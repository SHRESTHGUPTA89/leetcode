class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // Use long long to avoid overflow
        long long currentMass = mass;

        // Sort the asteroids to handle them in ascending order of mass
        sort(asteroids.begin(), asteroids.end());

        for (int asteroid : asteroids) {
            if (currentMass >= asteroid) {
                currentMass += asteroid;  // Increase the mass by the mass of the destroyed asteroid
            } else {
                return false;  // If the current mass cannot destroy the asteroid, return false
            }
        }

        return true;  // If all asteroids are destroyed, return true
    }
};
