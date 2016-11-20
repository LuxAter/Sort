#include "../../induco.h"
#include "../../sort_headers.h"
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

namespace sort {
int Btotalrecursioncount = 0;
}

double sort::BucketSort(int bucketcount, bool display) {
  if (display == true) {
    std::cout << "Bucket Sort:\n";
  }
  Btotalrecursioncount = 0;
  double timeelapsed;
  induco::Timer(true);
  if (display == true) {
    induco::DrawLoadingBar(0, 50);
  }
  BRecursion(bucketcount, &values, display, true);
  timeelapsed = induco::Timer();
  if (display == true) {
    induco::DrawLoadingBar(1, 50);
    std::cout << "\nSorted " << values.size() << "\n";
    std::cout << induco::DisplayTime(timeelapsed, true) << "\n";
  }
  return (timeelapsed);
}

void sort::BRecursion(int bucketcount, std::vector<int> *bucket, bool display,
                      bool top) {
  std::vector<std::vector<int>> buckets;
  int max = 0, min = 0, bucketrange;
  for (int i = 0; i < bucketcount; i++) {
    std::vector<int> newbucket;
    buckets.push_back(newbucket);
  }
  max = bucket->at(0);
  min = bucket->at(0);
  for (int i = 1; i < bucket->size(); i++) {
    int value = bucket->at(i);
    if (value > max) {
      max = value;
    }
    if (value < min) {
      min = value;
    }
  }
  bucketrange = ceil((max - min) / (double)bucketcount);
  for (int i = 0; i < bucket->size(); i++) {
    int value = bucket->at(i);
    if (value == max) {
      buckets[buckets.size() - 1].push_back(value);
    } else {
      buckets[BBucket(value - min, bucketrange)].push_back(value);
    }
  }
  bucket->clear();
  for (int i = 0; i < buckets.size(); i++) {
    if (buckets[i].size() <= 1) {
      bucket->insert(bucket->end(), buckets[i].begin(), buckets[i].end());
    } else if (BDupes(buckets[i]) == true) {
      Btotalrecursioncount += buckets[i].size();
      bucket->insert(bucket->end(), buckets[i].begin(), buckets[i].end());
    } else {
      BRecursion(bucketcount, &buckets[i], display);
      bucket->insert(bucket->end(), buckets[i].begin(), buckets[i].end());
    }
    if (display == true && top == true) {
      induco::DrawLoadingBar(bucket->size() / (double)scrambledvalues.size(),
                             50);
    }
  }
}

int sort::BBucket(int value, int bucketsize) {
  return ((floor(value / (double)bucketsize)));
}

bool sort::BDupes(std::vector<int> bucket) {
  if (bucket.size() <= 1) {
    return (true);
  }
  int value = bucket[0];
  for (int i = 1; i < bucket.size(); i++) {
    if (bucket[i] != value) {
      return (false);
    }
  }
  return (true);
}
