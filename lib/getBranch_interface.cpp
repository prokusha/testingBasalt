#include <cassert>
#include "getBranch_interface.h"

BranchLib* MakeBranchController() {
    return new BranchLib;
}

JsonLib* GetBranchJson(const BranchLib* br, std::string brId) {
    assert(br);
    return new JsonLib{br->br_.getBranch(brId)};
}
