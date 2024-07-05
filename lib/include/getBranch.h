#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <unordered_set>
#include <string>
#include <stdexcept>

using json = nlohmann::json;

static const std::string url = "https://rdb.altlinux.org/api/export/branch_binary_packages/";
static const std::unordered_set<std::string> branchs = {
    "sisyphus", "p9", "p10", "p11"
};

namespace Branch
{
    json getBranch(std::string branch);
    bool checkBranch(std::string branch);
};
