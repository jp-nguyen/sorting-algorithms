#include <iostream>
#include <fstream>
#include <vector>
#include "../include/timing.h"
using namespace std;

void test_bubble_sort() {
    cout << "...testing bubble sort..." << endl;
    for (int n = 10; n < 1000000; n *= 10) {
        timing t = time_sort(&bubble_sort, n, 3);
        cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
    }
    cout << "...finished bubble sort..." << endl;
}

int main() {
    test_bubble_sort();
    return 0;
}