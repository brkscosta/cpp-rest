#include "ISessionWrapper.h"

#include <restbed>

namespace rest::service {
class IResourceWrapper
{
public:
    virtual ~IResourceWrapper() = default;

    virtual void setPaths(const std::set<std::string>& paths) = 0;
    virtual void setMethodHandler(const std::string& method,
                                  const std::function<void(const std::shared_ptr<ISessionWrapper>)>& callback) = 0;
};
}   // namespace rest::service
