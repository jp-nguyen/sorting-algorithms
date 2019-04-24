#include "project1.h"
#include "utils.h"

void annealing_sort(std::vector<int>& nums, const std::vector<int>& temps, const std::vector<int>& reps) {
    int s, n = nums.size(), t = temps.size();

    for (int j = 0; j < t; ++j) {
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < reps[j]; ++k) {
                s = randint(i + 1, min(n - 1, i + temps[j]));
                if (nums[i] > nums[s])
                    swap(nums[i], nums[s]);
            }
        }
        for (int i = n - 1; i > 0; --i) {
            for (int k = 0; k < reps[j]; ++k) {
                s = randint(i - 1, max(0, i - temps[j]));
                if (nums[i] < nums[s])
                    swap(nums[i], nums[s]);
            }
        }
    }
}