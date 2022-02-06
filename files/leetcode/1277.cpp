#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rowSize = matrix.size(), colSize = matrix[0].size();
        vector<vector<int>> result(rowSize, vector<int>(colSize));
        int ans = 0;
        for (int i = 0; i < colSize; ++i) {
            result[0][i] = matrix[0][i];
            ans += result[0][i];
        }
        for (int i = 1; i < rowSize; ++i) {
            result[i][0] = matrix[i][0];
            ans += result[i][0];
        }
        for (int i = 1; i < rowSize; ++i) {
            for (int j = 1; j < colSize; ++j) {
                if (matrix[i][j]){
                    result[i][j] = min(result[i-1][j-1], min(result[i][j-1], result[i-1][j])) + 1;
                }
                else{
                    result[i][j] = 0;
                }
                ans += result[i][j];
            } 
        }
        return ans;
    }
}solution;


int main(){
    vector<vector<int> > test = {{1, 1, 0}, {1, 1, 0}};
    cout << solution.countSquares(test) << endl;
    return 0;
}