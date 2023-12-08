#include "MemoRepo.h"

using namespace rest::repository;

template <typename D, typename I>
MemoRepo<D, I>::MemoRepo()
{
}

template <typename D, typename I>
void MemoRepo<D, I>::add(D& value)
{
    m_data.push_back(value);
}

template <typename D, typename I>
void MemoRepo<D, I>::remove(I& value)
{
}

template <typename D, typename I>
std::vector<D> MemoRepo<D, I>::findAll()
{
    return m_data;
}