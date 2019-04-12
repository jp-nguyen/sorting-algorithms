#include "../include/timing.h"

timing time_sort(void (*sort_func)(vector<int>&), int n, int reps, bool almostSorted) {
    double total_time = 0;
    vector<int> nums = almostSorted ? get_almost_sorted_input(n) 
                        : get_uniformly_distributed_input(n);

    for (int i = 0; i < reps; ++i) {
        clock_t start = clock();
        (*sort_func)(nums);
        clock_t end = clock();

        total_time += (float) (end - start) / CLOCKS_PER_SEC;
        assert(is_sorted(nums));
    }
    double seconds = (float) total_time / reps;

    return {n, seconds};
}

timing time_annealing_sort(int n, int reps) {
    return {n, (float) reps};
}

timing time_shell_sort(int n, int reps) {
    return {n, (float) reps};
}