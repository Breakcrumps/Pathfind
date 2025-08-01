#pragma once

#include <unordered_map>

namespace Pathfind
{
  template <typename TKey, typename TValue>
  class UnorderedMap
  {
  private:
    std::unordered_map<TKey, TValue> _data;

  public:
    TValue& operator[](const TKey& key);

    const TValue& At(const TKey& key) const;

    bool Contains(const TKey& key) const;
    
  };

  template <typename TKey, typename TValue>
  inline TValue& UnorderedMap<TKey, TValue>::operator[](const TKey& key)
  {
    return _data[key];
  }

  template <typename TKey, typename TValue>
  inline const TValue &UnorderedMap<TKey, TValue>::At(const TKey &key) const
  {
    return _data.at(key);
  }

  template <typename TKey, typename TValue>
  inline bool UnorderedMap<TKey, TValue>::Contains(const TKey& key) const
  {
    return _data.find(key) != _data.end();
  }

}
