class Solution {
public:
    int minimumPushes(string word) 
    {
        int n=word.size();
        int cnt1=0,cnt2=0;
        string s=word;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='1'||s[i]=='#'||s[i]=='0'||s[i]=='*') cnt1++;
            else cnt2++;
        }
        if(cnt2<=8)
        {
            return cnt1+cnt2;
        }
        else if(cnt2>8 and cnt2<=16)
        {
            return cnt1+8+(cnt2-8)*2;
        }
        else if(cnt2>16 and cnt2<=24)
        {
            return cnt1+8+16+(cnt2-16)*3;
        }
        else if(cnt2>=24 and cnt2<=26)
        {
            return cnt1+8+16+24+(cnt2-24)*4;
        }
        return 0;
        
    }
};