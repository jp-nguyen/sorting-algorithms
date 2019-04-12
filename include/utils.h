/*
    This is a library containing common functions and tools for the program.
*/
#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <vector>
using namespace std;

void swap(int &i, int &j);
int randint(int lb, int ub);
bool is_sorted(const vector<int> &nums);

#endif