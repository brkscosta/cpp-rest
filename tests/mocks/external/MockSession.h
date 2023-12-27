#pragma once
#include <gmock/gmock.h>
#include <memory>
#include <restbed>
#include <string>

namespace restbed
{

class MockSession : public Session
{
  public:
    MockSession() : Session("") {}
    MOCK_CONST_METHOD1(has, bool(const std::string&));
    MOCK_METHOD1(erase, void(const std::string&));
    MOCK_CONST_METHOD0(keys, std::set<std::string>());
    MOCK_CONST_METHOD0(is_open, bool());
    MOCK_CONST_METHOD0(is_closed, bool());
    MOCK_METHOD1(close, void(const restbed::Bytes&));
    MOCK_METHOD1(close, void(const restbed::Response&));
    MOCK_METHOD1(close, void(const std::string&));
    MOCK_METHOD2(close, void(const int, const restbed::Bytes&));
    MOCK_METHOD2(close, void(const int, const std::string&));
    MOCK_METHOD2(close, void(const int, const std::multimap<std::string, std::string>&));
    MOCK_METHOD3(close, void(const int, const std::string&, const std::multimap<std::string, std::string>&));
    MOCK_METHOD2(yield, void(const restbed::Bytes&, const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD2(yield, void(const std::string&, const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD2(yield, void(const restbed::Response&, const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD3(yield, void(const int, const std::string&, const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD3(yield, void(const int, const restbed::Bytes&, const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD3(yield, void(const int, const std::multimap<std::string, std::string>&, const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD4(yield, void(const int, const restbed::Bytes&, const std::multimap<std::string, std::string>&, const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD4(yield, void(const int, const std::string&, const std::multimap<std::string, std::string>&, const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD2(fetch, void(const std::size_t, const std::function<void(const std::shared_ptr<restbed::Session>, const restbed::Bytes&)>&));
    MOCK_METHOD2(fetch, void(const std::string&, const std::function<void(const std::shared_ptr<restbed::Session>, const restbed::Bytes&)>&));
    MOCK_METHOD2(upgrade, void(const int, const std::function<void(const std::shared_ptr<restbed::WebSocket>)>&));
    MOCK_METHOD3(upgrade, void(const int, const restbed::Bytes&, const std::function<void(const std::shared_ptr<restbed::WebSocket>)>&));
    MOCK_METHOD3(upgrade, void(const int, const std::string&, const std::function<void(const std::shared_ptr<restbed::WebSocket>)>&));
    MOCK_METHOD3(upgrade, void(const int, const std::multimap<std::string, std::string>&, const std::function<void(const std::shared_ptr<restbed::WebSocket>)>&));
    MOCK_METHOD4(upgrade, void(const int, const restbed::Bytes&, const std::multimap<std::string, std::string>&, const std::function<void(const std::shared_ptr<restbed::WebSocket>)>&));
    MOCK_METHOD4(upgrade, void(const int, const std::string&, const std::multimap<std::string, std::string>&, const std::function<void(const std::shared_ptr<restbed::WebSocket>)>&));
    MOCK_METHOD2(sleep_for, void(const std::chrono::milliseconds&, const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_CONST_METHOD0(get_id, const std::string&());
    MOCK_CONST_METHOD0(get_origin, const std::string());
    MOCK_CONST_METHOD0(get_destination, const std::string());
    MOCK_CONST_METHOD0(get_request, const std::shared_ptr<const restbed::Request>());
    MOCK_CONST_METHOD0(get_resource, const std::shared_ptr<const restbed::Resource>());
    MOCK_CONST_METHOD0(get_headers, const std::multimap<std::string, std::string>&());
    MOCK_CONST_METHOD1(get, const restbed::ContextValue&(const std::string&));
    MOCK_CONST_METHOD2(get, const restbed::ContextValue&(const std::string&, const restbed::ContextValue&));
    MOCK_METHOD1(set_id, void(const std::string&));
    MOCK_METHOD2(set, void(const std::string&, const ContextValue&));
    MOCK_METHOD2(add_header, void(const std::string&, const std::string&));
    MOCK_METHOD2(set_header, void(const std::string&, const std::string&));
    MOCK_METHOD1(set_headers, void(const std::multimap<std::string, std::string>&));
};
}  // namespace restbed