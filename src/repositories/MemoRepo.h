#pragma once
#include "IMemoRepo.h"
#include <vector>

namespace rest::repository
{

template <typename D, typename I>
class MemoRepo : public IMemoRepo<D, I>
{
  public:
    MemoRepo();
    ~MemoRepo() = default;
    void add(D& value) override;
    void remove(I& value) override;
    std::vector<D> findAll() override;

  private:
    std::vector<D> m_data;
};

}  // namespace rest::repository