#include <iostream>
#include <fstream>
#include "../include/project1.h"
#include "../include/timing.h"
#include "../include/random_generation.h"
using namespace std;

void test_sort(string sort_name, void (*sort_func)(vector<int>&), int limit,
        bool fullyRandom, string filename) {
    cout << "...testing " << sort_name << " sort..." << endl;
    for (int n = 10; n <= limit; n *= 10) {
        timing t = time_sort(sort_func, n, 3, fullyRandom);
        add_timing_to_sheet(filename, sort_name, t);
        print_timing(t);
    }
    cout << "...finished " << sort_name << " sort..." << endl;
}

void test_spin_the_bottle_sort(int limit, bool fullyRandom, string filename) {
    cout << "...testing spin the bottle sort ..." << endl;
    for (int n = 10; n <= limit; n *= 10) {
        timing t = time_spin_the_bottle_sort(n, 3, fullyRandom);
        add_timing_to_sheet(filename, "spin the bottle", t);
        print_timing(t);
    }
    cout << "...finished spin the bottle sort..." << endl;
}

void test_shell_sort(int limit, bool fullyRandom, string filename) {
    int seq[] = {2, 5};
    for (int i = 0; i < 2; ++i) {
        cout << "...testing shell sort " << i << "..." << endl;
        for (int n = 10; n <= limit; n *= 10) {
            timing t = time_shell_sort(n, 3, fullyRandom, seq[i]);
            string sort = "shell ";
            sort += '0' + i;
            add_timing_to_sheet(filename, sort, t);
            print_timing(t);
        }
        cout << "...finished shell sort " << i << "..." << endl;
    }
}

void test_annealing_sort(int limit, bool fullyRandom, string filename) {
    int seq[] = {3, 4};
    for (int i = 0; i < 2; ++i) {
        cout << "...testing annealing sort " << i << "..." << endl;
        for (int n = 10; n <= limit; n *= 10) {
            timing t = time_annealing_sort(n, 3, fullyRandom, seq[i]);
            string sort = "annealing ";
            sort += '0' + i;
            add_timing_to_sheet(filename, sort, t);
            cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
        }
        cout << "...finished annealing sort " << i << "..." << endl;
    }
}

int main() {
    bool fullyRandom;
    string filename = "timings.csv";

    fullyRandom = false; // i.e. nearly sorted

    test_sort("bubble", &bubble_sort, 10000, fullyRandom, filename);
    test_sort("insertion", &insertion_sort, 10000, fullyRandom, filename);
    test_shell_sort(100000, fullyRandom, filename);
    test_spin_the_bottle_sort(1000, fullyRandom, filename);
    test_annealing_sort(1000, fullyRandom, filename);

    fullyRandom = true;

    test_sort("bubble", &bubble_sort, 10000, fullyRandom, filename);
    test_sort("insertion", &insertion_sort, 10000, fullyRandom, filename);
    test_shell_sort(100000, fullyRandom, filename);
    test_spin_the_bottle_sort(1000, fullyRandom, filename);
    test_annealing_sort(1000, fullyRandom, filename);
    return 0;
}
