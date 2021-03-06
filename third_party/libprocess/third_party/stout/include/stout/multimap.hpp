#ifndef __STOUT_MULTIMAP_HPP__
#define __STOUT_MULTIMAP_HPP__

#include <map>
#include <set>

#include <utility>

// Implementation of a multimap via std::multimap but with a better
// interface. The rationale for creating this is that the
// std::multimap interface is painful to use (requires lots of
// iterator garbage, as well as the use of 'equal_range' which makes
// for cluttered code).
template <typename K, typename V>
class Multimap : public std::multimap<K, V>
{
public:
  void put(const K& key, const V& value);
  std::set<V> get(const K& key) const;
  bool remove(const K& key);
  bool remove(const K& key, const V& value);
  bool contains(const K& key) const;
  bool contains(const K& key, const V& value) const;
};


template <typename K, typename V>
void Multimap<K, V>::put(const K& key, const V& value)
{
  std::multimap<K, V>::insert(std::pair<K, V>(key, value));
}


template <typename K, typename V>
std::set<V> Multimap<K, V>::get(const K& key) const
{
  std::set<V> values; // Values to return.

  std::pair<typename std::multimap<K, V>::const_iterator,
    typename std::multimap<K, V>::const_iterator> range;

  range = std::multimap<K, V>::equal_range(key);

  typename std::multimap<K, V>::const_iterator i;
  for (i = range.first; i != range.second; ++i) {
    values.insert(i->second);
  }

  return values;
}


template <typename K, typename V>
bool Multimap<K, V>::remove(const K& key)
{
  return std::multimap<K, V>::erase(key) > 0;
}


template <typename K, typename V>
bool Multimap<K, V>::remove(const K& key, const V& value)
{
  std::pair<typename std::multimap<K, V>::iterator,
    typename std::multimap<K, V>::iterator> range;

  range = std::multimap<K, V>::equal_range(key);

  typename std::multimap<K, V>::iterator i;
  for (i = range.first; i != range.second; ++i) {
    if (i->second == value) {
      std::multimap<K, V>::erase(i);
      return true;
    }
  }

  return false;
}


template <typename K, typename V>
bool Multimap<K, V>::contains(const K& key) const
{
  return count(key) > 0;
}


template <typename K, typename V>
bool Multimap<K, V>::contains(const K& key, const V& value) const
{
  const std::set<V>& values = get(key);
  return values.count(value) > 0;
}

#endif // __STOUT_MULTIMAP_HPP__
