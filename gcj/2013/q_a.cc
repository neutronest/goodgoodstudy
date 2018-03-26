#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    void solve(vector<string> board, int t) {
        int res = 0;
        int flag = 0;
        // check each row
        std::string s = "";
        for (int r=0; r<4; r++) {
            s = board[r];
            flag = isOver(s);
            if (flag != 0) {
                res = flag;
            }
        }
        // check each column
        for(int c=0; c<4; c++) {
            s = "";
            for (int r=0; r<4; r++) {
                s += board[r][c];
                
            }
            flag = isOver(s);
            if (flag != 0) {
                res = flag;
            }
        }
        // check diagonal
        s = "";
        for(int i=0; i<4; i++) {
            s += board[i][i];
        }
        flag = isOver(s);
        if (flag != 0) {
            res = flag;
        }
        s = "";
        for(int i=3; i>=0; i--) {
            s += board[i][3-i];
        }
        flag = isOver(s);
        if (flag != 0) {
            res = flag;
        }
        if (res == 1) {
            cout<<"Case #"<<t+1<<": "<<"X won"<<endl;
            return;
        } else if (res == -1) {
            cout<<"Case #"<<t+1<<": "<<"O won"<<endl;
            return;
        } else {
            // check if draw or uncompleted
            for(int r=0; r<4; r++) {
                for(int c=0; c<4; c++) {
                    if (board[r][c] == '.') {
                        cout<<"Case #"<<t+1<<": Game has not completed"<<endl;
                        return;
                    }
                }
            }
            cout<<"Case #"<<t+1<<": Draw"<<endl;
            return;
        }
    }

    int isOver(string str) {
        if (str.length() != 4) {
            //cout<<"What?"<<endl;
            return 0;
        }

        int playFlag = 0;
        for (int i=0; i<str.length(); i++) {
            char c = str[i];
            if (c == '.') {
                return false;
            } else if (c == 'X') {
                if (playFlag == -1) {
                    // exist 'O', conflict
                    return 0;
                }
                playFlag = 1;
            } else if (c == 'O') {
                if (playFlag == 1) {
                    // exist 'X', conflict
                    return 0;
                }
                playFlag = -1;
            } else {
                // c == 'T'
            }
        }
        return playFlag;
    }

};





int main() {
    int T;
    cin>>T;
    Solution solution = Solution();
    vector<string> board = {};
   
    for (int t=0; t<T; t++) {
        board.clear();
        for(int i=0; i<4; i++) {
            string str;
            cin>>str;
            board.push_back(str);
        }
        solution.solve(board, t);
    }
    return 0;
}