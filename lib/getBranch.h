#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <unordered_set>
#include <string>

using json = nlohmann::json;

static const std::string url = "https://rdb.altlinux.org/api/export/branch_binary_packages/";

class Branch
{

public:
    Branch() {}
    json getBranch(std::string branch) const;
};
