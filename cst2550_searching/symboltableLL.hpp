#ifndef _SYMBOL_TABLE_LL_
#define _SYMBOL_TABLE_LL_
#include <vector>

template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node<K,V>* next;

  Node(K key, V value, Node<K,V>* next) {
    this->key = key;
    this->value = value;
    this->next = next;
  }
};

template <typename K, typename V>
class SymbolTable {
private:
  Node<K,V>* first;
  
public:
  SymbolTable() {
    first = nullptr;
  }

  ~SymbolTable() {
    while (first != nullptr) {
      Node<K,V>* next = first->next;
      delete first;
      first = next;
    }
  }

  V& operator[](K key) {
    for (Node<K,V>* x = first; x != nullptr; x = x->next)
      if (key == x->key)
	return x->value;
    first = new Node<K,V>(key, V(), first);
    return first->value;
  }
  
  bool contains(K key) {
    for (Node<K,V>* x = first; x != nullptr; x = x->next)
      if (key == x->key)
	return true;
    return false;
  }

  std::vector<K> keys() {
    std::vector<K> keys;
    for (Node<K,V>* x = first; x != nullptr; x = x->next)
      keys.push_back(x->key);
    return keys;
  }
};
#endif
