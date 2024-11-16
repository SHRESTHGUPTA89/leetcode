class Solution {
public:
    bool canPartition(vector<int>& arr) {
        
        int n=arr.size();
        long long sum=accumulate(arr.begin(),arr.end(),0);
        
        if(sum%2!=0){
            
            return false;
            
        }
        
        int target = sum/2;
         
    
        int t[n + 1][target + 1]; // Declare DP table
        
        // Initialize the DP table
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (i == 0) {
                    t[i][j] = false; // No elements, no subset (except sum=0)
                }
                if (j == 0) {
                    t[i][j] = true; // Sum is 0, subset is possible with no elements
                }
            }
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][target]; // Final answer
    }
        
        
        
    
};