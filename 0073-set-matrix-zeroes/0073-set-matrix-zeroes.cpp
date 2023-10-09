class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    vector<bool> rowZero(n, false);
    vector<bool> colZero(m, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                rowZero[i] = true;
                colZero[j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (rowZero[i]) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = 0;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        if (colZero[j]) {
            for (int i = 0; i < n; i++) {
                arr[i][j] = 0;
            }
        }
    }
    }
};