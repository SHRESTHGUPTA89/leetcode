class Solution {
public:
    
    // Only the filled cells need to be validated according to the mentioned rules.
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_set<int>>row(9), col(9), subMat(9); // 9 subMatrices numbered from 0 to 8
        
        // To get subMatrix number corresponding to (i,j) = (4,7)
        // formula (i/3)*3+j/3 = (4/3)*3+7/3 = 3+2 = 5    
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                if(board[i][j]!='.')
                {
                    int val = (board[i][j]-'0');
                    
                    if(row[i].count(val) or col[j].count(val) or subMat[(i/3)*3 + j/3].count(val))
                        return false;
                    
                    row[i].insert(val);
                    col[j].insert(val);
                    subMat[(i/3)*3+j/3].insert(val);
                }
            }
        }
        return true;
    }
};