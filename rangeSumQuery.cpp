#include <iostream>
#include <vector>

// Two solutions, A: segment tree, B: Binary Index Tree
// Here, we choose segment tree
// 1. Leaf Nodes are the elements of the input array
// 2. Each internal node represents merging of leaves.
// 
// The segment tree is a full binary tree, n leaves + (n-1) inner = 2*n-1 nodes
// So the height of the tree should be log(2*n)+1, the size should be 2*(logn

using namespace std;

class NumArray{
public:
    class node{
    public:
        int start_{0}, end_{0};
        int sum_{0};
        shared_ptr<node> left_{nullptr}, right_{nullptr};
        node(int start, int end, int sum) : start_(start), end_(end), sum_(sum) {}
    };

    NumArray(vector<int> nums){
        nums_ = move(nums);
        root_ = buildTree(0, nums_.size() -1);
    }
    
    void update(int i, int val){
        int diff = val - nums_[i];
        nums_[i] = val;
        updateHelper(root_, i, diff);
    }

    int sumRange(int i, int j){
        return sumRangeHelper(root_, i, j);
    }
    
    // debug helper //
    void print(){
        if (root_ != nullptr){
            vector<shared_ptr<node>> q;
            q.push_back(root_);
            while (!q.empty()){
                vector<shared_ptr<node>> nx;
                for (auto ptr:q){
                    cout << "start: " << ptr->start_ << ", end: " << ptr->end_ << ", sum: " << ptr->sum_ << "       ";
                    if (ptr->left_ != nullptr) nx.push_back(ptr->left_);
                    if (ptr->right_ != nullptr) nx.push_back(ptr->right_);
                }
                cout << endl;
                q = nx;
            }
        }  
        return;
    }
private:
    vector<int> nums_;
    shared_ptr<node> root_{nullptr};

    // build the segment tree
    // return the tree node for range[start, end]
    shared_ptr<node> buildTree(int start, int end){
        auto cur = make_shared<node>(start, end, 0);
        if (end <= start){
            cur->sum_ = nums_[start];
            return cur;
        }
        
        // update left&right sub tree
        int mid = (start + end) >> 1;
        cur->left_ = buildTree(start, mid);
        cur->right_ = buildTree(mid+1, end);
        
        // update sum of current
        cur->sum_ = cur->left_->sum_ + cur->right_->sum_;

        return cur;
    }

    // update sum in the segment tree
    void updateHelper(shared_ptr<node> cur, int i, int diff){
        if (cur == nullptr){
            return;
        }
        if (cur->start_ <= i && cur->end_ >= i) {
            cur->sum_ += diff; 
            updateHelper(cur->left_, i, diff);
            updateHelper(cur->right_, i, diff);
        }
        return;
    }

    // helper for return sum in range[i, j]
    int sumRangeHelper(shared_ptr<node> cur, int i, int j){
        // if !cur || cur is not in range
        if (cur == nullptr || cur->start_ > j || cur->end_ < i){
            return 0;
        }

        // if cur is inside range
        if (i <= cur->start_ && j >= cur->end_){
            return cur->sum_;
        }

        return sumRangeHelper(cur->left_, i, mid) + sumRangeHelper(cur->right_, i, j);
    }

};

int main(){
    vector<int> nums={7, 2, 7, 2, 0};
    NumArray na(nums);
    na.print();
    na.update(4,6);
    na.print();
    na.update(0,2);
    na.print();
    na.update(0,9);
    na.print();
    cout << "Range[4,4] is " << na.sumRange(4,4) << endl;
    na.update(3,8);
    cout << "Range[0,4] is " << na.sumRange(0,4) << endl;
    na.update(4,1);
    cout << "Range[0,3] is " << na.sumRange(0,3) << endl;
    return 0;
}
