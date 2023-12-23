#pragma once

#include <set>
#include <string>

namespace rest::paths
{
const std::set<std::string>& PROMPTS = {
    "/prompts",
    "/prompts/add",
    "/prompts/listAll"
};
}  // namespace rest::paths
