#pragma once

#include "ISessionWrapper.h"

#include <gmock/gmock.h>

namespace rest::service {

class MockSession : public ISessionWrapper
{
public:
    MOCK_METHOD0(getRequest, std::shared_ptr<IRequestWrapper>());
    MOCK_METHOD0(getCurrentSession, std::shared_ptr<restbed::Session>());
};
}   // namespace rest::service