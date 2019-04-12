#include "../include/utils.h"

void swap(int &i, int&j) {
    int temp = i;
    i = j;
    j = temp;
}

int randint(int lb, int ub) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<int> range(lb, ub);
    
    return range(gen);
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