class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int id    = 0; //0, 1, 2, 3
        int top   = 0;
        int down  = n-1;
        int left  = 0;
        int right = n-1;
        int val=1;
        
        
        while(top <= down && left <= right ) {
            if(id == 0) { //left to right
                for(int i = left;  i <= right; i++) {
                    matrix[top][i] = val;
                    val++;
                    
                }
                top++;
            }

            if(id == 1) { //top to down
                for(int i = top; i <= down; i++) {
                    matrix[i][right] = val;
                    val++;
                    
                }
                right--;
            }

            if(id == 2) { //right to left
                for(int i = right; i >= left; i--) {
                    matrix[down][i] = val;
                    val++;
            
                }
                down--;
            }

            if(id == 3) { //down to top
                for(int i = down;  i >= top; i--) {
                    matrix[i][left] =val;
                    val++;
                    
                }
                left++;
            }

            id = (id+1)%4; //0, 1, 2, 3
        }

        return matrix;
        
        
    }
};
