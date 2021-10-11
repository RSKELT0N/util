#include "terminal.h"

using namespace std;

int main() {
    log("Hello world!\n", graphics::BOLD, colour::BLUE);
    action(RESET);
    return 0;
}
