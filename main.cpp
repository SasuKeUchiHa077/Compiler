#include <cstdlib>
#include <iostream>

int main (int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error\n<./exec> <src_file>\n";
        exit(-1);
    }

    std::cout << "Reading from : " << argv[1] << "\n";
    return 0;
}
