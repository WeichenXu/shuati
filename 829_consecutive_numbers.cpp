class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int count = 0;
        for (int k=1; k<sqrt(N); ++k)
        {
            if ((N-k*(k-1)/2)%k == 0)   ++count;
        }
        return count;
    }
};
