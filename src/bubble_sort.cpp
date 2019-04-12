#include "../include/project1.h"
#include "../include/utils.h"

void bubble_sort(std::vector<int>& nums) {
    int n = nums.size();
    bool noSwaps = false;

    for (int i = 1; i < n && !noSwaps; ++i) {
        noSwaps = true;
        for (int j = 0; j < n - i; ++j) {
            if (nums[j] > nums[j + 1]) {      
                noSwaps = false;
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}