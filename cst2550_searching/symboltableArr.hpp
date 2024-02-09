#ifndef _SYMBOL_TABLE_ARR_
#define _SYMBOL_TABLE_ARR_
#include <vector>

template <typename K, typename V>
class SymbolTable {
private:
  K* key_list;
  V* values;
  size_t qty;
  size_t capacity;
  
public:
  SymbolTable() {
    capacity = 100;
    qty = 0;
    key_list = new K[capacity];
    values = new V[capacity];
  }

  ~SymbolTable() {
    delete[] key_list;
    delete[] values;
  }

  int size() {
    return qty;
  }

  bool empty() {
    return qty == 0;
  }

  V& operator[](K key) {
    size_t i = rank(key);
    if (i < qty && key_list[i] == key)
      return values[i];

    // extend arrays to fit new element
    if (qty == capacity)
      resize(2*capacity);

    // shift elements to make room for new key
    for (size_t j = qty; j > i; --j) {
      key_list[j] = key_list[j-1];
      values[j] = values[j-1];
    }

    key_list[i] = key;
    values[i] = V();
    ++qty;
    return values[i];
  }
  
  bool contains(K key) {
    size_t i = rank(key);
    if (i < qty && key_list[i] == key)
      return true;
    return false;
  }

  void resize(size_t newsize) {
    K* tempK = new K[newsize];
    V* tempV = new V[newsize];

    for (size_t i = 0; i < qty; ++i) {
      tempK[i] = key_list[i];
      tempV[i] = values[i];
    }

    delete[] key_list;
    delete[] values;
    
    key_list = tempK;
    values = tempV;
    capacity = newsize;
  }

  size_t rank(K key) {
    long lo = 0;
    long hi = qty-1;

    while (lo <= hi) {
      
      long mid = lo + (hi - lo)/2;
      
      if (key < key_list[mid])
	hi = mid - 1;
      else if (key > key_list[mid])
	lo = mid + 1;
      else
	return mid;
    }
    return lo;
  }
  
  std::vector<K> keys() {
    std::vector<K> thekeys(key_list, key_list + qty);
    return thekeys;
  }
};
#endif
