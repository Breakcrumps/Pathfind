#pragma once

#include <unordered_set>

namespace Pathfind
{
  template <typename T>
  class UnorderedSet
  {
  private:
    std::unordered_set<T> _data;

  public:
    bool Contains(const T& item) const;

    void Insert(const T& item);

  };

  template <typename T>
  inline bool UnorderedSet<T>::Contains(const T& item) const
  {
    return _data.find(item) != _data.end();
  }

  template <typename T>
  inline void UnorderedSet<T>::Insert(const T& item)
  {
    _data.insert(item);
  }
}
