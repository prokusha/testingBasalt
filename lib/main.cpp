#include <iostream>
#include <curl/curl.h>
#include "getBranch_interface.h"

int main(int argc, const char** argv)
{
    if (argc != 3) {
        std::cerr << "Expected 2 arguments: branch first, branch second";
        return -1;
    }
    BranchLib* br = MakeBranchController();
    JsonLib* jj = GetBranchJson(br, argv[1]);
    std::cout << jj->json_ << std::endl;
}
