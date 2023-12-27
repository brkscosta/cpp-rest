#include <gmock/gmock.h>
#include <restbed>

namespace restbed
{
class MockResource : public Resource
{
  public:
    MockResource() {};

    MOCK_METHOD1(add_rule, void(const std::shared_ptr<restbed::Rule>&));
    MOCK_METHOD2(add_rule, void(const std::shared_ptr<restbed::Rule>&, const int));
    MOCK_METHOD1(set_path, void(const std::string&));
    MOCK_METHOD1(set_paths, void(const std::set<std::string>&));
    MOCK_METHOD2(set_default_header, void(const std::string&, const std::string&));
    MOCK_METHOD1(set_default_headers, void(const std::multimap<std::string, std::string>&));
    MOCK_METHOD1(set_failed_filter_validation_handler,
        void(const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD1(set_error_handler,
        void(const std::function<void(const int, const std::exception&, const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD1(
        set_authentication_handler, void(const std::function<void(const std::shared_ptr<restbed::Session>,
                                            const std::function<void(const std::shared_ptr<restbed::Session>)>&)>&));
    MOCK_METHOD2(set_method_handler, void(const std::string&, const std::function<void(const std::shared_ptr<restbed::Session>)>&));
    MOCK_METHOD3(set_method_handler, void(const std::string&, const std::multimap<std::string, std::string>&, const std::function<void(const std::shared_ptr<restbed::Session>)>&));
};

}  // namespace restbed
