#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

int main (int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error\n<./exec> <src_file>\n";
        exit(-1);
    }

    std::ifstream readSourceFile(argv[1]);

    if (!readSourceFile.is_open()) {
        std::cerr << argv[1] << " not found!\n";
        exit(-1);
    }

    std::cout << "=====[START]=====\n\n";

    std::cout << "Reading from : " << argv[1] << "\n\n";

    std::stringstream buffer;
    char temp;

    while (readSourceFile.get(temp)) {
        buffer << temp;
    }

    readSourceFile.close();

    std::cout << buffer.str() << '\n';

    std::cout << "\n======[END]======\n";

    return 0;
}
