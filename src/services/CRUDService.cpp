#include "CRUDService.h"
#include "Prompt.h"

using namespace rest::service;

template <typename T>
CRUDService<T>::CRUDService(const std::shared_ptr<restbed::Service>& listener)
    : m_listener(listener)
{
    m_listener->set_error_handler([](const int, const std::exception& error, const std::shared_ptr<restbed::Session>& session)
    {
        std::cout << "Erro ao processar a requisição: " << error.what() << std::endl;
        session->close(restbed::BAD_REQUEST);
    });

    m_listener->set_not_found_handler([this](const std::shared_ptr<restbed::Session>& session)
    {
        const auto request = session->get_request();
        const std::string method = request->get_method();
        const std::string path = request->get_path();

        if (method == "GET" && path.substr(0, 6) == "/data/")
        {
            get(session, path);
        }
        else if (method == "POST" && path == "/data")
        {
            post(session);
        }
        else
        {
            session->close(restbed::BAD_REQUEST);
        }
    });
}

template <typename T>
void CRUDService<T>::get(const std::shared_ptr<restbed::Session>& session, const std::string& path)
{
    const size_t index = std::stoi(path.substr(6));
    if (index >= 0 && index < m_data.size())
    {
        const T& item = m_data[index];
        const std::string response_body = to_json(item);

        session->close(restbed::OK, response_body, {{"Content-Length", std::to_string(response_body.length())}});
    }
    else
    {
        session->close(restbed::NOT_FOUND);
    }
}

template <typename T>
void CRUDService<T>::post(const std::shared_ptr<restbed::Session>& session)
{
    auto contentLength = session->get_request()->get_header("Content-Length", 0);
    session->fetch(contentLength, [this](const std::shared_ptr<restbed::Session>& session, const restbed::Bytes& body)
    {
        try
        {
            const std::string body_str(body.begin(), body.end());
            const T item = from_json(body_str);

            // m_data.push_back(item);
            session->close(restbed::CREATED);
        }
        catch (const std::exception& e)
        {
            session->close(restbed::BAD_REQUEST, e.what());
        }
    });
}

template <typename T>
std::string CRUDService<T>::to_json(const T& item)
{
    return "";
}

template <typename T>
T CRUDService<T>::from_json(const std::string& json)
{
    T item;
    return item;
}

template class rest::service::CRUDService<rest::model::Prompt>;
