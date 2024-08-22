class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        
    int n=arr.size();
    int K=0;
        
	vector<vector<int>> ans;
	sort(arr.begin() , arr.end());

	set<vector<int>> temp;

	for(int i= 0 ; i < n-2 ; i++){
		int j = i+1 , k = n-1;
		while(j<k){
			int sum = arr[i] + arr[j] + arr[k];
			if(sum == K){
				temp.insert({arr[i] , arr[j] , arr[k]});
				j++; k--;
			}
			else if(sum<K)	j++;
			else k--;
		}
	}
	for(auto i : temp){
		ans.push_back(i);
	}
	return ans;


        
    }
};