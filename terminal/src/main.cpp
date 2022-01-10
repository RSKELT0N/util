#include "terminal.h"

using namespace std;

int main() {
    action(set_cursor(10, 10));
    std::cout << "Hello world!\n";
    return 0;
}
