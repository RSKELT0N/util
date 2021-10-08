#include "terminal.h"
#include <chrono>
#include <windows.h>

using namespace std;

constexpr int MAX = 100;

void print_loading_bar(const int& precent, const int& line) {
    set_cursor(line,0);
    printf("%c", '[');

    set(colour::GREEN);
    for(int i = 0; i < precent; i++)
        printf("%c", '#');
    action(RESET);
    
    uint32_t remaining = MAX - precent;

    set(colour::WHITE);
    for(int i = 0; i < remaining; i++)
        printf("%c", '~');
    action(RESET);

    printf("%c", ']');

    double val = (double)precent/(double)MAX * (double)100;
    std::cout << " % " << val;
    set_cursor(line, 0);
}

void print_package(const int& line) {
    set_cursor(line+1, 0);
    std::cout << "Package installed..";
    set_cursor(line+2, 0);
}

int main() {
    action(control::CLEAR_ENTIRE);
    set_cursor(1, 0);
    for(int i = 1, line = 100; i <= MAX; i++) {
        print_loading_bar(i, MAX);
        Sleep(50);
        print_package(i);
        action(control::CLEAR_LINE);
    }
    std::cout << "\n";
    std::cout << "Download complete\n";

    return 0;
}