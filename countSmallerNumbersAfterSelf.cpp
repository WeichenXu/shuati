#include <iostream>
#include <vector>
#include <memory>

// 1. use binary search tree 
//    each node restore the count of num smaller than itself
//    and the value it stored

using namespace std;

class Solution{
public:
    class node{
    public:
        int val_{0};
        int count_{0};
        shared_ptr<node> left_{nullptr}, right_{nullptr};
        node(int val, int count):val_(val),count_(count){}
    };

    vector<int> countSmaller(vector<int>& nums){
        //insert the nums from back to begin
        int len = nums.size();
        vector<int> small(len, 0);
        for (int i=len-1; i>=0; --i){
            small[i] = insert(nums[i], 0, root_);
        }
        return small;
    }

private:
    shared_ptr<node> root_{nullptr};

    // insert the node into the binary search tree and update the count
    // return the count of number < val
    int insert(int val, int count, shared_ptr<node>& cur){
        if(cur == nullptr){
            cur = make_shared<node>(val, 1);
        }
        else{
            if (val <= cur->val_){
                ++cur->count_;
                count += insert(val, count, cur->left_);
            }
            else{
                count += cur->count_ + insert(val, count, cur->right_);
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums={5,2,6,1};
    auto res = sol.countSmaller(nums);
    for (auto n:res){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
