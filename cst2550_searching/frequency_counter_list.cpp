#include <iostream>
#include <string>
#include "symboltableLL.hpp"

int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0]
	      << " <min-length>\n";
    exit(1);
  }

  size_t min_length = atoi(argv[1]);
  SymbolTable<std::string, size_t> st;
  
  std::string word = "";
  while (std::cin >> word) {
    
    if (word.size() < min_length)
      continue;

    // if st doesn't contain word, adds default
    // constructed value for word, i.e. 0
    st[word]++;
  }

  std::string max = "";
  st[max] = 0;

  for (std::string word : st.keys())
    if (st[word] > st[max])
      max = word;

  std::cout << max << " " << st[max] << std::endl;

  return 0;
}
