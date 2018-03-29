#include <iostream>
#include <vector>
#include <map>

using namespace std;
// return number of pairs where nums[i] > 2*nums[j], i < j
/*
// 1. BST
class BST{
    struct Node{
        Node(long v, long c) : m_val(v), m_cnt(c){}
        long m_val{0}, m_cnt{0};
        Node* m_left{nullptr}, *m_right{nullptr};
    };
public:
    Node* insert(Node* cur, long num)
    {
        if (cur == nullptr) return new Node(num, 1);
        if (cur->m_val == num) 
        {
            ++cur->m_cnt;
        }
        else if (num < cur->m_val)
        {
            cur->m_left = insert(cur->m_left, num);
        }
        else
        {
            ++cur->m_cnt;
            cur->m_right = insert(cur->m_right, num);
        }
        return cur;
    }
    // return number of nodes larger than num
    int search(Node* cur, long num)
    {
        if (cur == nullptr) return 0;
        if (cur->m_val > num) return cur->m_cnt + search(cur->m_left, num);
        return search(cur->m_right, num);
    }
    Node* m_root{nullptr};
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0;
        BST bst;
        for (const auto num:nums)
        {
            res += bst.search(bst.m_root, 2*(long)num);
            cout << num << ":" << res << endl;
            bst.m_root = bst.insert(bst.m_root, num);
        }
        return res;
    }
};

// 2. BIT
//    a. sort nums
//    b. build BIT using index of sorted array
class Solution {
private:
    vector<int> bit;
    void insert(int i)
    {
        while (i > 0)
        {
            bit[i] += 1;
            i &= (i-1);
        }
    }

    int search(int i)
    {
        int res = 0;
        while (i < bit.size())
        {
            res += bit[i];
            i += i & (-i);
        }
        return res;
    }
public:
    int index(const vector<int>& nums, long target)
    {
        // find lower bound
        int l=0, r=nums.size()-1;
        while(l < r)
        {
            int m = l + ((r-l)>>1);
            if (nums[m]>=target)   r = m;
            else l = m+1;
        }
        int res = nums[l] >= target ? l+1:l+2;
        cout << res << ", " << target << endl;
        return l+1;
    }
    int reversePairs(vector<int>& nums) {
        auto sorted = nums;
        sort(sorted.begin(), sorted.end());
        bit.resize(nums.size()+1, 0);
        int res = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            res += search(index(sorted, (long)2*(long)nums[i]+1));
            insert(index(sorted, nums[i])); 
        }
        return res;
    }
};
*/

// Method 3: merge sort
class Solution {
public:
    int mergeHelper(vector<int>& nums, int l, int r)
    {
        if (l >= r) return 0;
        int mid = (l+r)/2;
        int res = mergeHelper(nums, l, mid) + mergeHelper(nums, mid+1, r);
        // merge two sub sectioin
        vector<int> sorted(r-l+1, 0);
        // 1. find all nums[l] > nums[j]*2
        // 2. merge two lists
        int i=l, j=mid+1, k=l, cur=0;
        while (j <= r)
        {
            while (k <= mid && nums[k] <= 2*(long)nums[j])    ++k;
            res += mid+1-k;
            while (i <= mid && nums[i] < nums[j]) sorted[cur++] = nums[i++];
            sorted[cur++] = nums[j++];
        }
        while (i <= mid) sorted[cur++] = nums[i++];
        copy(sorted.begin(), sorted.end(), nums.begin()+l);
        return res;
    }
    int reversePairs(vector<int>& nums) {
        int res = mergeHelper(nums, 0, nums.size()-1);
        for (auto n:nums)
        {
            cout << n << " ";
        }
        cout << endl;
        return res;
    }
};

int main()
{
    //vector<int> nums = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
    //vector<int> nums = {5,4,3,2,1};
    vector<int> nums = {1,3,2,3,1};
    Solution sol;
    auto res = sol.reversePairs(nums);
    cout << res << endl;
}
