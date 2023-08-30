// Given an array arr of size n. We need to find the number of pairs. i, j such that. arr[i] XOR arr[j] >= arr[i] AND arr[j].
// Constraints were:
// 2 <= n <= 2e5
// 1 <= arr[i] <= 2^31
// Basic Idea was to check for the leftmost set bit of numbers, if these are equal then we have AND >= XOR.

#include <iostream>
#include <vector>
#include <cmath>

int countXorsAtLeastAnds(std::vector<int> nums) {
    /* Returns number of pairs i,j where nums[i] ^ nums[j] >= nums[i] & nums[j] */

    // Idea: if MSB positions are different: ^ has that bit set, while & does not. So ^ > &
    //       if .................. the same: ^ clears that bit, while & keeps it. So ^ < &
    // So we count the number of values with a different MSB position

    std::vector<int> counts(32, 0);
    int zeros = 0; // separately count zeros to avoid log2(0)
    int total = 0;
    for (int i = 0; i < nums.size(); i++) { // there are i previous numbers
        int n = nums[i];
        if (n == 0) {
            total += i - zeros;
            zeros++;
        } else {
            int p = log2(n);
            total += i - counts[p];
            counts[p]++;
        }
    }

    return total;
}

int main() {
    std::vector<int> nums = {3, 6, 8, 12};
    int result = countXorsAtLeastAnds(nums);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
