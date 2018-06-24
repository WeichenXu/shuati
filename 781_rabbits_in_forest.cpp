class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int count[1000] = {0}, res = 0;
        for (int i:answers)
        {
            if (count[i])   --count[i];
            else 
            {
                res += i+1;
                count[i] = i;
            }
        }
        return res;
    }
};
