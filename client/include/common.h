#pragma once

#include <string>
#include <nlohmann/json.hpp>

struct Package
{
    std::string name;
    uint64_t epoch;
    std::string version;
    std::string release;
    std::string arch;
    std::string disttag;
    uint64_t buildtime;
    std::string source;

    bool operator==(const Package &other) const {
        return name == other.name && source == other.source && arch == other.arch;
    }

    bool operator!=(const Package &other) const {
        return !(*this == other);
    }

    bool operator>(const Package &other) const {
        return name > other.name ||
               name == other.name && source > other.source ||
               source == other.source &&  arch > other.arch;
    }

    bool operator>=(const Package &other) const {
        return *this > other || *this == other;
    }

    bool operator<(const Package &other) const {
        return !(*this >= other);
    }

    bool operator<=(const Package &other) const {
        return !(*this > other);
    }
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Package, name, epoch, version, release, arch, disttag, buildtime, source);

bool checkVersion(const std::string& v1, const std::string& v2);

