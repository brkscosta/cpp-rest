#include <algorithm>
#include <corvusoft/restbed/logger.hpp>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <ratio>
#include <restbed>

using namespace std;
using namespace restbed;

void post_method_handler(const shared_ptr<Session> session)
{
    const auto request = session->get_request();

    int content_length = request->get_header("Content-Length", 0);

    session->fetch(content_length,
        [](const shared_ptr<Session>& session, const Bytes& body)
        {
            fprintf(stdout, "%.*s\n", (int)body.size(), body.data());
            session->close(BAD_REQUEST, "Hello, World!", {{"Content-Length", "13"}});
        });
}

void get_method_handler(const shared_ptr<Session> session)
{
    const auto request = session->get_request();
    const auto headers = session->get_headers();

    for (auto it = headers.begin(), itEnd = headers.end(); it != itEnd;)
    {
        std::cout << "it->first: " << it->first << "it->second: " << it->second << std::endl;
    }
}

int main(const int, const char**)
{
    const uint16_t port = 8080;
    auto resource = make_shared<Resource>();
    auto resourceGet = make_shared<Resource>();

    resource->set_path("/resource");
    resource->set_method_handler("POST", post_method_handler);

    resourceGet->set_path("/test");
    resourceGet->set_method_handler("GET", get_method_handler);

    auto settings = make_shared<Settings>();
    settings->set_port(port);
    settings->set_default_header("Connection", "close");

    Service service;
    service.publish(resource);
    service.publish(resourceGet);

    std::cout << "Server stated on port: " << port << std::endl;

    service.start(settings);

    return EXIT_SUCCESS;
}