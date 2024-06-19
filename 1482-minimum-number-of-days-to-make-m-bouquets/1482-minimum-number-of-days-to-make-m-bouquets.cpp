class Solution {
public:

    int possible(const std::vector<int>& arr, int k, int mid) {
    int n = arr.size();
    int count = 0;
    int countans = 0;

    for (int i = 0; i < n; i++) {
        if (mid >= arr[i]) {
            count++;
        } else {
            countans += (count / k);
            count = 0;
        }
    }

    countans += (count / k);
    return countans;
}
    int minDays(vector<int>& arr, int m,int k) {


    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); // size of the array
    if (val > n) return -1; // impossible case
    int e = *max_element(arr.begin(), arr.end());
    int s = *min_element(arr.begin(), arr.end());

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (possible(arr, k, mid) >= m) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return s;
}

};