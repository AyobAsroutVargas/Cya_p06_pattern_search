/** 
 * Universidad de La Laguna
 * Asignatura: Computabilidad y Algoritmia
 * Practica Nº 6 Búsqueda de patrones
 * @author Ayob Asrout Vargas
 * @date 11/11/2020
 * Contact: alu0101350158@ull.edu.es
 * Compilation: g++ -std=c++14 -g -Wall dfa.cc pattern_search.cc -o pattern_search 
 */

#include "dfa.h"

int main(int argc, char* argv[]) {
  if (argc != 4) {  // Comprobamos que el número de argumentos es correcto
    std::cout << "Usage: " << argv[0] << " Pattern " << "Name of input file"
    << "Name of output file(both files must be in the same directory)"
    << std::endl;
    return 0;
  }

  std::ofstream fout;
  fout.open(argv[3]);
  std::ifstream fin;
  fin.open(argv[2]);
  std::string pattern = argv[1];

  std::string input_string;
  Dfa automaton(pattern);
  while (std::getline(fin, input_string)) {
    if (automaton.evaluate_string(input_string)) {
      fout << "Si\n";
    } else {
      if (automaton.get_not_in_alphabet_()) {
        fout << "Error\n";
      } else {
        fout << "No\n";
      }
    }
  }


  return 0;
}
