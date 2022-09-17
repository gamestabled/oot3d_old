#include <ctype.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "n3dsdisasm.h"

struct ConfigLabel
{
    uint32_t addr;
    uint8_t type;
    const char *label;
};

uint8_t *gInputFileBuffer;
size_t gInputFileBufferSize;
bool gStandaloneFlag;

void fatal_error(const char *fmt, ...)
{
    va_list args;

    fputs("error: ", stderr);
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fputs("\n", stderr);
    exit(1);
}

static void read_input_file(const char *fname)
{
    FILE *file = fopen(fname, "rb");

    if (file == NULL)
        fatal_error("could not open input file '%s'", fname);
    fseek(file, 0, SEEK_END);
    gInputFileBufferSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    gInputFileBuffer = malloc(gInputFileBufferSize);
    if (gInputFileBuffer == NULL)
        fatal_error("failed to alloc file buffer for '%s'", fname);
    if (fread(gInputFileBuffer, 1, gInputFileBufferSize, file) != gInputFileBufferSize)
        fatal_error("failed to read from file '%s'", fname);
    fclose(file);
}

static char *split_word(char *s)
{
    while (!isspace(*s))
    {
        if (*s == '\0')
            return s;
        s++;
    }
    *s++ = '\0';
    while (isspace(*s))
        s++;
    return s;
}

static char *split_line(char *s)
{
    while (*s != '\n' && *s != '\r')
    {
        if (*s == '\0')
            return s;
        s++;
    }
    *s++ = '\0';
    while (*s == '\n' || *s == '\r')
        s++;
    return s;
}

static char *skip_whitespace(char *s)
{
    while (isspace(*s))
        s++;
    return s;
}

static char *dup_string(const char *s)
{
    char *new = malloc(strlen(s) + 1);

    if (new == NULL)
        fatal_error("could not alloc space for string '%s'", s);
    strcpy(new, s);
    return new;
}

#define NUM_CMD_TOKENS 4

