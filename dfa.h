/** 
 * @class Dfa
 * @brief Deterministic Finite automaton built given a pattern
 * 
 * Given a pattern the class provides a method to know if a string
 * contains said pattern
 */
#ifndef Dfa_H_
#define Dfa_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <cstdlib>

class Dfa {
 public :
  Dfa(std::string pattern);
  bool all_simbols_in_alphabet(std::string input_string);
  bool get_not_in_alphabet_(void);
  bool evaluate_string(std::string input_string);

 private:
  std::set<char> alphabet_;
  std::string pattern_;
  bool not_in_alphabet_ = false;
};
#endif  // Dfa_H_
