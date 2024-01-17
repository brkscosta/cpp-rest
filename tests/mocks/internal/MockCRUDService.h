#pragma once

#include "ICRUDService.h"

#include <gmock/gmock.h>

namespace rest::service {

template<typename T>
class MockCRUDService : public ICRUDService<T>
{
public:
    MOCK_METHOD2_T(post, void(const std::shared_ptr<restbed::Session>&, std::shared_ptr<T>&));
    MOCK_METHOD2_T(get, void(const std::shared_ptr<restbed::Session>&, const std::string&));
};

}   // namespace rest::service
