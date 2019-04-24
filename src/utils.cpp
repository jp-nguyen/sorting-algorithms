#include "utils.h"

void swap(int &i, int&j) {
    int temp = i;
    i = j;
    j = temp;
}

int min(int i, int j) {
    return i < j ? i : j;
}

int max(int i, int j) {
    return i > j ? i : j;
}

bool is_sorted(const vector<int> &nums) {
    int n = nums.size();
    if (n < 2)
        return true;
    for (int i = 1; i < n; ++i) {
        if (nums[i - 1] > nums[i])
            return false;
    }
    return true;
}

int randint(int lb, int ub) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    if (lb < ub) {
        uniform_int_distribution<int> range(lb, ub);
        return range(gen);
    } else
        return lb;
}

void reverse(vector<int> & nums) {
    int n = nums.size();
    for (int i = 0; i < n/2; ++i) {
        swap(nums[i], nums[n - 1 - i]);
    }
}

vector<int> get_shell_sort_gaps(int n, int seq) {
    vector<int> gaps;
    int k;
    switch (seq) {
    case 0:
        for (k = (int) log2(n + 1) ; k > 0; --k)
            gaps.push_back((int) pow(2.0, k) - 1);
        break;
    case 1:
        for (int i = (int) n / 2.2; i > 0; i = (int) i / 2.2) {
            gaps.push_back(i);
        }
        break;
    default:
        for (int i = n / 2; i > 0; i /= 2)
            gaps.push_back(i);
        break;
    }
    return gaps;
}

vector<int> get_annealing_sort_temps(int n, int seq) {
    vector<int> temps;
    switch (seq) {
    default:
        for (int i = 0; i < n; ++i)
            temps.push_back(1);
        break;
    }
    return temps;
}

vector<int> get_annealing_sort_reps(int n, int seq) {
    vector<int> reps;
    switch (seq) {
    default:
        for (int i = 0; i < n; ++i)
            reps.push_back(1);
        break;
    }
    return reps;
}