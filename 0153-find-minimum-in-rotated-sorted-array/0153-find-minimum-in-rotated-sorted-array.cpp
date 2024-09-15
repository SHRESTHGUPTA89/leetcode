class Solution {
public:
    
        int findMin(vector<int>& arr)
{
    int n=arr.size();
	int s=0;
	int e=n-1;

	while(s<e){

		int m=s+(e-s)/2;

		if(arr[0]<=arr[m]){
			s=m+1;
		}
		else{
			e=m;
		}
	}
	if(arr[0]<=arr[e]){
		return arr[0];
	}
	return arr[s];
}
    
};