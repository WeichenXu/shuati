#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 1. binary search, find lower bound
        // 2. two pointers, extend
        int left = 0, right = arr.size() - 1;
        while (left < right)
        {
            int mid = (left+right)/2;
            if (arr[mid] >= x)
            {
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        vector<int> res;
        if (not k){
            return res;
        }
        int i,j; 
        if (left-1 < 0 || abs(arr[left-1])-x > abs(arr[left]-x))
        {
            i = j = left;
        }
        else
        {
            i = j = left-1;
        }
        --k;
        while (k)
        {
            --k;
            if (i-1 >=0 && j+1 < arr.size())
            {
                int lNum = arr[i-1], rNum = arr[j+1];
                if (abs(lNum-x) <= abs(rNum-x))
                {
                    --i;
                }
                else
                {
                    ++j;
                }
            }
            else if (i-1>=0)
            {
                --i;
            }
            else
            {
                ++j;
            }
        }
        return vector<int>(arr.begin()+i, arr.begin()+j+1);
    }
};

int main()
{
    vector<int> arr = {1,2,3,4,5};
    int k = 4, x = 10;
    Solution sol;
    auto res = sol.findClosestElements(arr, k, x);
    for (auto r:res)
    {
        cout << r << " " ;
    }
    cout << endl;
}
