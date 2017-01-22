#include "../../sort_headers.hpp"
#include <appareo.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

namespace sort {
int Btotalrecursioncount = 0;
}

double sort::BucketSort(bool display) {
  int bucketcount = 10;
  if (display == true) {
    appareo::induco::CreateProgressBar("Bucket Sort");
  }
  Btotalrecursioncount = 0;
  double timeelapsed;
  appareo::induco::Timer(true);
  if (display == true) {
    appareo::induco::UpdateProgressBar(0);
  }
  BRecursion(bucketcount, &values, display, true);
  timeelapsed = appareo::induco::Timer();
  if (display == true) {
    appareo::induco::TerminateProgressBar();
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
      appareo::induco::UpdateProgressBar(bucket->size() /
                                         (double)scramble.size());
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
