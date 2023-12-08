#pragma once
#include <vector>

namespace rest::repository
{

template <typename D, typename I>
class IMemoRepo
{
  public:
    virtual void add(D& value) = 0;
    virtual void remove(I& value) = 0;
    virtual std::vector<D> findAll() = 0;
};
}  // namespace rest::repository