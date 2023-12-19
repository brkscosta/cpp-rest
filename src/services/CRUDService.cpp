#include "CRUDService.h"
#include "Prompt.h"
#include <memory>
#include <string>
#include <vector>

using namespace rest::service;
using namespace nlohmann;

namespace
{
const std::string HEADER_CONTENT_LENGTH = "Content-Length";
};

template <typename T>
CRUDService<T>::CRUDService(const std::shared_ptr<restbed::Service>& listener)
    : m_listener(listener)
{
    m_listener->set_error_handler([](const int, const std::exception& error, const std::shared_ptr<restbed::Session>& session)
    {
        std::cout << "Error on precessing request: " << error.what() << std::endl;
        session->close(restbed::BAD_REQUEST);
    });

    m_listener->set_not_found_handler([this](const std::shared_ptr<restbed::Session>& session)
    {
        const auto request = session->get_request();
        const std::string method = request->get_method();
        const std::string path = request->get_path();
        std::shared_ptr<T> item;

        if (method == "GET" && path.substr(0, 6) == "/data/")
        {
            get(session, path);
        }
        else if (method == "POST" && path == "/data")
        {
            post(session, item);
        }
        else
        {
            session->close(restbed::BAD_REQUEST);
        }
    });
}

template <typename T>
T CRUDService<T>::fromJSON(const std::string& json)
{
    return json::parse(json);
}

template <typename T>
std::string CRUDService<T>::toJSON(const json& item)
{
    try
    {
        return item.dump(2);
    }
    catch (const json::type_error& e)
    {
        std::cout << e.what() << std::endl;
    }

    return {};
}

template <typename T>
void CRUDService<T>::get(const std::shared_ptr<restbed::Session>& session, const std::string& path)
{
    const std::string response_body = "Nice response";
    session->close(restbed::OK, response_body, {{HEADER_CONTENT_LENGTH, std::to_string(response_body.length())}});
}

template <typename T>
void CRUDService<T>::post(const std::shared_ptr<restbed::Session>& session, std::shared_ptr<T>& item)
{
    auto contentLength = session->get_request()->get_header(HEADER_CONTENT_LENGTH, 0);

    session->fetch(contentLength, [this, &item](const std::shared_ptr<restbed::Session>& session, const restbed::Bytes& body)
    {
        try
        {
            const std::string bodyRequest(body.begin(), body.end());
            const T data = fromJSON(bodyRequest);

            item = std::make_shared<T>(data);
            session->close(restbed::CREATED);
        }
        catch (const std::exception& e)
        {
            session->close(restbed::BAD_REQUEST, e.what());
        }
    });
}

template class rest::service::CRUDService<rest::model::Prompt>;
