#include "terminal.h"

using namespace std;

int main() {
    log("Hello\n", graphics::BOLD, colour::BLUE);
    set(RESET);
    return 0;
}