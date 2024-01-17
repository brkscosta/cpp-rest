#pragma once

#include "IRequestWrapper.h"

#include <gmock/gmock.h>

namespace rest::service {

class MockRequest : public IRequestWrapper
{
public:
    MOCK_METHOD1(getPathParameters, std::map<std::string, std::string>(const std::string&));
};
}   // namespace rest::service