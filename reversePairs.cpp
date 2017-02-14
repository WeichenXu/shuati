#include <iostream>
#include <vector>
#include <memory>

// 1. use bst, each node store val and count of number <= val
// 2. query the current val, insert val*2

using namespace std;

class Solution{
public:
    class node{
    public:
        long val{0};
        int smaller{0};
        shared_ptr<node> left{nullptr}, right{nullptr};
        node(long v, int s):val(v), smaller(s){}
    };

    int reversePairs(vector<int>& nums){
        int res = 0;
        // query and insert in reverse order
        for (auto it = nums.rbegin(); it != nums.rend(); ++it){
            res += query(*it);
            root = insert(root, 2*(*it));
        }
        return res;
    }

private:
    shared_ptr<node> root;
    //-- utility function --/
    int query(long val) const{
        auto cur = root;
        int count = 0;
        while(cur != nullptr){
            long curV = cur->val;
            if (val <= curV){
                cur = cur->left;
            }
            else{
                count += cur->smaller;
                cur = cur->right;
            }
        }
        return count;
    }

    shared_ptr<node> insert(shared_ptr<node> cur, long val){
        if (cur == nullptr){
            return make_shared<node>(val, 1);
        }
        long curV = cur->val;
        if (val <= curV){
            ++cur->smaller;
            cur->left = insert(cur->left, val);
        }
        else{
            cur->right = insert(cur->right, val);
        }
        return cur;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 4, 3, 5, 1};
    auto res = sol.reversePairs(nums);
    cout << "Find " << res << " reverse pairs." << endl;
    return 0;
}
