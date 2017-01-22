#include "../../sort_headers.hpp"
#include <appareo.h>
#include <pessum.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

double sort::ShellSort(bool display) {
  if (display == true) {
    appareo::induco::CreateProgressBar("Shell Sort");
  }
  double timeelapsed;
  appareo::induco::Timer(true);
  std::vector<int> gaps;
  int gap = (values.size() / (pow(2, 1)));
  int counter = 1;
  pessum::logging::Log(pessum::logging::DATA, std::to_string(gap));
  while (gap > 1) {
    gaps.push_back(gap);
    counter++;
    gap = (values.size() / (pow(2, counter)));
  }
  if (gap <= 1) {
    gaps.push_back(1);
  }
  std::string line = "";
  for(int i = 0; i <values.size();i++){
	  line += std::to_string(values[i]) + ",";
  }
  pessum::logging::Log(pessum::logging::INFORMATION, line);
  line = "";
  for(int i =0;i<gaps.size();i++){
	line += std::to_string(gaps[i]) + ",";
  }
  pessum::logging::Log(pessum::logging::DATA, line);
  for (int i = 0; i < gaps.size(); i++) {
    for (int j = 0; j < values.size(); j++) {
      if(j + gaps[i] < values.size() && values[j + gaps[i]] < values[j]){
      	iter_swap(values.begin() + j + gaps[i], values.begin() + j);
      } else if(j - gaps[i] >= 0 && values[j - gaps[i]] > values[j]){
	      iter_swap(values.begin() + j - gaps[i], values.begin() + j);
      }
    }
  }
  timeelapsed = appareo::induco::Timer();
  if (display == true) {
    appareo::induco::TerminateProgressBar();
  }
  line = "";
  for(int i =0;i<values.size();i++){
	line += std::to_string(values[i]) + ",";
  }
  pessum::logging::Log(pessum::logging::INFORMATION, line);
  return (timeelapsed);
}
