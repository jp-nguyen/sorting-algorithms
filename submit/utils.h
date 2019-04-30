/*
    This is a library containing common functions and tools for the program.
*/
#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

void swap(int &i, int &j);
int min(int i, int j);
int max(int i, int j);
int randint(int lb, int ub);
bool is_sorted(const vector<int> &nums);
void set_vector(vector<int> &nums, const vector<int>& src);
void reverse(vector<int> &nums);
vector<int> get_shell_sort_gaps(int n, int seq);
vector<int> get_annealing_sort_temps(int n, int seq);
vector<int> get_annealing_sort_reps(int n, int seq);

#endif