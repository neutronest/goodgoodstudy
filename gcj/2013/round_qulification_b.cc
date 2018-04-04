#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

bool solve(int rows, int cols, vector<vector<int>> mat) {

    vector<vector<int>> oriMat(rows, vector<int>(cols, 100));
    int maxVal = -1;
    for (auto r = 0; r < rows; r++) {
        maxVal = -1;
        for(auto i=0; i<cols; i++) {
            if (maxVal < mat[r][i]) {
                maxVal = mat[r][i];
            }
        }
        for(auto i=0; i<cols; i++) {
            if (oriMat[r][i] > maxVal) {
                oriMat[r][i] = maxVal;
            }
        }
    }
    for (auto c = 0; c < cols; c++) {
        maxVal = -1;
        for(auto i=0; i<rows; i++) {
            if (maxVal < mat[i][c]) {
                maxVal = mat[i][c];
            }
        }
        for(auto i=0; i<rows; i++) {
            if (oriMat[i][c] > maxVal) {
                oriMat[i][c] = maxVal;
            }
            
        }
    }

    for (auto i=0; i<rows; i++) {
        for(auto j=0; j<cols; j++) {
            if (oriMat[i][j] != mat[i][j]) {
                return false;
            }
        }
    }

    return true;

}

bool isValid(int r, int c, vector<vector<int>> mat) {

    int rows = mat.size();
    int cols = mat[0].size();
    vector<int> neibourHeights;

    // check up value if exists
    if (r > 0) {
        neibourHeights.push_back(mat[r-1][c]);
    }
    // check down value if exists
    if (r < rows-1) {
        neibourHeights.push_back(mat[r+1][c]);
    }
    // check left value is exists
    if (c > 0) {
        neibourHeights.push_back(mat[r][c-1]);
    }
    if (c < cols-1) {
        neibourHeights.push_back(mat[r][c+1]);
    }
    int biggerAcc = 0;
    for (auto i=0; i < neibourHeights.size(); i++) {
        if (mat[r][c] > neibourHeights[i]) {
            biggerAcc += 1;
        }
    }
    return biggerAcc > 0;
}

};

int main() {

    int T;
    int n, m;
    int case_idx = 0;
    int h;
    vector<vector<int>> mat;
    Solution solution = Solution();
    cin>>T;
    while (case_idx < T) {
        mat.clear();
        cin>>n>>m;
        for(auto i=0; i<n; i++) {
            vector<int> temp;
            for(auto j=0; j<m; j++) {
                cin>>h;
                temp.push_back(h);
            }
            mat.push_back(temp);
        }
        bool res = solution.solve(n, m, mat);
        if (res) {
            cout<<"Case #"<<(case_idx+1)<<": YES"<<endl;
        } else {
            cout<<"Case #"<<(case_idx+1)<<": NO"<<endl;
        }
        case_idx += 1;
    }
}