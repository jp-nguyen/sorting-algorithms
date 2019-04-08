#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <ctime>
using namespace std;

struct timing {
    int n;
    double seconds;    
};

vector<int> get_random_input(int n) {
    vector<int> input = vector<int>(n);
    for (int i = 1; i < n; ++i)
        input[i] = i;
    random_shuffle(input.begin(), input.end()); 
    return input;
}

inline void swap(int &i, int&j) {
    int temp = i;
    i = j;
    j = temp;
}

void bubble_sort(vector<int> & input) {
    int n = input.size();
    bool noSwaps = false;;

    for (int i = 1; i < n && !noSwaps; ++i) {
        noSwaps = true;
        for (int j = 0; j < n - i; ++j) {
            if (input[j] > input[j + 1]) {      
                noSwaps = false;
                swap(input[j], input[j + 1]);
            }
        }
    }
}

timing time_sort(int n, int reps) {
    vector<int> input = get_random_input(n);
    double total_time = 0;

    for (int i = 0; i < reps; ++i) {
        clock_t start = clock();
        bubble_sort(input);
        clock_t end = clock();
        total_time += (float) (end - start) / CLOCKS_PER_SEC;
    }
    double seconds = (float) total_time / reps;

    return {n, seconds};
}

int main() {
    for (int n = 10; n < 1000000; n *= 10) {
        timing t = time_sort(n, 3);
        cout << "Sorted " << t.n << " items in " << t.seconds << " seconds" << endl;
    }
    return 0;
}