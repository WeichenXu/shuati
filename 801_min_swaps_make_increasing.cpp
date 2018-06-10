#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        //https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/discuss/119835/Java-O(n)-DP-Solution
        int fixRecord = 0, swapRecord = 1;
        for (int i=1; i<A.size(); ++i)
        {
            if (A[i-1] >= B[i] or B[i-1] >= A[i])   swapRecord++;
            else if(A[i-1] >= A[i] or B[i-1] >= B[i])
            {
                int tmp = swapRecord;
                swapRecord = fixRecord + 1; 
                fixRecord = tmp;
            }
            else
            {
                int nx = min(fixRecord, swapRecord);
                swapRecord = nx+1;
                fixRecord = nx;
            }
        }
        return min(fixRecord, swapRecord);
    }
};
