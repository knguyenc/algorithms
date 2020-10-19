#ifndef ALGORITHMS_DATA_STRUCTURES_HASHING_HASH_TABLE_SEPARATE_CHAINING_H_
#define ALGORITHMS_DATA_STRUCTURES_HASHING_HASH_TABLE_SEPARATE_CHAINING_H_

#include <algorithm>
#include <iostream>
#include <vector>

namespace data_structures {
namespace hashing {

template <class K, class V>
class HashTableSeparateChaining {
  enum { DEFAULT_SLOTS = 10 };

 public:
  class Node {
   private:
    K key_;
    V value_;
    Node *next_;
    friend class HashTableSeparateChaining;

   public:
    Node(const K &key, const V &value) : key_(key), value_(value), next_(NULL) {}
  };

 public:
  HashTableSeparateChaining();
  explicit HashTableSeparateChaining(int slots);
  ~HashTableSeparateChaining();
  int Size() const;
  bool IsEmpty() const;
  K *Keys() const;
  V Get(K key) const;
  void Insert(K key, V value);
  V Remove(K key);

  friend std::ostream &operator<<(std::ostream &out, const HashTableSeparateChaining &hash_table) {
    if (hash_table.IsEmpty())
      out << "Empty hash table";
    else
      for (K key : hash_table.keys_) out << "(" << key << ": " << hash_table.Get(key) << ") ";
    return out;
  }

 protected:
  int Hashing(K key) const;

 private:
  Node **buckets_;
  std::vector<K> keys_;
  int slots_;
  int size_;
};

template <class K, class V>
HashTableSeparateChaining<K, V>::HashTableSeparateChaining()
    : buckets_(new Node *[DEFAULT_SLOTS]), slots_(DEFAULT_SLOTS), size_(0) {
  for (int i = 0; i < slots_; i++) buckets_[i] = NULL;
}

template <class K, class V>
HashTableSeparateChaining<K, V>::HashTableSeparateChaining(int slots)
    : buckets_(new Node *[slots]), slots_(slots), size_(0) {
  for (int i = 0; i < slots_; i++) buckets_[i] = NULL;
}

template <class K, class V>
HashTableSeparateChaining<K, V>::~HashTableSeparateChaining() {
  for (int i = 0; i < slots_; i++) delete buckets_[i];
  delete[] buckets_;
}

template <class K, class V>
int HashTableSeparateChaining<K, V>::Size() const {
  return size_;
}

template <class K, class V>
bool HashTableSeparateChaining<K, V>::IsEmpty() const {
  return size_ == 0;
}

template <class K, class V>
K *HashTableSeparateChaining<K, V>::Keys() const {
  K *keys_array = new K[keys_.size()];
  for (unsigned long i = 0; i < keys_.size(); i++) keys_array[i] = keys_[i];
  return keys_array;
}

template <class K, class V>
int HashTableSeparateChaining<K, V>::Hashing(K key) const {
  int hash = (int)key % slots_;
  if (hash < 0) hash += slots_;
  return hash;
}

template <class K, class V>
V HashTableSeparateChaining<K, V>::Get(K key) const {
  int hash = Hashing(key);
  Node *node = buckets_[hash];
  while (node != NULL && node->key_ != key) node = node->next_;
  if (node == NULL) throw std::runtime_error("Key is not exist in hash table");
  return node->value_;
}

template <class K, class V>
void HashTableSeparateChaining<K, V>::Insert(K key, V value) {
  int hash = Hashing(key);
  Node *node = new Node(key, value);
  if (buckets_[hash] == NULL)
    buckets_[hash] = node;
  else {
    Node *temp = buckets_[hash];
    if (temp->key_ == key) throw std::runtime_error("Key is already exist");
    while (temp->next_ != NULL) {
      if (temp->key_ == key) throw std::runtime_error("Key is already exist");
      temp = temp->next_;
    }
    temp->next_ = node;
  }
  keys_.push_back(key);
  size_++;
}

template <class K, class V>
V HashTableSeparateChaining<K, V>::Remove(K key) {
  int hash = Hashing(key);
  Node *node = buckets_[hash], *prev = NULL;
  while (node != NULL && node->key_ != key) {
    prev = node;
    node = node->next_;
  }
  if (node == NULL) throw std::runtime_error("Key is not exist in this hash table");
  V removed = node->value_;
  if (node == buckets_[hash])
    buckets_[hash] = node->next_;
  else if (prev == NULL)
    buckets_[hash] = NULL;
  else
    prev->next_ = node->next_;
  node->next_ = NULL;
  delete node;
  keys_.erase(std::remove(keys_.begin(), keys_.end(), key), keys_.end());
  size_--;
  return removed;
}

}  // namespace hashing
}  // namespace data_structures

#endif  // ALGORITHMS_DATA_STRUCTURES_HASHING_HASH_TABLE_SEPARATE_CHAINING_H_
