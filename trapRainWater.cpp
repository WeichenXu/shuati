#include <iostream>
#include <vector>

// use two pointers

using namespace std;

class Solution{
public:

    int trap(vector<int>& height){
        int i=0, j=height.size()-1;
        int leftMax = 0, rightMax = 0;
        int rain = 0;
        
        while(i <= j){
            int cur = 0;
            leftMax = max(leftMax, height[i]);
            rightMax = max(rightMax, height[j]);
            if (height[i] < height[j]){
                cur = height[i];
                ++i;
            }            
            else{
                cur = height[j];
                --j;
            }
            rain += max(0, min(leftMax, rightMax) - cur);
        }
        return rain;
    }

};

int main(){
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trap: " << sol.trap(height) << endl;
    return 0;
}
