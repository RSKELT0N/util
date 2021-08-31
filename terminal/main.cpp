#include "terminal.h"

using namespace std;

int main() {
    log("Hello", BOLD, STRIKE_THROUGH, ITALIC, UNDER_LINE, RED);
    action(RESET);
    return 0;
}