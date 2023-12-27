#pragma once
#include <optional>
#include <string>
#include <variant>
#include <vector>

namespace rest::repository
{

template <typename D, typename I>
class IMemoRepo
{
  public:
    using ManyOrNullResults = std::variant<std::vector<D>, std::optional<D>>;

    /*
    * Adds an element to the memory
    */
    virtual void add(const D& value) = 0;

    /*
    * Remove an element.
    */
    virtual void remove(const I& value) = 0;

    /*
     * Returns all elements stored.
     */
    virtual std::vector<D> findAll() = 0;

    /*
    * Find a element by id.
    */
    virtual std::optional<D> findPromptById(const std::string& id) = 0;
    
    /*
    * Returns an array of elements in case more the one matchs otherwise will return one optional, this optional can be nullopt
    */
    virtual ManyOrNullResults searchByTitle(const std::string& title) = 0;
};
}  // namespace rest::repository