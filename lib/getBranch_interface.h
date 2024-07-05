#pragma once

#include "getBranch.h"
#include "nlohmann/json.hpp"

#define EXPORT_LIB extern "C"

using json = nlohmann::json;

struct BranchLib {
    Branch br_;
};
struct JsonLib {
    json json_;
};

EXPORT_LIB BranchLib* MakeBranchController();
EXPORT_LIB JsonLib* GetBranchJson(const BranchLib* br, std::string brId);
