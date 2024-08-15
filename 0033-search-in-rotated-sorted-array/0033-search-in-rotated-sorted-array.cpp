class Solution {
public:
    int binarySearch(vector<int>& nu, int target , int s, int e){
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nu[mid] == target) {
                return mid;
            } else if (nu[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return -1; // return -1 if the target is not found
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        // Find the pivot
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        int pivot = s;
        int ans = -1;

        // Determine which part of the array to search in
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            ans = binarySearch(nums, target, pivot, n - 1);
        } else {
            ans = binarySearch(nums, target, 0, pivot - 1);
        }

        return ans;
    }
};