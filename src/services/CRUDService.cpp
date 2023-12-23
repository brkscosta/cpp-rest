#include "CRUDService.h"
#include "Prompt.h"
#include "corvusoft/restbed/service.hpp"
#include <cstdint>
#include <memory>
#include <nlohmann/json_fwd.hpp>
#include <string>
#include <vector>

using namespace rest::service;
using namespace nlohmann;

namespace
{
const std::string HEADER_CONTENT_LENGTH = "Content-Length";

std::multimap<std::string, std::string> buildJsonResponseHeader(const std::uint16_t& messageContentLength)
{
    return { { HEADER_CONTENT_LENGTH, std::to_string(messageContentLength) }, {"Content-Type", "application/json"} };
};

};  // namespace

template <typename T>
CRUDService<T>::CRUDService(const std::shared_ptr<restbed::Service>& listener)
    : m_listener(listener)
{
    m_listener->set_error_handler([](const int, const std::exception& error, const std::shared_ptr<restbed::Session>& session)
    {
        std::cout << "Error on precessing request: " << error.what() << std::endl;
        session->close(restbed::BAD_REQUEST);
    });

    m_listener->set_not_found_handler([](const std::shared_ptr<restbed::Session>& session)
    {
        std::cout << "Endpoint not found" << std::endl;
        session->close(restbed::BAD_REQUEST);
    });
}

template <typename T>
T CRUDService<T>::fromJSON(const std::string& json)
{
    return json::parse(json);
}

template <typename T>
void CRUDService<T>::get(const std::shared_ptr<restbed::Session>& session, const std::string& jsonData)
{
    if (jsonData.empty())
    {
        nlohmann::json responseMessage = {
            {"message", "Resource not found"}
        };

        std::string strResponseMessage = responseMessage.dump(2);
        session->close(restbed::NOT_FOUND, strResponseMessage, buildJsonResponseHeader(strResponseMessage.length()));
        return;
    }

    session->close(restbed::OK, jsonData, buildJsonResponseHeader(jsonData.length()));
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
