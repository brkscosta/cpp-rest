#pragma once

#include <set>
#include <string>

namespace rest::paths {
const std::set<std::string>& PROMPTS = { "/prompts/{id: .*}", "/prompts", "/prompts/add" };
}   // namespace rest::paths
