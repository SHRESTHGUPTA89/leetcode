#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Create a vector of pairs to store the names and their corresponding heights
        vector<pair<string, int>> people;
        int n = names.size();

        // Populate the vector with names and heights
        for(int i = 0; i < n; i++) {
            people.push_back({names[i], heights[i]});
        }

        // Sort the vector by the heights in descending order
        sort(people.begin(), people.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
        });

        // Extract the names from the sorted vector
        vector<string> ans;
        for(auto& person : people) {
            ans.push_back(person.first);
        }

        return ans;
    }
};
