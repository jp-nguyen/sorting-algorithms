#include <iostream>
#include <fstream>
#include "../include/project1.h"
#include "../include/timing.h"
#include "../include/random_generation.h"
using namespace std;

void test_sort(string sort_name, void (*sort_func)(vector<int>&), int limit, string filename) {
    cout << "...testing " << sort_name << " sort..." << endl;
    for (int n = 10; n <= limit; n *= 10) {
        timing t = time_sort(sort_func, n, 3, true);
        add_timing_to_sheet(filename, sort_name, t);
        cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
    }
    cout << "...finished " << sort_name << " sort..." << endl;
}

void test_shell_sort(int limit, string filename) {
    for (int i = 0; i < 2; ++i) {
        cout << "...testing shell sort " << i << "..." << endl;
        for (int n = 10; n <= limit; n *= 10) {
            timing t = time_shell_sort(n, 5, true, i);
            string sort = "shell";
            sort += '0' + i;
            add_timing_to_sheet(filename, sort, t);
            cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
        }
        cout << "...finished shell sort " << i << "..." << endl;
    }
}

void test_annealing_sort(int limit, string filename) {
    for (int i = 0; i < 2; ++i) {
        cout << "...testing annealing sort " << i << "..." << endl;
        for (int n = 10; n <= limit; n *= 10) {
            timing t = time_annealing_sort(n, 5, true, i);
            string sort = "annealing";
            sort += '0' + i;
            add_timing_to_sheet(filename, sort, t);
            cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
        }
        cout << "...finished annealing sort " << i << "..." << endl;
    }
}

int main() {
    string filename = "timings.csv";
    create_empty_timings_sheet(filename);
    // test_sort("bubble", &bubble_sort, 100000, filename);
    // test_sort("insertion", &insertion_sort, 100000, filename);
    // test_sort("spin the bottle", &spin_the_bottle_sort, 1000, filename);
    // test_shell_sort(100000, filename);
    test_annealing_sort(100000, filename);
    return 0;
}