#include "../include/common.h"

std::vector<int> parse_version(const std::string& version)
{
    std::vector<int> parts;
    std::string part;
    for (char c : version) {
        if (c == '.') {
            parts.push_back(std::stoi(part));
            part.clear();
        } else {
            part += c;
        }
    }
    parts.push_back(std::stoi(part));
    return parts;
}

bool checkVersion(const std::string& v1, const std::string& v2)
{
    std::vector<int> parts1 = parse_version(v1);
    std::vector<int> parts2 = parse_version(v2);

    for (size_t i = 0; i < std::max(parts1.size(), parts2.size()); i++) {
        int part1 = (i < parts1.size()) ? parts1[i] : 0;
        int part2 = (i < parts2.size()) ? parts2[i] : 0;
        if (part1 > part2) {
            return true;
        }
    }

    return false;
}
