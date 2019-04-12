/*
    This is a library containing the functions for randomly generating inputs
    for the sorts.
*/
#include "../include/random_generation.h"

void random_shuffle(vector<int> &nums) {
    int i, n = nums.size() - 1;

    while (n >= 0) {
        i = randint(0, n);
        swap(nums[i], nums[n--]);
    }
}

vector<int> get_sorted_input(int n) {
    vector<int> nums = vector<int>(n);
    for (int i = 1; i < n; ++i)
        nums[i] = i;
    return nums;
}

vector<int> get_almost_sorted_input(int n) {
    int i, j;
    vector<int> nums = get_sorted_input(n);
    for (int iter = 2 * log10(n); iter > 0; --iter) {
        i = randint(0, n - 1);
        j = randint(0, n - 1);
        swap(nums[i], nums[j]);
    }
    return nums;
}

vector<int> get_uniformly_distributed_input(int n) {
    vector<int> nums = get_sorted_input(n);
    random_shuffle(nums);
    return nums;
}