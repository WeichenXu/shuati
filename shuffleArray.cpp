#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    Solution(vector<int> nums){
        origin_ = move(nums);
    }

    /*reset the array*/
    vector<int> reset(){
        return origin_;
    }

    /*return a random shuffling array*/
    vector<int> shuffle(){
        vector<int> shuffled(origin_.begin(), origin_.end());
        
        // swap each item with a random one
        int size = shuffled.size();
        for (int i=size-1; i>0; --i){
            swap(shuffled[i], shuffled[rand()%(i+1)]);
        }

        return shuffled;
    }
private:
    vector<int> origin_;
};

void print(vector<int>& nums){
    for (auto n:nums){
        cout << n << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums={1, 2, 3};
    Solution sol(nums);

    auto s = sol.shuffle();
    auto ori = sol.reset();
    print(s);
    print(ori);

    return 0;
}
