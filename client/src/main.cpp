#include <getBranch.h>
#include "../include/common.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <set>

// "name", "epoch", "version", "release", "arch", "disttag", "buildtime", "source"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: branchUtility <branch 1> <branch 2> \nValid branch set names: ['sisyphus', 'p9', 'p10', 'p11']";
        return -1;
    }
    std::string br1 = argv[1];
    std::string br2 = argv[2];
    if (!(Branch::checkBranch(br1) && Branch::checkBranch(br2)) || br1 == br2)
    {
        std::cerr << "Valid branch set names: ['sisyphus', 'p9', 'p10', 'p11']";
        return -1;
    }
    try
    {
        std::set<Package> f = Branch::getBranch(br1)["packages"].get<std::set<Package>>();
        std::set<Package> s = Branch::getBranch(br2)["packages"].get<std::set<Package>>();

        std::set<Package> left, right, highVersionInLeft;
        std::set_difference(f.begin(), f.end(), s.begin(), s.end(), std::inserter(left, left.end()));
        std::set_difference(s.begin(), s.end(), f.begin(), f.end(), std::inserter(right, right.end()));

        std::set<Package> temp1, temp2;
        std::set_intersection(f.begin(), f.end(), s.begin(), s.end(), std::inserter(temp1, temp1.end()));
        std::set_intersection(s.begin(), s.end(), f.begin(), f.end(), std::inserter(temp2, temp2.end()));

        for (const auto& pak1 : temp1)
        {
            auto pak2 = temp2.find(pak1);
            if (pak2 != temp2.end() && checkVersion(pak1.version, pak2->version))
            {
                highVersionInLeft.insert(pak1);
            }
        }

        json result = {{"high version left", highVersionInLeft}};
        std::cout << result.dump(4);

    } catch (const std::invalid_argument& e)
    {
        std::cerr << e.what();
        return -1;
    }
}
