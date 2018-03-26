#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(long long n, long long r, long long t) {
        long long cur_cost = n * (2 * n +  2 * r - 1);
        bool res = false;
        if (cur_cost > t) {
            res = false;
        } else {
            res = true;
        }
        return res;
    }

    long long solve(long long r, long long t) {
        long long left = 0;
        long long right = 1;
        long long res = 0;
        //cout<<"right "<<right<<endl;
        while (isValid(right, r, t)) {
            //cout<<"right "<<right<<endl;
            left = right;
            right *= 2;
        }
        // binary search on [left, right)
        long long mid;
        while (right - left > 1) {
            mid = (left + right) / 2;
            if (isValid(mid, r, t)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        res = left;
        return res;
    }
};


int main() {
    int T;
    cin>>T;
    int case_id = 0;
    long long r,t;
    long long res;
    Solution solution = Solution();
    while (case_id < T) {
        r = 0;
        t = 0;
        cin>>r>>t;
        res = solution.solve(r, t);
        cout<<"Case #"<<(case_id+1)<<": "<<res<<endl;
        case_id += 1;
    }
    return 0;
}