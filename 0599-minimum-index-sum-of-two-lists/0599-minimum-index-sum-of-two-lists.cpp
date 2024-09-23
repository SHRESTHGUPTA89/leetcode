class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map1;
        vector<string> ans;
        int minSum = INT_MAX; 

        
        for (int i = 0; i < list1.size(); ++i) {
            map1[list1[i]] = i;
        }

        
        for (int j = 0; j < list2.size(); ++j) {
            if (map1.find(list2[j]) != map1.end()) {
                int sum = j + map1[list2[j]];
                
                
                if (sum < minSum) {
                    ans.clear();
                    ans.push_back(list2[j]);
                    minSum = sum;
                } 
                
                else if (sum == minSum) {
                    ans.push_back(list2[j]);
                }
            }
        }

        return ans;
    }
};
