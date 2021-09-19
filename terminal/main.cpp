#include "terminal.h"
#include <windows.h>

using namespace std;

int main() {
    printf("Result: ");
    action(control::CURSOR_INVISIBLE);
    
    action(control::CURSOR_SAVE_SCO);
    
    for(int i = 0; i < 100; i++) {
        log("", colour::RED);
        printf("%d%%", i);
        action(control::CURSOR_RESTORE_SCO);
        Sleep(1000);
    }
    printf("\n");

    return 0;
}