class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        priority_queue<pair<double,int>>max_heap;

        int n = classes.size();

        for(int i=0 ; i<n ; i++)
        {
            int pass = classes[i][0];
            int total = classes[i][1];

            double passRatio = double(pass)/total;

            int newpass = pass + 1;
            int newtotal = total + 1;

            double newPassRatio = double(newpass)/newtotal;

            max_heap.push({newPassRatio-passRatio,i});
        }

        while(extraStudents)
        {
            pair<double,int>top = max_heap.top();
            max_heap.pop();

            int i = top.second;
            classes[i][0] = classes[i][0] + 1;
            classes[i][1] = classes[i][1] + 1;

            double passRatio = double(classes[i][0])/classes[i][1];

            int newpass = classes[i][0] + 1;
            int newtotal = classes[i][1] + 1;

            double newPassRatio = double(newpass)/newtotal;

            max_heap.push({newPassRatio-passRatio,i});

            extraStudents--;
        }

        double sum = 0;

        for(int i=0;i<classes.size();i++)
        {
            sum+=(double)classes[i][0]/(double)classes[i][1];
        }
        return sum/(double)classes.size();
    }
};
