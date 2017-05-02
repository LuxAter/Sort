#include <ostendo.h>
#include <pessum.h>
#include <iostream>
#include <string>
#include "sorting/sort.hpp"

int main(int argc, char const* argv[]) {
  pessum::InitializePessum(true, true);
  ostendo::InitOstendo(true, 1);
  ostendo::SetLogHandle(pessum::logging::Log);
  srand(time(NULL));
  sort::MainLoop();
  ostendo::TermOstendo();
  pessum::TerminatePessum();
  return (0);
}
