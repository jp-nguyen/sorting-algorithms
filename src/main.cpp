#include <iostream>
#include <fstream>
#include "../include/project1.h"
#include "../include/timing.h"
#include "../include/random_generation.h"
using namespace std;

void test_bubble_sort(string filename) {
    cout << "...testing bubble sort..." << endl;
    for (int n = 10; n < 100000; n *= 10) {
        timing t = time_sort(&bubble_sort, n, 3, true);
        add_timing_to_sheet(filename, "bubble", t);
        cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
    }
    cout << "...finished bubble sort..." << endl;
}

void test_insertion_sort(string filename) {
    cout << "...testing insertion sort..." << endl;
    for (int n = 10; n < 100000; n *= 10) {
        timing t = time_sort(&insertion_sort, n, 3, true);
        add_timing_to_sheet(filename, "insertion", t);
        cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
    }
    cout << "...finished insertion sort..." << endl;
}

void test_spin_the_bottle_sort(string filename) {
    cout << "...testing spin the bottle sort..." << endl;
    for (int n = 10; n < 100000; n *= 10) {
        timing t = time_sort(&spin_the_bottle_sort, n, 1, true);
        add_timing_to_sheet(filename, "spin the bottle", t);
        cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
    }
    cout << "...finished spin the bottle sort..." << endl;
}

int main() {
    string filename = "timings.csv";
    create_empty_timings_sheet(filename);
    test_bubble_sort(filename);
    test_insertion_sort(filename);
    test_spin_the_bottle_sort(filename);
    return 0;
}