#include <gmock/gmock.h>
#include <restbed>

namespace restbed
{

class MockRequest : public Request
{
  public:
    MOCK_CONST_METHOD1(has_header, bool(const std::string&));
    MOCK_CONST_METHOD1(has_path_parameter, bool(const std::string&));
    MOCK_CONST_METHOD1(has_query_parameter, bool(const std::string&));

    MOCK_CONST_METHOD0(get_port, uint16_t());
    MOCK_CONST_METHOD0(get_version, double());
    MOCK_CONST_METHOD0(get_body, const restbed::Bytes&());
    MOCK_CONST_METHOD0(get_response, const std::shared_ptr<const restbed::Response>());

    MOCK_CONST_METHOD1(get_host, std::string(const std::function<std::string(const std::string&)>&));
    MOCK_CONST_METHOD1(get_path, std::string(const std::function<std::string(const std::string&)>&));
    MOCK_CONST_METHOD1(get_method, std::string(const std::function<std::string(const std::string&)>&));
    MOCK_CONST_METHOD1(get_protocol, std::string(const std::function<std::string(const std::string&)>&));
    MOCK_CONST_METHOD2(get_header, std::string(const std::string&, const std::string&));
    MOCK_CONST_METHOD2(get_header, std::string(const std::string&, const std::function<std::string(const std::string&)>&));
    MOCK_CONST_METHOD1(get_headers, std::multimap<std::string, std::string>(const std::string&));
    MOCK_CONST_METHOD2(get_query_parameter, std::string(const std::string&, const std::string&));
    MOCK_CONST_METHOD1(get_query_parameters, std::multimap<std::string, std::string>(const std::string&));
    MOCK_CONST_METHOD2(get_path_parameter, std::string(const std::string&, const std::string&));
    MOCK_CONST_METHOD1(get_path_parameters, std::map<std::string, std::string>(const std::string&));

    MOCK_METHOD1(set_body, void(const restbed::Bytes&));
    MOCK_METHOD1(set_body, void(const std::string&));
    MOCK_METHOD1(set_port, void(const uint16_t));
    MOCK_METHOD1(set_version, void(const double));
    MOCK_METHOD1(set_path, void(const std::string&));
    MOCK_METHOD1(set_host, void(const std::string&));
    MOCK_METHOD1(set_method, void(const std::string&));
    MOCK_METHOD1(set_protocol, void(const std::string&));
    MOCK_METHOD2(add_header, void(const std::string&, const std::string&));
    MOCK_METHOD2(set_header, void(const std::string&, const std::string&));
    MOCK_METHOD1(set_headers, void(const std::multimap<std::string, std::string>&));
    MOCK_METHOD2(set_query_parameter, void(const std::string&, const std::string&));
    MOCK_METHOD1(set_query_parameters, void(const std::multimap<std::string, std::string>&));
};
}  // namespace restbed