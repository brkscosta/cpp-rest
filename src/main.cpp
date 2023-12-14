#include "MemoRepo.h"
#include "Prompt.h"
#include "PromptController.h"
#include "PromptMemoDataAccess.h"
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <ratio>
#include <restbed>
#include "config.h"

using namespace restbed;
using namespace rest;

static const uint16_t SERVER_PORT = 8080;

int main(const int, const char**)
{
    auto service = std::make_shared<Service>();
    auto promptMemoDao = std::make_shared<service::PromptMemoDataAccess>(std::make_shared<repository::MemoRepo<std::shared_ptr<model::Prompt>, std::string>>());
    auto promptService = std::make_shared<service::PromptService>(promptMemoDao);
    auto promptController = std::make_shared<controller::PromptController>(service, promptService);

    auto promptResource = std::make_shared<Resource>();
    promptResource->set_path("/prompts");
    promptResource->set_method_handler("POST", [promptController](const std::shared_ptr<Session>& session)
    {
        promptController->handlePost(session);
    });

    promptResource->set_method_handler("GET", [promptController](const std::shared_ptr<Session>& session)
    {
        promptController->handleGet(session);
    });

    auto settings = std::make_shared<Settings>();
    settings->set_port(SERVER_PORT);
    settings->set_default_header("Connection", "close");

    service->publish(promptResource);

    std::cout << "Server started on port: " << SERVER_PORT << "\n Version: " << VERSION << "\n Commit: " << GIT_COMMIT_HASH << std::endl;

    service->start(settings);

    return EXIT_SUCCESS;
}
