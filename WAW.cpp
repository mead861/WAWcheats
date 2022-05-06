#include <iostream>
#include <windows.h>
#include <conio.h>
#define money_address 0x0
using namespace std;

void StartCheats () {
    int playerMoney = 76670;
    int playerHealth = 100000;
    int playerPammo = 7;
    int crosshair = 0;
    int sgammo = 6;
    int cbammo = 15;
    int dammo = 2;
    int tammo = 20;
    int g43ammo;
    int st44ammo = 15;
    int barammo = 15;
    int ppshammo = 30;

    HWND hwnd = FindWindowA(NULL, "Call of Duty\xAE"); // specifies the window to act upon
        // error message if the window isn't found
        if (hwnd == NULL) {
            cout << "window not found!\n";
            system("PAUSE");
        }
        else {
            DWORD processID;
            // stores the process id of the window
            GetWindowThreadProcessId(hwnd, &processID);
            // gets the process id of the window
            HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
            // opens the process with full access
            if (!handle) {
                cout << "couldnt initiate a handle on the process!\n";
                system("PAUSE");
            }

            // error message if the process ID isn't found
            if (processID == NULL) {
                cout << "cannot find process!\n";
                system("PAUSE");
            }
            else {

                //code here
                bool f = true;
                while (f)
                {
                    if (GetAsyncKeyState(VK_ESCAPE)) {
                        //Enter code for when a button is pushed here
                        f = false;
                    }
                    else {
                       // WriteProcessMemory(handle, (LPVOID)money_address, PlayerMoney, sizeof(Money), NULL);
                        //std::cout << "Cheats enabled press 0 to exit";
                        WriteProcessMemory(handle, (LPVOID)0X18EF124, &playerMoney, 4, 0); // this writes the new value to the listed address
                        WriteProcessMemory(handle, (LPVOID)0x176C8B8, &playerHealth, 4, 0); // this writes the new value to the listed address
                        WriteProcessMemory(handle, (LPVOID)0x18ED67c, &playerPammo, 4, 0); // this writes the new value to the listed address 14ED680
                        WriteProcessMemory(handle, (LPVOID)0X18ed6c0, &sgammo, 4, 0); // this writes the new value to the listed address
                        WriteProcessMemory(handle, (LPVOID)0X18ed698, &cbammo, 4, 0); // this writes the new value to the listed address
                        WriteProcessMemory(handle, (LPVOID)0X18Ed6b4, &dammo, 4, 0); // this writes the new value to the listed address
                        WriteProcessMemory(handle, (LPVOID)0X18ED6B0, &tammo, 4, 0); // this writes the new value to the listed address
                        WriteProcessMemory(handle, (LPVOID)0X18ED694, &g43ammo, 4, 0); // this writes the new value to the listed address
                        WriteProcessMemory(handle, (LPVOID)0X18ED6AC, &st44ammo, 4, 0); // this writes the new value to the listed address
                        WriteProcessMemory(handle, (LPVOID)0X18ED6C8, &barammo, 4, 0); // this writes the new value to the listed address
                        WriteProcessMemory(handle, (LPVOID)0X18ED6AC, &ppshammo, 4, 0); // this writes the new value to the listed address
                        ReadProcessMemory(handle, (LPVOID)0x18ED078, &crosshair, 4, 0);
                        std::cout << "No Target:\n";
                        Sleep(2);
                        //Code to run until the button is pushed
                        if (crosshair == 16) {
                            cout << "Found Target\n";
                            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                        }
                       

                    }
                }

            }

        }
        }
    //return 0;



int main()
{
    int choice;
    do
    {
        std::cout << "0. Quit" << std::endl << "1. Enable Cheats";
        std::cin >> choice;


        switch (choice)
        {
        case 0:
            break;
        case 1:
            StartCheats();

        }
    } while (choice != 0);
}