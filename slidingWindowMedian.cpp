#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

// 1. use two priority_queue
// 2. use multiset

using namespace std;

class Solution{
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        // used containers
        priority_queue<int, vector<int>> smaller;
        priority_queue<int, vector<int>, greater<int>> larger;
        unordered_map<int, int> toRemove;
        vector<double> result;

        int len = nums.size();
        if (len < k){
            return result;
        }
        // initial status
        int i=0;
        while(i < k){
            smaller.push(nums[i++]);
        }
        for(int j=0; j<k/2; ++j){
            larger.push(smaller.top());
            smaller.pop();
        }
        while(true){
            // push the updated result
            if (k%2){
                result.push_back((double)smaller.top());
            }
            else{
                result.push_back( (double) (larger.top() + smaller.top()) / 2.0);
            }
            if (i == len){
                break;
            }

            int prev = nums[i-k], cur = nums[i++];
            int toBalance = 0;
            // update the balance for the prev
            if (!smaller.empty() && prev <= smaller.top()){
                ++toBalance;
                if (prev == smaller.top()){
                    smaller.pop();
                }
                else{
                    ++toRemove[prev];
                }
            }
            else{
                --toBalance;
                if (!larger.empty() && prev == larger.top()){
                    larger.pop();
                }
                else{
                    ++toRemove[prev];
                }
            }

            // update the balance for the cur
            if (!smaller.empty() && cur <= smaller.top()){
                --toBalance;
                smaller.push(cur);
            } 
            else{
                ++toBalance;
                larger.push(cur);
            } 

            // balance the top of two heaps
            if (toBalance > 0){
                smaller.push(larger.top());
                larger.pop();
            }
            else if (toBalance < 0){
                larger.push(smaller.top());
                smaller.pop();
            }

            // remove the top heaps as much as possible
            while(!smaller.empty() && toRemove[smaller.top()]){
                --toRemove[smaller.top()];
                smaller.pop();
            }
            while(!larger.empty() && toRemove[larger.top()]){
                --toRemove[larger.top()];
                larger.pop();
            }
        } 
        return result;
    }
};

int main(){
    Solution sol;
    //vector<int> nums = {8, 3, 8, 1, 5, 3, 5, 4};
    vector<int> nums = {7, 8, 8, 3, 8, 1, 5, 3, 5, 4};
    int k = 3;
    auto res = sol.medianSlidingWindow(nums, k);
    for (auto r:res){
        cout << r << "   ";
    }
    cout << endl;
    return 0;
}
