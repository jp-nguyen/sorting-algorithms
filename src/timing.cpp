#include "../include/timing.h"

void create_empty_timings_sheet(string filename) {
    ofstream file;
    file.open(filename, ofstream :: trunc);
    file << "sort,n,seconds" << endl;
    file.close();
}

void add_timing_to_sheet(string filename, string sort_func, timing t) {
    ofstream file;
    file.open(filename, ofstream :: app);
    file << sort_func << "," << t.n << "," << t.seconds << endl;
    file.close();
}

timing time_sort(void (*sort_func)(vector<int>&), int n, int reps, bool fullySorted) {
    double total_time = 0;
    vector<int> nums = fullySorted ? get_uniformly_distributed_input(n)
                        : get_almost_sorted_input(n);

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