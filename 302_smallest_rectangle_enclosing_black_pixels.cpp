#include <iostream>
#include <vector>

// Use binary search to locate the range of rectangle
// For column range, binary search in two halves, [0, y] & [y, end] == O(lgr)
//     search the entire col, O(c)
// For row range, vice versa
//
// Time complexity = O(rlgc) + O(clgr)

using namespace std;

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        row = image.size();
        if (!row)
            return 0;
        col = image[0].size();

        int top, bottom, left, right;
        top = binarySearchHelper(image, 0, x, 0, true, 0, col-1);
        cout << "\t top:" << top << endl;
        bottom = binarySearchHelper(image, x, row, 0, false, 0, col-1);
        cout << "\t bottom:" << bottom << endl;
        left = binarySearchHelper(image, 0, y, 1, true, top, bottom-1);
        cout << "\t left:" << left << endl;
        right = binarySearchHelper(image, y, col, 1, false, top, bottom-1);
        cout << "\t right:" << right << endl;
        return (right-left)*(bottom-top);
    }

private:
    /**
     * Search the boundary in range[@lo, @hi]
     * toSearch: 0 == row, 1 == col
     * target: 0 == white, 1 == black
     */
    int binarySearchHelper(vector<vector<char>>& image, int lo, int hi, int toSearch, bool option, int start, int end){
        while(lo < hi){
            int mid = ( (lo + hi) >> 1 );
            bool containOne = false;
            for (int i=start; i<=end; ++i){
                int cur = toSearch ? image[i][mid] : image[mid][i];
                if(cur == '1'){
                    containOne = true;
                    break;
                }
            }
            if (containOne == option){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        return lo;
    }

    int row{0}, col{0};
};

int main(){
    vector<vector<char>> images = {
        {'0', '0', '1', '0'},
        {'0', '1', '1', '0'},
        {'0', '1', '0', '0'},
        //{'0', '0', '0', '0'},
    };
    Solution sol;
    auto res = sol.minArea(images, 1, 2);
    cout << "The area size is: " << res << endl;
    return 0;
}
