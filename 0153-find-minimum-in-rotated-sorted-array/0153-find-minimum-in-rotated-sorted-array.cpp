class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        
        // If the array is not rotated (e.g., [1, 2, 3, 4, 5]), return the first element
        if (arr[s] <= arr[e]) return arr[s];
        
        // Binary search to find the minimum element
        while (s < e) {
            int m = s + (e - s) / 2;
            
            // If the middle element is greater than the last element,
            // the minimum must be in the right half.
            if (arr[m] > arr[e]) {
                s = m + 1;
            } 
            // Otherwise, the minimum is in the left half (including mid).
            else {
                e = m;
            }
        }
        
        // After the loop, s == e, which is the index of the minimum element.
        return arr[s];
    }
};
