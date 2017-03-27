#include <math.h>
#include <map>
#include <string>
#include <vector>
#include "../sorting/sort.hpp"
#include "algo_core.hpp"
#include "algorithm_headers.hpp"

namespace sort {
  AlgoResult result;
  std::map<std::string, void (*)()> algorithms;
  std::vector<int> data_base, data;
  int data_count = 10000, data_min = 0, data_max = 10000;
}

void sort::LoadAlgos() {
  algorithms["quick"] = QuickSort;
  algorithms["insertion"] = InsertionSort;  
  algorithms["merge"] = MergeSort;
  algorithms["heap"] = HeapSort;
  algorithms["badsort"] = BadSort;
  algorithms["selection"] = SelectionSort;
  algorithms["binarytree"] = BinaryTreeSort;
  algorithms["bubble"] = BubbleSort;
  algorithms["cocktail"] = CocktailSort;
}

bool sort::RunAlgo(std::string algo) {
  std::map<std::string, void (*)()>::iterator it;
  it = algorithms.find(algo);
  bool good = false;
  if (it != algorithms.end()) {
    win.Print("Running %s...\n", algo.c_str());
    ClearResults();
    data = data_base;
    it->second();
    win.Print("Compleated %s\n", algo.c_str());
    good = true;
  } else {
    ClearResults();
    win.Print("%s is not a valid sorting algorithm\n", algo.c_str());
    good = false;
  }
  return (good);
}

void sort::ClearResults() {
  result.time_elapsed = 0;
  result.comparisons = 0;
  result.vec_access = 0;
}

void sort::GenData(std::string settings) {
  std::string min_str = "", max_str = "", count_str = "";
  std::string sub_string = "";
  int min = 0, max = 100000;
  int count = 10000;
  for (int i = 0; i < settings.length(); i++) {
    if (settings[i] == ' ' && sub_string != "") {
      if (count_str == "") {
        count_str = sub_string;
      } else if (max_str == "") {
        max_str = sub_string;
      } else if (min_str == "") {
        min_str = sub_string;
      }
      sub_string = "";
    } else if (settings[i] == ' ') {
      sub_string = "";
    } else {
      sub_string += settings[i];
    }
  }
  if (sub_string != "") {
    if (count_str == "") {
      count_str = sub_string;
    } else if (max_str == "") {
      max_str = sub_string;
    } else if (min_str == "") {
      min_str = sub_string;
    }
  }
  if (count_str.length() != 0 && IsInt(count_str) != -1) {
    count = IsInt(count_str);
  }
  if (max_str.length() != 0 && IsInt(max_str) != -1) {
    max = IsInt(max_str);
  }
  if (min_str.length() != 0 && IsInt(min_str) != -1) {
    min = IsInt(min_str);
  }
  GenData(count, min, max);
}

void sort::GenData(int count, int min, int max){
  if(count == -1){
    count = data_count;
  }
  if(min == -1){
    min = data_min;
  }
  if(max == -1){
    max = data_max;
  }
  data_count = count;
  data_min = min;
  data_max = max;
  win.Print("Generating Data...\n%i values between:\n(%i-%i)\n", data_count, data_min, data_max);
  data_base.clear();
  int range = max - min;
  for(int i = 0; i < data_count; i++){
    data_base.push_back(min + (rand() % range));
  }
}

bool sort::IsSorted(){
  bool good = true;
  for(int i = 1; i < data.size() && good == true; i++){
    if(data[i] < data[i-1]){
      good = false;
    }
  }
  return(good);
}

void sort::BadSort(){
}

void sort::Run(std::vector<std::string> algos){
  std::vector<AlgoResult> results;
  bool new_data_gen = false;
  int loops = 1;
  if(IsInt(algos[0]) != -1){
    loops = IsInt(algos[0]);
    algos.erase(algos.begin());
    if(algos[0] == "true"){
      new_data_gen = true;
      algos.erase(algos.begin());
    }
  }
  if(algos[0] == "all"){
    algos.clear();
    for(std::map<std::string, void (*)()>::iterator it = algorithms.begin(); it != algorithms.end(); ++it){
      algos.push_back(it->first);
    }
  }
  for(int i = 0; i < loops; i++){
    if(new_data_gen == true){
      GenData(-1,-1,-1);
    }
    for(int j = 0; j < algos.size(); j++){
      RunAlgo(algos[j]);
      if(results.size() <= j){
        results.push_back(result);
      } else{
        results[j].time_elapsed += result.time_elapsed;
        results[j].comparisons += result.comparisons;
        results[j].vec_access += result.vec_access;
      }
    }
  }
  for(int i = 0; i < algos.size(); i++){
    while(algos[i].size() > 10){
      algos[i].pop_back();
    }
    while(algos[i].size() < 10){
      algos[i] += " ";
    }
  }
  win.Print("\n\nAlgorithm    Sort Time             Raw Time   Comparisons   Array Access\n");
  win.Print("----------------------------------------------------------------------------\n");
  for(int i = 0; i < results.size(); i++){
    results[i].time_elapsed /= (double)loops;
    results[i].comparisons /= loops;
    results[i].vec_access /= loops;
    double dmin, dsec, dmilli_sec, dmicro_sec;
    double remaining_time = results[i].time_elapsed;
    dmin = floor(results[i].time_elapsed / 60.0);
    remaining_time = modf(remaining_time, &dsec);
    dsec -= (dmin * 60);
    remaining_time *= pow(10, 3);
    remaining_time = modf(remaining_time, &dmilli_sec);
    remaining_time *= pow(10, 3);
    dmicro_sec = ceil(remaining_time);
    int min = dmin, sec = dsec, milli_sec = dmilli_sec,
        micro_sec = (int)dmicro_sec;
    win.Print("%s   %.2im:%.2is:%.3ims:%.3ius   %.8f   %.11i   %.12i\n", algos[i].c_str(), min, sec, milli_sec, micro_sec, results[i].time_elapsed, results[i].comparisons, results[i].vec_access);
  }
}
