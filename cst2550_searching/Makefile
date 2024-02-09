CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic

.PHONY : all clean
all : frequency_counter_array frequency_counter_list

frequency_counter_array : frequency_counter_array.cpp symboltableArr.hpp
	$(CXX) $(CXXFLAGS) -o $@ $<

frequency_counter_list : frequency_counter_list.cpp symboltableLL.hpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean :
	$(RM) frequency_counter_array frequency_counter_list

