/*
    This is a library containing the functions for randomly generating inputs
    for the sorts.
*/
#ifndef RANDOM_GENERATION_H
#define RANDOM_GENERATION_H

#include <vector>
#include <cmath>
#include "utils.h"
using namespace std;

void random_shuffle(vector<int> &nums);
vector<int> get_sorted_input(int n);
vector<int> get_almost_sorted_input(int n);
vector<int> get_uniformly_distributed_input(int n);

#endif