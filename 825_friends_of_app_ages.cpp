class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int count[121] = {0};
        for (int age:ages) count[age]++;
        int res = 0;
        for (int i=1; i<=120; ++i)
        {
            int tmp = count[i];
            count[i] += count[i-1];
            if (i>14)
            {
                int pre = i/2+7;
                res += tmp*(count[i]-count[pre]-1);
            }
        }
        return res;
    }
};
