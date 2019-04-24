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

void print_timing(timing t) {
    cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
}

timing time_sort(void (*sort_func)(vector<int>&), int n, int reps, bool fullyRandom) {
    double seconds, total_time = 0;
    vector<int> nums;

    for (int i = 0; i < reps; ++i) {
        set_vector(nums, fullyRandom ? get_uniformly_distributed_input(n) 
            : get_almost_sorted_input(n));

        clock_t start = clock();
        (*sort_func)(nums);
        clock_t end = clock();
            
        assert(is_sorted(nums));
        total_time += (float) (end - start) / CLOCKS_PER_SEC;
    }
    seconds = (float) total_time / reps;

    return {n, seconds};
}

timing time_spin_the_bottle_sort(int n, int reps, bool fullyRandom) {
    double seconds, total_time = 0;
    vector<int> nums;

    for (int i = 0; i < reps; ++i) {
        set_vector(nums, fullyRandom ? get_uniformly_distributed_input(n) 
            : get_almost_sorted_input(n));

        clock_t start = clock();
        spin_the_bottle_sort(nums);
        clock_t end = clock();
            
        assert(is_sorted(nums));
        total_time += (float) (end - start) / CLOCKS_PER_SEC;
    }
    seconds = (float) total_time / reps;

    return {n, seconds};
}

timing time_shell_sort(int n, int reps, bool fullyRandom, int seq) {
    double seconds, total_time = 0;
    vector<int> nums, GAPS = get_shell_sort_gaps(n, seq);

    for (int i = 0; i < reps; ++i) {
        set_vector(nums, fullyRandom ? get_uniformly_distributed_input(n) 
            : get_almost_sorted_input(n));

        clock_t start = clock();
        shell_sort(nums, GAPS);
        clock_t end = clock();
            
        assert(is_sorted(nums));
        total_time += (float) (end - start) / CLOCKS_PER_SEC;
    }
    seconds = (float) total_time / reps;

    return {n, seconds};
}

timing time_annealing_sort(int n, int reps, bool fullyRandom, int seq) {
    double seconds, total_time = 0;
    vector<int> TEMPS = get_annealing_sort_temps(n, seq);
    vector<int> REPS = get_annealing_sort_reps(n, seq);
    vector<int> nums;

    for (int i = 0; i < reps; ++i) {
        set_vector(nums, fullyRandom ? get_uniformly_distributed_input(n)
            : get_almost_sorted_input(n));

        clock_t start = clock();
        annealing_sort(nums, TEMPS, REPS);
        clock_t end = clock();
        
        assert(is_sorted(nums));
        total_time += (float) (end - start) / CLOCKS_PER_SEC;
    }
    seconds = (float) total_time / reps;

    return {n, seconds};
}