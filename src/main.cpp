// // #include "global.hpp"

// extern int cont;
// extern void Graph_ThreadEntry(int);
// extern int first;
// extern int second;
// extern void Finalize(int*);
// extern void SetDeviceMemorySize(int);
// extern void SetHeapSize(int);
// extern void PrepareToCloseApplication(bool);
// extern void CloseApplication(bool, int, int);

// class MainClass {
// public:
//     MainClass();

//     static MainClass* getInstance() {
//         static MainClass instance;
//         return &instance;
//     }

//     int FUN_00416608();
// private:
//     char data[0x100];
// };

// extern "C" void nnMain() {
//     MainClass* mainClass = MainClass::getInstance();

//     if (mainClass->FUN_00416608()) {
//         while (cont == 0) {
//             Graph_ThreadEntry(0);
//         }
//     }

//     Finalize(&first);
//     Finalize(&second);
//     SetDeviceMemorySize(0);
//     SetHeapSize(0);
//     PrepareToCloseApplication(false);
//     CloseApplication(false, 0, 0);
// }