static void read_config(const char *fname)
{
    FILE *file = fopen(fname, "rb");
    char *buffer;
    size_t size;
    char *line;
    char *next;
    int lineNum = 1;

    if (file == NULL)
        fatal_error("could not open config file '%s'", fname);
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    buffer = malloc(size + 1);
    if (buffer == NULL)
        fatal_error("could not alloc buffer for '%s'", fname);
    if (fread(buffer, 1, size, file) != size)
        fatal_error("failed to read from file '%s'", fname);
    buffer[size] = '\0';
    fclose(file);

    for (line = next = buffer; *line != '\0'; line = next, lineNum++)
    {
        char *tokens[NUM_CMD_TOKENS];
        char *name = NULL;
        int i;

        next = split_line(line);

        tokens[0] = line = skip_whitespace(line);
        for (i = 1; i < NUM_CMD_TOKENS; i++)
            tokens[i] = line = split_word(line);

        if (tokens[0][0] == '#')
            continue;
        if (strcmp(tokens[0], "arm_func") == 0)
        {
            int addr;
            int idx;

            if (sscanf(tokens[1], "%i", &addr) == 1)
            {
                if (strlen(tokens[2]) != 0)
                    name = dup_string(tokens[2]);
                idx = disasm_add_label(addr, LABEL_ARM_CODE, name);
                if (strlen(tokens[3]) != 0)
                    disasm_force_func(idx);
            }
            else
            {
                fatal_error("%s: syntax error on line %i\n", fname, lineNum);
            }
        }
        else if (strcmp(tokens[0], "thumb_func") == 0)
        {
            int addr;
            int idx;

            if (sscanf(tokens[1], "%i", &addr) == 1)
            {
                if (strlen(tokens[2]) != 0)
                    name = dup_string(tokens[2]);
                idx = disasm_add_label(addr, LABEL_THUMB_CODE, name);
                if (strlen(tokens[3]) != 0)
                    disasm_force_func(idx);
            }
            else
            {
                fatal_error("%s: syntax error on line %i\n", fname, lineNum);
            }
        }
        else if (strcmp(tokens[0], "thumb_label") == 0)
        {
            int addr;

            if (sscanf(tokens[1], "%i", &addr) == 1)
            {
                if (strlen(tokens[2]) != 0)
                    name = dup_string(tokens[2]);
                disasm_add_label(addr, LABEL_THUMB_CODE, name);
                disasm_set_branch_type(addr, BRANCH_TYPE_B, false);
            }
            else
            {
                fatal_error("%s: syntax error on line %i\n", fname, lineNum);
            }
        }
        else if (strcmp(tokens[0], "arm_label") == 0)
        {
            int addr;

            if (sscanf(tokens[1], "%i", &addr) == 1)
            {
                if (strlen(tokens[2]) != 0)
                    name = dup_string(tokens[2]);
                disasm_add_label(addr, LABEL_ARM_CODE, name);
                disasm_set_branch_type(addr, BRANCH_TYPE_B, false);
            }
            else
            {
                fatal_error("%s: syntax error on line %i\n", fname, lineNum);
            }
        }
        else if (strcmp(tokens[0], "thumb_far_jump") == 0)
        {
            int addr;

            if (sscanf(tokens[1], "%i", &addr) == 1)
            {
                if (strlen(tokens[2]) != 0)
                    name = dup_string(tokens[2]);
                disasm_add_label(addr, LABEL_THUMB_CODE, name);
                disasm_set_branch_type(addr, BRANCH_TYPE_B, true);
            }
            else
            {
                fatal_error("%s: syntax error on line %i\n", fname, lineNum);
            }
        }
        else if (strcmp(tokens[0], "arm_far_jump") == 0)
        {
            int addr;

            if (sscanf(tokens[1], "%i", &addr) == 1)
            {
                if (strlen(tokens[2]) != 0)
                    name = dup_string(tokens[2]);
                disasm_add_label(addr, LABEL_ARM_CODE, name);
                disasm_set_branch_type(addr, BRANCH_TYPE_B, true);
            }
            else
            {
                fatal_error("%s: syntax error on line %i\n", fname, lineNum);
            }
        }
        else if (strcmp(tokens[0], "pool_label") == 0)
        {
            int addr, count, i;

            if (sscanf(tokens[1], "%i", &addr) == 1
                && sscanf(tokens[2], "%i", &count) == 1)
            {
                for (i = 0; i < count; ++i)
                    disasm_add_label(addr + 4*i, LABEL_POOL, NULL);
            }
            else
            {
                fatal_error("%s: syntax error on line %i\n", fname, lineNum);
            }
        }
        else if (strcmp(tokens[0], "jump_table") == 0)
        {
            int addr, count;

            if (sscanf(tokens[1], "%i", &addr) == 1
                && sscanf(tokens[2], "%i", &count) == 1)
            {
                disasm_add_label(addr, LABEL_JUMP_TABLE, NULL);
                if (jump_table_create_labels(addr, count))
                    fatal_error("%s: invalid params on line %i\n", fname, lineNum);
            }
            else
            {
                fatal_error("%s: syntax error on line %i\n", fname, lineNum);
            }
        }
        else if (strcmp(tokens[0], "data_label") == 0)
        {
            int addr;

            if (sscanf(tokens[1], "%i", &addr) == 1)
            {
                disasm_add_label(addr, LABEL_DATA, NULL);
            }
            else
            {
                fatal_error("%s: syntax error on line %i\n", fname, lineNum);
            }
        }
        else
        {
            fprintf(stderr, "%s: warning: unrecognized command '%s' on line %i\n", fname, tokens[0], lineNum);
        }
    }

    free(buffer);
}

int main(int argc, char **argv)
{
    int i;
    const char *romFileName = NULL;
    const char *configFileName = NULL;
    ROM_LOAD_ADDR = 0x100000;

#ifdef _WIN32
    // Work around MinGW bug that prevents us from seeing the assert message
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
#endif

    for (i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-c") == 0)
        {
            if (i + 1 >= argc)
                fatal_error("expected filename for option -c");
            i++;
            configFileName = argv[i];
        }
        else if (strcmp(argv[i], "-l") == 0)
        {
            char * end;
            if (i + 1 >= argc)
                fatal_error("expected integer for option -l");
            i++;
            ROM_LOAD_ADDR = strtoul(argv[i], &end, 0);
            if (*end != 0)
                fatal_error("invalid integer value for option -l");
        }
        else if (strcmp(argv[i], "-s") == 0)
        {
            gStandaloneFlag = true;
        }
        else
        {
            romFileName = argv[i];
        }
    }

    if (romFileName == NULL)
        fatal_error("no code.bin file specified");
    read_input_file(romFileName);
    if (configFileName != NULL)
        read_config(configFileName);
    disasm_disassemble();
    free(gInputFileBuffer);
    return 0;
}
