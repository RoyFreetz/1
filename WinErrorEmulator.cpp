#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Function prototypes
void simulateBSOD();
void fakeSystemCrash();
void glitchEffect();
void corruptedFileSim();
void centerText(const string& text);
void fakeLoadingScreen();
void matrixEffect();
void virusWarning();
void drawErrorBox(int x, int y, int width, int height);

// Utility function for centered text
void centerText(const string& text) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    cout << string((width - text.length()) / 2, ' ') << text << endl;
}

// Simulate BSOD
void simulateBSOD() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    
    // Set blue background
    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
    system("cls");
    
    centerText(":(");
    centerText("Your PC ran into a problem and needs to restart.");
    centerText("We're just collecting some error info, and then we'll restart for you.");
    centerText("20% complete");
    centerText("Stop code: CRITICAL_OBJECT_HUMOR");
    
    // Flash effect
    for(int i = 0; i < 3; i++) {
        SetConsoleTextAttribute(hConsole, BACKGROUND_WHITE);
        system("cls");
        Sleep(50);
        SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
        system("cls");
        Sleep(50);
    }
    
    SetConsoleTextAttribute(hConsole, 7); // Reset colors
    system("cls");
}

// Fake loading screen with potential failure
void fakeLoadingScreen() {
    system("cls");
    centerText("System Recovery Initializing...");
    
    for(int i = 0; i <= 100; i++) {
        cout << "\r[";
        for(int j = 0; j < 50; j++) {
            cout << (j < i/2 ? "#" : " ");
        }
        cout << "] " << i << "%";
        Sleep(rand() % 50);
        
        if(i == 73) { // Simulate freeze
            system("cls");
            centerText("Unexpected error occurred during recovery");
            centerText("Press any key to continue...");
            getch();
            return;
        }
    }
}

// Fake virus detection
void virusWarning() {
    system("cls");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(hConsole, 12); // Red text
    centerText("!!! CRITICAL WARNING !!!");
    centerText("Multiple threats detected");
    
    vector<string> fakeFiles = {
        "C:\\Windows\\System32\\humor.dll - TROJAN_HAPPY",
        "C:\\Users\\Player\\Documents\\joke.txt - ADWARE_SILLY",
        "C:\\Program Files\\Game\\laughter.exe - RANSOMFUN"
    };
    
    SetConsoleTextAttribute(hConsole, 15); // White text
    for(const auto& file : fakeFiles) {
        centerText(file);
    }
    
    SetConsoleTextAttribute(hConsole, 12);
    centerText("Recommend action: Immediate quarantine");
    centerText("Press Q to quarantine threats");
    
    while(true) {
        if(toupper(getch()) == 'Q') {
            system("cls");
            centerText("Quarantining threats...");
            Sleep(2000);
            centerText("Successfully contained humor!");
            centerText("System stability compromised: 100%");
            Sleep(3000);
            break;
        }
    }
    SetConsoleTextAttribute(hConsole, 7);
}

// Main menu
int main() {
    srand(time(0));
    int choice;
    
    while(true) {
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        centerText("Windows Error Simulator 2024");
        cout << endl;
        
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        centerText("1. Simulate BSOD");
        centerText("2. Fake System Recovery");
        centerText("3. Trigger Virus Warning");
        centerText("4. Exit");
        centerText("Enter choice: ");
        
        COORD pos;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        pos = csbi.dwCursorPosition;
        cin >> choice;

        switch(choice) {
            case 1:
                simulateBSOD();
                break;
            case 2:
                fakeLoadingScreen();
                break;
            case 3:
                virusWarning();
                break;
            case 4:
                return 0;
            default:
                centerText("Invalid selection - Error 0xHUMOR");
                Sleep(1000);
        }
    }
}
