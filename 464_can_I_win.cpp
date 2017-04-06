#include <iostream>
#include <vector>
#include <unordered_map>

#include <cassert>

// use id = int of bitset of numbers
// keep map<int, bool> restore when enter state, win or not

using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        cache.clear();
        cout << "Starting choose: " << maxChoosableInteger << ", target: " << desiredTotal << endl;
        selected.resize(maxChoosableInteger, false);
        int sum = (1+maxChoosableInteger)*maxChoosableInteger/2;
        if (sum < desiredTotal) return false;
        return desiredTotal <= 0 || helper(desiredTotal);
    }
private:
    vector<bool> selected;
    unordered_map<int, bool> cache;

    bool helper(int remain){
        if (remain <= 0)    return false;
        int id = bitset2int(selected);
        cout << "\tGetting id: " << id << endl;
        if (cache.find(id) == cache.end()){
            for (int i=0; i<selected.size(); ++i){
                if (!selected[i]){
                    selected[i] = true;
                    if (!helper(remain - (i+1))){
                        cache[id] = true;
                        selected[i] = false;
                        return true;
                    }
                    selected[i] = false;
                }
            }
            cache[id] = false;
        }
        return cache[id];
    }
    int bitset2int(vector<bool>& selected){
        int res = 0;
        for (int i=0; i<selected.size(); ++i){
            if (selected[i])    res |= (1<<i);
        }
        return res;
    }
};

int main(){
    Solution sol;
    int choose1 = 10, desired = 11;
    assert (sol.canIWin(choose1, 11) == false);
    assert (sol.canIWin(choose1, 10) == true);
    assert (sol.canIWin(choose1, 35) == true);
    assert (sol.canIWin(choose1, 40) == false);
    return 0;
}
