#include "timing.h"

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
    double seconds, total_time  = 0;
    vector<int> input, nums;
    vector<double> times;

    for (int i = 0; i < reps; ++i) {
        input = fullySorted ? get_uniformly_distributed_input(n) 
            : get_almost_sorted_input(n);

        for (int j = 0; j < reps; ++j) {
            nums = input;

            clock_t start = clock();
            (*sort_func)(nums);
            clock_t end = clock();
            
            assert(is_sorted(nums));
            times.push_back((float) (end - start) / CLOCKS_PER_SEC);
        }
        total_time += *min_element(times.begin(), times.end());
        times.clear();
    }
    seconds = (float) total_time / reps;

    return {n, seconds};
}

timing time_shell_sort(int n, int reps, bool fullySorted, int seq) {
    double seconds, total_time = 0;
    vector<int> input, nums, GAPS = get_shell_sort_gaps(n, seq);
    vector<double> times;

    for (int i = 0; i < reps; ++i) {
        input = fullySorted ? get_uniformly_distributed_input(n) 
            : get_almost_sorted_input(n);

        for (int j = 0; j < reps; ++j) {
            nums = input;

            clock_t start = clock();
            shell_sort(nums, GAPS);
            clock_t end = clock();
            
            assert(is_sorted(nums));
            times.push_back((float) (end - start) / CLOCKS_PER_SEC);
        }
        total_time += *min_element(times.begin(), times.end());
        times.clear();
    }
    seconds = (float) total_time / reps;

    return {n, seconds};
}

timing time_annealing_sort(int n, int reps, bool fullySorted, int seq) {
    double seconds, total_time = 0;
    vector<int> input, nums;
    vector<int> TEMPS = get_annealing_sort_temps(n, seq);
    vector<int> REPS = get_annealing_sort_reps(n, seq);
    vector<double> times;

    for (int i = 0; i < reps; ++i) {
        input = fullySorted ? get_uniformly_distributed_input(n) 
            : get_almost_sorted_input(n);

        for (int j = 0; j < reps; ++j) {
            nums = input;

            clock_t start = clock();
            annealing_sort(nums, TEMPS, REPS);
            clock_t end = clock();
            
            assert(is_sorted(nums));
            times.push_back((float) (end - start) / CLOCKS_PER_SEC);
        }
        total_time += *min_element(times.begin(), times.end());
        times.clear();
    }
    seconds = (float) total_time / reps;

    return {n, seconds};
}