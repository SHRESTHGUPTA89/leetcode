class Solution {
public:
    bool isPossible(vector<int>& ranks, long long cars, long long time)  {
        long long cnt = 0;
        
        for(auto it : ranks)   {
            
            cnt += sqrt(time / it);
            
            if(cnt >= cars) return true;
            
        }
        return cnt >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long s=0;
        long long e=ranks[0]*1LL*cars*cars ,   ans = e;
        
        while(s <= e)   {
            long long mid = s + (e - s) / 2;
            
            if(isPossible(ranks, cars, mid))    {
                ans = mid;
                e = mid - 1;
            }
            
            
            else   { 
                
                s = mid + 1;
            }
        }
        return ans;
    }
};
