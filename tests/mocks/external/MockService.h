#include <chrono>
#include <functional>
#include <gmock/gmock.h>
#include <memory>
#include <restbed>

namespace restbed {
class MockService : public restbed::Service
{
  public:
    MOCK_CONST_METHOD0(is_up, bool());
    MOCK_CONST_METHOD0(is_down, bool());
    MOCK_METHOD0(stop, void());
    MOCK_METHOD1(start, void(const std::shared_ptr<const restbed::Settings>&));
    MOCK_METHOD1(restart, void(const std::shared_ptr<const restbed::Settings>&));
    MOCK_METHOD1(add_rule, void(const std::shared_ptr<restbed::Rule>&));
    MOCK_METHOD2(add_rule, void(const std::shared_ptr<restbed::Rule>&, int));
    MOCK_METHOD1(publish, void(const std::shared_ptr<const restbed::Resource>&));
    MOCK_METHOD1(suppress, void(const std::shared_ptr<const restbed::Resource>&));
    MOCK_METHOD2(schedule, void(const std::function<void()>&, const std::chrono::milliseconds&));
    MOCK_CONST_METHOD0(get_uptime, const std::chrono::seconds());
    MOCK_CONST_METHOD0(get_http_uri, const std::shared_ptr<const restbed::Uri>());
    MOCK_CONST_METHOD0(get_https_uri, const std::shared_ptr<const restbed::Uri>());
    MOCK_METHOD1(set_logger, void(const std::shared_ptr<restbed::Logger>&));
    MOCK_METHOD1(set_session_manager, void(const std::shared_ptr<restbed::SessionManager>&));
    MOCK_METHOD1(set_ready_handler, void(const std::function<void(Service&)>&));
    MOCK_METHOD2(set_signal_handler, void(int, const std::function<void(int)>&));
    MOCK_METHOD1(set_not_found_handler, void(const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD1(set_method_not_allowed_handler, void(const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD1(set_method_not_implemented_handler, void(const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD1(set_failed_filter_validation_handler, void(const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD1(set_error_handler, void((const std::function<void(const int, const std::exception&, const std::shared_ptr<restbed::Session>)>&)));
    MOCK_METHOD1(set_authentication_handler, void(const std::function<void(const std::shared_ptr<restbed::Session>, const std::function<void(const std::shared_ptr<restbed::Session>)>&)>&));
};
}

