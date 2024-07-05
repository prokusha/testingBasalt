#include <iostream>
#include <curl/curl.h>
#include "getBranch.h"

int main(int argc, const char** argv)
{
    if (argc != 3) {
        std::cerr << "Expected 2 arguments: branch first, branch second";
        return -1;
    }
    Branch br;
    json jj = br.getBranch(argv[1]);
    std::cout << jj << std::endl;
}
