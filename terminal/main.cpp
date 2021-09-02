#include "terminal.h"

using namespace std;

int main() {
    log("Hello!", UNDER_LINE, colour::BLUE);
    action(RESET);

    std::cout << PREFIX << UNDER_LINE << colour::BLUE << SUFFIX << "Hello" << "\n";
return 0;
}