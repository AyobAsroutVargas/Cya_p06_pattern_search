#include "dfa.h"

/// Alphabet contains characters {a,b..z}
Dfa::Dfa(std::string pattern) {
  char character = 'a';
  for (int i = 0; i < 26; i++) {
    alphabet_.insert(character++);
  }

  pattern_ = pattern;
}


/// Checks if all simbols of a string are in the alphabet
bool Dfa::all_simbols_in_alphabet(std::string input_string) {
    for (int i = 0; i < input_string.size(); i++) {
      if (alphabet_.count(input_string[i]) == 0) {
        not_in_alphabet_ = true;
        return false;
      }
    }
    return true;
}


bool Dfa::get_not_in_alphabet_(void) {
  return not_in_alphabet_;
}


/**
 * @brief Checks if a string contains the pattern of the class
 * @returns False if the string doesn't have the pattern or if it has any symbol
 * not included in the alphabet
 */
bool Dfa::evaluate_string(std::string input_string) {
  if (all_simbols_in_alphabet(input_string)) {
    int CurrentState = 0;
    for (int j = 0; j < input_string.size(); j++) {
      do {
        for (int i = 0; i < pattern_.size(); i++) {
          if (input_string[i+j] == pattern_[i]) {
          CurrentState++;
          } else {
          CurrentState = 0;
          break;
          }
        }
        if (CurrentState == pattern_.size()) return true;
      }while ((CurrentState < pattern_.size()) && (CurrentState !=0));
    }
    return false;
  } else {
    return false;
  }
}
