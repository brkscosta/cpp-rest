#pragma once
#include "IMemoRepo.h"
#include <restbed>
#include <vector>

namespace rest::repository
{

template <typename D, typename I>
class MemoRepo : public IMemoRepo<D, I>
{
  public:
    MemoRepo();
    ~MemoRepo() = default;
    void add(const D& value) override;
    void remove(const I& value) override;
    std::vector<D> findAll() override;
    std::optional<D> findPromptById(const std::string& id) override;
    typename IMemoRepo<D, I>::ManyOrNullResults searchByTitle(const std::string& title) override;

  private:
    std::vector<D> m_data;
};

}  // namespace rest::repository