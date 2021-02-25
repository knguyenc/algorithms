#ifndef ALGORITHMS_DATA_STRUCTURES_HASHING_HASH_TABLE_OPEN_ADDRESSING_H_
#define ALGORITHMS_DATA_STRUCTURES_HASHING_HASH_TABLE_OPEN_ADDRESSING_H_

#include <algorithm>
#include <iostream>
#include <vector>

namespace data_structures {
namespace hashing {

template <class K, class V>
class HashTableOpenAddressing {
  enum { DEFAULT_CAPACITY = 10 };

 public:
  HashTableOpenAddressing();
  explicit HashTableOpenAddressing(int capacity);
  ~HashTableOpenAddressing();
  int Size() const;
  bool IsEmpty() const;
  K *Keys() const;
  V Get(K key) const;
  void Insert(K key, V value);
  V Remove(K key);

  friend std::ostream &operator<<(std::ostream &out,
                                  const HashTableOpenAddressing &hash_table) {
    if (hash_table.IsEmpty())
      out << "Empty hash table";
    else {
      for (int i = 0; i < hash_table.capacity_; i++)
        if (hash_table.keys_[i] != NULL)
          out << "(" << *hash_table.keys_[i] << ": " << *hash_table.values_[i]
              << ") ";
    }
    return out;
  }

 protected:
  int Hashing(K key) const;
  int Rehashing() const;

 private:
  K **keys_;
  V **values_;
  int capacity_;
  int size_;
};

template <class K, class V>
HashTableOpenAddressing<K, V>::HashTableOpenAddressing()
    : keys_(new K *[DEFAULT_CAPACITY]),
      values_(new V *[DEFAULT_CAPACITY]),
      capacity_(DEFAULT_CAPACITY),
      size_(0) {
  for (int i = 0; i < capacity_; i++) {
    keys_[i] = NULL;
    values_[i] = NULL;
  }
}

template <class K, class V>
HashTableOpenAddressing<K, V>::HashTableOpenAddressing(int capacity)
    : keys_(new K *[capacity]),
      values_(new V *[capacity]),
      capacity_(capacity),
      size_(0) {
  for (int i = 0; i < capacity_; i++) {
    keys_[i] = NULL;
    values_[i] = NULL;
  }
}

template <class K, class V>
HashTableOpenAddressing<K, V>::~HashTableOpenAddressing() {
  for (int i = 0; i < capacity_; i++) {
    delete keys_[i];
    delete values_[i];
  }
  delete[] keys_;
  delete[] values_;
}

template <class K, class V>
int HashTableOpenAddressing<K, V>::Size() const {
  return size_;
}

template <class K, class V>
bool HashTableOpenAddressing<K, V>::IsEmpty() const {
  return size_ == 0;
}

template <class K, class V>
K *HashTableOpenAddressing<K, V>::Keys() const {
  return keys_;
}

template <class K, class V>
int HashTableOpenAddressing<K, V>::Hashing(K key) const {
  int hash = (int)key % capacity_;
  if (hash < 0) hash += capacity_;
  return hash;
}

template <class K, class V>
int HashTableOpenAddressing<K, V>::Rehashing() const {
  for (int i = 0; i < capacity_; i++)
    if (keys_[i] == NULL) return i;
  throw std::runtime_error("Hash table is full");
}

template <class K, class V>
V HashTableOpenAddressing<K, V>::Get(K key) const {
  int index;
  for (index = 0; index < capacity_; index++)
    if (keys_[index] != NULL && *keys_[index] == key) break;
  if (index > capacity_ - 1)
    throw std::runtime_error("Key is not exist in this hash table");
  return *values_[index];
}

template <class K, class V>
void HashTableOpenAddressing<K, V>::Insert(K key, V value) {
  for (int i = 0; i < capacity_; i++)
    if (keys_[i] != NULL && *keys_[i] == key)
      throw std::runtime_error("Key is already exist");
  int hash = Hashing(key);
  if (keys_[hash] != NULL) hash = Rehashing();
  keys_[hash] = new K;
  *keys_[hash] = key;
  values_[hash] = new V;
  *values_[hash] = value;
  size_++;
}

template <class K, class V>
V HashTableOpenAddressing<K, V>::Remove(K key) {
  int index;
  for (index = 0; index < capacity_; index++)
    if (keys_[index] != NULL && *keys_[index] == key) break;
  if (index > capacity_ - 1) throw std::runtime_error("Key is not exist");
  V removed = *values_[index];
  keys_[index] = NULL;
  values_[index] = NULL;
  size_--;
  return removed;
}

}  // namespace hashing
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_HASHING_HASH_TABLE_OPEN_ADDRESSING_H_
