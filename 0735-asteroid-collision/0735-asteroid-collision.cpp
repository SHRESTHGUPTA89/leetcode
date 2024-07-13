class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for (int i = 0; i < asteroids.size(); ++i) {
            bool destroyed = false;
            while (!ans.empty() && asteroids[i] < 0 && ans.back() > 0) {
                if (abs(ans.back()) < abs(asteroids[i])) {
                    ans.pop_back();
                    continue;
                } else if (abs(ans.back()) == abs(asteroids[i])) {
                    ans.pop_back();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                ans.push_back(asteroids[i]);
            }
        }

        return ans;
    }
};
