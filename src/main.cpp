#include <iostream>
#include <fstream>
#include "../include/project1.h"
#include "../include/timing.h"
#include "../include/random_generation.h"
using namespace std;

void test_bubble_sort() {
    cout << "...testing bubble sort..." << endl;
    for (int n = 10; n < 1000000; n *= 10) {
        timing t = time_sort(&bubble_sort, n, 3, true);
        cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
    }
    cout << "...finished bubble sort..." << endl;
}

void test_insertion_sort() {
    cout << "...testing insertion sort..." << endl;
    for (int n = 10; n < 1000000; n *= 10) {
        timing t = time_sort(&insertion_sort, n, 3, true);
        cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
    }
    cout << "...finished insertion sort..." << endl;
}

void test_spin_the_bottle_sort() {
    cout << "...testing spin the bottle sort..." << endl;
    for (int n = 10; n < 1000000; n *= 10) {
        timing t = time_sort(&spin_the_bottle_sort, n, 3, true);
        cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
    }
    cout << "...finished spin the bottle sort..." << endl;
}

int main() {
    test_bubble_sort();
    test_insertion_sort();
    test_spin_the_bottle_sort();
    return 0;
}