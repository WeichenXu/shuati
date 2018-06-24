class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        const int size = A.size();
        for (int i=1; i<size-1; ++i)
        {
            if (A[i] > A[i-1] and A[i] > A[i+1])    return i;
        }
        return -1;
    }
};
