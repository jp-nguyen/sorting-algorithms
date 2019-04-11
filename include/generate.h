/*
    This is a library containing the functions for randomly generating inputs
    for the sorts.
*/
#ifndef GENERATE_H
#define GENERATE_H

#include <algorithm>
using namespace std;

vector<int> get_random_input(int n) {
    vector<int> input = vector<int>(n);
    for (int i = 1; i < n; ++i)
        input[i] = i;
    random_shuffle(input.begin(), input.end()); 
    return input;
}

#endif