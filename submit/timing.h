/*
    This is a library containing the timing interface of the program, supplying
    both the struct to hold timings as well as the functions to get timings.
*/
#ifndef TIMING_H
#define TIMING_H

#include <ctime>
#include <cassert>
#include <fstream>
#include <algorithm>
#include "project1.h"
#include "random_generation.h"
#include "utils.h"
using namespace std;

struct timing {
    int n;
    double seconds; 
};

void create_empty_timings_sheet(string filename);
void add_timing_to_sheet(string filename, string sort_func, timing t);
void print_timing(timing t);
timing time_sort(void (*sort_func)(vector<int>&), int n, int reps, bool fullyRandom);
timing time_spin_the_bottle_sort(int n, int reps, bool fullyRandom);
timing time_shell_sort(int n, int reps, bool fullyRandom, int seq);
timing time_annealing_sort(int n, int reps, bool fullyRandom, int seq);

#endif