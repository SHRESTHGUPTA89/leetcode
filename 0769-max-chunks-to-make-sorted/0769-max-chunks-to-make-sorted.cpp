class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxval=0;
        int chunk=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxval){
                maxval=arr[i];
            }
            if(maxval==i){
                chunk++;
            }
        }
        return chunk;
    }
};