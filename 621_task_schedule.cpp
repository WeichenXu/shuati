#include <iostream>
#include <vector>

using namespace std;

// we only need to consider most-frequent elements
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sum = tasks.size();
        vector<int> slots(26, 0);
        for (const auto t : tasks)
        {
            slots[t-'A']++;
        }
        sort(slots.begin(), slots.end());
        int max = slots[25];
        int count =1;
        for (int i=24; i>=0; --i)
        {
            if (slots[i] == max)
            {
                ++count;
            }
            else
            {
                break;
            }
        }
        int idle = (max-1)*n;
        int remain = sum - max - count + 1;
        idle = ::max(0, idle - remain);
        return sum + idle;
    }
};

int main()
{
    Solution sol;
    vector<char> tasks = {'A','A','A','B','B','B'};
    auto res = sol.leastInterval(tasks, 2);
    cout << res << endl;
    return 0;
}
