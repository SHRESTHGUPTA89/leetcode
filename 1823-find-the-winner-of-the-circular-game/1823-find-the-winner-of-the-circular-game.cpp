class Solution {
public:
    int findTheWinner(int n, int k) {
        // Create a list of friends from 1 to n
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back(i + 1);
        }

        // Initialize the current index to start counting from
        int index = 0;

        // Repeat the process until one person is left
        while (arr.size() > 1) {
            // Calculate the index of the friend to remove
            index = (index + k - 1) % arr.size();
            arr.erase(arr.begin() + index);
        }

        // Return the winner
        return arr[0];
        
         
    }//  time comp= O(n*n)
};
