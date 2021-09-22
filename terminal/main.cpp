#include "terminal.h"

using namespace std;

int main() {
    std::ostringstream out;
    std::streambuf* def = std::cout.rdbuf();

    out << PREFIX << control::CURSOR_REQST;
    std::cout << "hello\n";
    std::cout.rdbuf(out.rdbuf());
    std::cout.rdbuf(def);
    std::cout << "hello\n";
    std::string rs = out.str().c_str();

    for(int i = 0; i < rs.size(); i++) {
        std::cout << rs[i] << "-";
    }
    return 0;
}