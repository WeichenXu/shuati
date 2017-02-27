#include <iostream>
#include <vector>

// 1. Maintain a possible celebrity list

using namespace std;

//bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<bool> people(n, true);
        int cel;
        // 1. find a possible candidate, check who he knows
        while ( (cel = findCandidate(people)) != -1 ){
            // if everyone know him
            bool allKnown = true;
            for (int i=0; i<n; ++i){
                if (i == cel)   continue;
                if (!knows(i, cel)){
                    allKnown = false;
                    break;
                }
                people[i] = false;
            }
            // if he doesnt know everyone
            if (allKnown){
                bool knowNone = true;
                for (int i=0; i<n; ++i){
                    if (i == cel)   continue;
                    if (knows(cel, i)){
                        knowNone = false;
                        break;
                    }
                    people[i] = false;
                }
                if (knowNone){
                    return cel;
                }
            }
            people[cel] = false;
        }

        return -1;
    }
private:
    int findCandidate(vector<bool>& people){
        for (int i=0; i<people.size(); ++i){
            if (people[i])  return i;
        }
        return -1;
    }
    bool knows(int a, int b){
        if (b == 1 || a== b){
            return true;
        }
        return false;
    }
};

int main(){
    int n = 10;
    Solution sol;
    auto res = sol.findCelebrity(n);
    cout << "Celebrity is " << res << endl;
    return 0;
}
