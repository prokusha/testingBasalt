#include "../include/common.h"

std::vector<int> parseVersion(const std::string& version)
{
    std::vector<int> parts;
    std::string part;
    for (char c : version) {
        if (c == '.' && !part.empty()) {
            parts.push_back(std::stoi(part));
            part.clear();
        } else if (c >= '0' && c <= '9') {
            part += c;
        }
    }
    return parts;
}

bool checkVersion(const std::string& v1, const std::string& v2)
{
    std::vector<int> parts1 = parseVersion(v1);
    std::vector<int> parts2 = parseVersion(v2);

    for (size_t i = 0; i < std::max(parts1.size(), parts2.size()); i++) {
        int part1 = (i < parts1.size()) ? parts1[i] : 0;
        int part2 = (i < parts2.size()) ? parts2[i] : 0;
        if (part1 > part2) {
            return true;
        }
    }

    return false;
}
