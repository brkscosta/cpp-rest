#include "CRUDService.h"
#include <corvusoft/restbed/settings.hpp>
#include <corvusoft/restbed/status_code.hpp>
#include <memory>

using namespace rest::service;

#include <iostream>
#include <restbed>
#include <vector>

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
        else if (method == "PUT" && path.substr(0, 7) == "/data/")
        {
            put(session, path);
        }
        else if (method == "DELETE" && path.substr(0, 7) == "/data/")
        {
            _delete(session, path);
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
    session->fetch([this](const std::shared_ptr<restbed::Session>& session, const restbed::Bytes& body)
    {
        try
        {
            const std::string body_str(body.begin(), body.end());
            const T item = from_json(body_str);

            m_data.push_back(item);
            session->close(restbed::CREATED);
        }
        catch (const std::exception& e)
        {
            session->close(restbed::BAD_REQUEST, e.what());
        }
    });
}

template <typename T>
void CRUDService<T>::put(const std::shared_ptr<restbed::Session>& session, const std::string& path)
{
    const size_t index = std::stoi(path.substr(6));
    if (index >= 0 && index < m_data.size())
    {
        session->fetch(
            [this, index](const std::shared_ptr<restbed::Session>& session, const restbed::Bytes& body)
            {
                try
                {
                    const std::string body_str(body.begin(), body.end());
                    const T item = from_json(body_str);

                    m_data[index] = item;
                    session->close(restbed::OK);
                }
                catch (const std::exception& e)
                {
                    session->close(restbed::BAD_REQUEST, e.what());
                }
            });
    }
    else
    {
        session->close(restbed::NOT_FOUND);
    }
}

template <typename T>
void CRUDService<T>::_delete(const std::shared_ptr<restbed::Session>& session, const std::string& path)
{
    const size_t index = std::stoi(path.substr(6));
    if (index >= 0 && index < m_data.size())
    {
        m_data.erase(m_data.begin() + index);
        session->close(restbed::NO_CONTENT);
    }
    else
    {
        session->close(restbed::NOT_FOUND);
    }
}

template <typename T>
std::string CRUDService<T>::to_json(const T& item)
{
    // Implemente aqui a conversão da estrutura de dados para JSON
    return "";
}

template <typename T>
T CRUDService<T>::from_json(const std::string& json)
{
    T item;
    // Implemente aqui a conversão do JSON para a estrutura de dados
    return item;
}