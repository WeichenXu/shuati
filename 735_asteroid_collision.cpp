class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (const auto as:asteroids)
        {
            bool insert = as != 0;
            if (as < 0)
            {
                while (not s.empty())
                {
                    int pre = s.top();
                    if (pre < 0) break;
                    else if (abs(pre) < abs(as))    s.pop();
                    else 
                    {
                        if (abs(pre) == abs(as))
                        {
                            s.pop();
                        }
                        insert = false;
                        break;
                    }
                }
            }
            if (insert) s.push(as);
        }
        vector<int> res;
        while (not s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
