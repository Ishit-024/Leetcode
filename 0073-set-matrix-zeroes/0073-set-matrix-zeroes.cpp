class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>rows;
        unordered_set<int>columns;
        int row_size=matrix[0].size();
        int col_size=matrix.size();
        for(int i=0;i<matrix[0].size();i++){
            for(int j=0;j<matrix.size();j++){
                if(matrix[j][i]==0){
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for(int row:rows){
            for(int j=0;j<matrix.size();j++){
                matrix[j][row]=0;
            }
        }
        for(int col:columns){
            for(int j=0;j<matrix[0].size();j++){
                matrix[col][j]=0;
            }
        }
            }
};