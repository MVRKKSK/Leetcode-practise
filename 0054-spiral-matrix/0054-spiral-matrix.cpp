class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0 , right = m-1;
        int top = 0 , bottom = n-1;
        while(top<=bottom && left<=right){
        for(int j=left;j<=right;j++){
            ans.push_back(matrix[top][j]); //pushing for the right
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);//pushing for down
        }
        right--;
        if(top<=bottom){
        for(int j=right;j>=left;j--){
            ans.push_back(matrix[bottom][j]); //pushing for left
        }
        bottom--;
        }

        if(left<=right){
        for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]); //pushing for up
        }
        left++;
        }

        }
        return ans;
        
    }
};