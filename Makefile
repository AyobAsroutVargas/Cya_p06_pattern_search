CXX = g++
CXXFLAGS = -std=c++14 -g -Wall

pattern_search: pattern_search.o dfa.o
	$(CXX) $(CXXFLAGS) -o $@ $^

dfa.o: dfa.cc dfa.h
	$(CXX) -c dfa.cc

pattern_search.o: pattern_search.cc dfa.h
	$(CXX) -c pattern_search.cc

clean:
	rm pattern_search *.o outfile.txt
  
