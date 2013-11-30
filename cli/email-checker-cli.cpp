#include <iostream>
#include "EmailDomainSpellChecker.h"

int main(int argc, char** argv) {
  EmailDomainSpellChecker edsc;
  for (int i = 1; i < argc; i++) {

    std::cout << argv[i] << " -> " << edsc.suggestDomainCorrection(argv[i])
              << std::endl;
  }
}
