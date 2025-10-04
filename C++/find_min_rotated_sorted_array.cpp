#include <bits/stdc++.h>
using namespace std;

/*
  Function to find the minimum element in a rotated sorted array (with duplicates).
  Approach: Modified binary search.
  Time Complexity: O(log n) in average case, O(n) in worst case due to duplicates.
*/

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // Minimum is on the right side
            left = mid + 1;
        } else if (nums[mid] < nums[right]) {
            // Minimum is on the left side (including mid)
            right = mid;
        } else {
            // When nums[mid] == nums[right], reduce right by one
            right--;
        }
    }

    return nums[left];
}

int main() {
    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 2, 2, 0, 1};

    cout << "Minimum in [1,3,5]: " << findMin(nums1) << endl;
    cout << "Minimum in [2,2,2,0,1]: " << findMin(nums2) << endl;

    return 0;
}
