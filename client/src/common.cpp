#include "../include/common.h"
#include <rpm/rpmver.h>

bool checkVersion(const std::string& v1, const std::string& v2)
{
    return rpmvercmp(v1.c_str(), v2.c_str()) > 0;
}
