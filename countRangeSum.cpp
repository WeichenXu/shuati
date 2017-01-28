#include <iostream>
#include <vector>

using namespace std;

// Two solution bases
// 1. merge sort based
// 2. balanced binary search tree

// replace the int with long for overflow cases
class Solution{
public:
    int countRangeSum(vector<int>& nums, int lower, int higher){
        int len = nums.size();
        vector<int> sums(len+1, 0);

        // calculate the sums[i] = sum[0, i)
        for (int i=1; i<=len; ++i){
            sums[i] = nums[i-1] + sums[i-1];
        }

        return merge(sums, 0, len, lower, higher);
    }
private:
    // sums[i] = sum[0, i)
    // sum[i, j] = sums[j+1] - sums[i]
    int merge(vector<int>& sums, int start, int end, int lower, int higher){
        // the base case, j > i
        if (end <= start){
            return 0;
        }

        int mid = (start + end) >> 1;
        int count = merge(sums, start, mid, lower, higher) + merge(sums, mid+1, end, lower, higher);

        cout << "Sub solution, from start:" << start << " to end:" << end << ", " << count << "solutions" << endl;
        for (auto sum:sums){
            cout << sum << " ";
        }
        cout << endl;
        // iterate all solution with [l, mid] + [mid, r]
        // store the newly sorted array
        int k = mid+1, j = mid+1, len=end-start+1, r = mid+1, curL = 0;
        vector<int> array(len, 0);
        for (int l=start; l<=mid; ++l, ++curL){
            // find the first k sum[k] - sum[l] >= lower
            while(k <= end && (sums[k] - sums[l]) < lower){
                ++k;
            }
            cout << "start is " << l << ", low is " << k;
            // find the first j sum[j] - sum[l] > higher
            while(j <= end && (sums[j] - sums[l]) <= higher){
                ++j;
            }
            cout << ", high is " << j << endl;
            // copy the right array, who are < sums[l]
            while(r <= end && sums[r] < sums[l]){
                array[curL++] = sums[r++];
            }
            count += j-k;
            array[curL] = sums[l];
        }
        cout << "With mid solution, from start:" << start << " to end:" << end << ", " << count << "solutions" << endl;

        // copy the merged array to sums
        copy(array.begin(), array.begin()+curL, sums.begin()+start);

        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {-2, 5, -1};
    cout << "Ans: " << sol.countRangeSum(nums, -2, 2) << endl;
    return 0;
}
