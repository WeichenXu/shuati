#include <iostream>
#include <vector>
#include <unordered_map>

// 1. fetch all number with num bits
// 2. seperate to hours & mins
// 3. judge if it is valid time

using namespace std;

class Solution{
public:
    vector<string> readBinaryWatch(int num){
        vector<string> res;
        
        int n = (1 << 10);
        int minMask = (1 << 6) - 1;
        for (int i=0; i<n; ++i){
            if (getBits(i) == num){
                int minute = i&minMask, hour = ( i >> 6);
                if (hour < 12 && minute < 60){
                    string time = "";
                    time += to_string(hour) + ":";
                    if (minute < 10){
                       time += "0";
                    }
                    time += to_string(minute);
                    res.push_back(time);
                }
            }
        }

        return res;
    }
private:
    int getBits(int i){
        int count = 0;
        while(i){
            i &= (i-1);
            ++ count;
        }
        return count;
    }
};

int main(){
    Solution sol;
    int num = 1;
    auto times = sol.readBinaryWatch(num);
    cout << "All time for num: " << num << endl;
    for (const auto&t:times){
        cout << t << " ";
    }
    cout << endl;
}
