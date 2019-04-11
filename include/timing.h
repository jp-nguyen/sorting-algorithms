/*
    This is a library containing the timing interface of the program, supplying
    both the struct to hold timings as well as the functions to get timings.
*/
#ifndef TIMING_H
#define TIMING_H

#include <ctime>
#include "project1.h"
#include "generate.h"
using namespace std;

struct timing {
    int n;
    double seconds; 
};

timing time_sort(void (*sort_func)(vector<int>&), int n, int reps) {
    vector<int> nums = get_random_input(n);
    double total_time = 0;

    for (int i = 0; i < reps; ++i) {
        clock_t start = clock();
        (*sort_func)(nums);
        clock_t end = clock();
        total_time += (float) (end - start) / CLOCKS_PER_SEC;
    }
    double seconds = (float) total_time / reps;

    return {n, seconds};
}

#endif