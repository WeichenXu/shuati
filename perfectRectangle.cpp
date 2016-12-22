//1. area sum is right, find the min(row, col), max(row, col)
//2. no overlapping between each pair, O(1) * n^2
//   better, after connected all paired points(corners), there should only be four left
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution{
public:
    bool isRectangleCover(vector<vector<int>>& rectangles){
        // sum the area of small rectangles
        int sum = 0;
        int size = rectangles.size();
        for (const auto&rec : rectangles){
            sum += (rec[2] - rec[0]) * (rec[3] - rec[1]);
            vector<string> curCorners;
            // add NW, NE, SE, SW corners of the rectangle
            curCorners.emplace_back( to_string(rec[2]) + ',' + to_string(rec[1]));
            curCorners.emplace_back( to_string(rec[2]) + ',' + to_string(rec[3]));
            curCorners.emplace_back( to_string(rec[0]) + ',' + to_string(rec[3]));
            curCorners.emplace_back( to_string(rec[0]) + ',' + to_string(rec[1]));
            // remove the corners if matched
            for(auto& cur:curCorners){
                if (corners_.find(cur) != corners_.end()){
                    corners_.erase(cur);
                }
                else{ 
                    corners_.emplace(cur);
                }
            }
        }
        
        //for (const auto&str:corners_){
        //    cout << str << " ";
        //}
        //cout <<endl;
        
        // if the remaining corners are only with size of 4
        // and the area trapped by the corners == sum
        return (corners_.size() == 4 && getCornerArea() == sum);
    }

private:
    // utility function, get the area of the rectangle region of the corners
    int getCornerArea(){
        int xL = INT_MIN, xM = INT_MAX, yL = xL, yM = xM;
        for(auto& cor:corners_){
            int sp = cor.find(",");
            int x =  stoi(cor.substr(0, sp));
            int y =  stoi(cor.substr(sp+1));
            xL = max(xL, x), xM = min(xM, x);
            yL = max(yL, y), yM = min(yM, y);
        }
        return (xL-xM)*(yL-yM);
    }
    unordered_set<string> corners_;
};

int main(){
    Solution sol;
    vector< vector<int> > rectangles = {{1,1,3,3}, {3,1,4,2}, {1,3,2,4},{3,2,4,4}, {2,3,3,4}};
    cout << sol.isRectangleCover(rectangles);
    return 0;
}
