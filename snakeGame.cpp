#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>
#include <string>

// 1. use linked list to represent the body, unordered_set<int> locate the body pixels
// 2. walk the direction: a. out of boundary, b. hit the body, c. eat the fruit 

using namespace std;

class SnakeGame{
public:
    SnakeGame(int width, int height, vector<pair<int, int>> food){
        food_ = food;
        w_ = width, h_ = height;
        body.clear(), map.clear();
        body.push_front({0,0});
        map.insert(0);
    }

    int move(string direction){
        // up, right, down, left direction
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (auto dir:direction){
            // remove the last one in body&map
            auto last = body.back();
            map.erase(last.first * w_ + last.second);

            // forward the head
            auto head = body.front();
            int idx = dir2idx(dir);
            if (idx < 0){
                return -1;
            }
            int nx_row = head.first + directions[idx][0], nx_col = head.second + directions[idx][1];
            // if out of bound
            if (nx_row <0 || nx_row >= h_ || nx_col < 0 || nx_col >= w_){
                return -1;
            }
            // if hit the body
            if (map.find(nx_row * w_ + nx_col) != map.end()){
                return -1;
            }
            
            body.push_front({nx_row, nx_col});
            map.insert(nx_row * w_ + nx_col);
            // if eat the fruit
            if ( len < food_.size() && food_[len].first == nx_row && food_[len].second == nx_col){
                ++len;
            }
            else{
                body.pop_back();
            }
            
            cout << "Len: " << len << endl;
            cout << "Body: " << endl;
            for (const auto&p:body){
                cout << "   " << p.first << ", " << p.second << endl;
            }
        }

        return len;
    }
private:
    // utility function
    int dir2idx(char d){
        int dir = -1;
        switch(d){
        case 'U':
            dir = 0;
            break;
        case 'R':
            dir = 1;
            break;
        case 'D':
            dir = 2;
            break;
        case 'L':
            dir = 3;
            break;
        }
        return dir;
    }
    using list_t = list<pair<int, int>>;
    using set_t = unordered_set<int>;
    using vec2d_t = vector<pair<int, int>>;

    vec2d_t food_;
    list_t body;
    set_t map;

    int len = 0;
    int w_{0}, h_{0};
};

int main(){
    int w=3, h=2;
    vector<pair<int, int>> fruit = {{1,2}, {0,1}};
    string dir = "RDRU";
    SnakeGame sol(w, h, fruit);
    cout << sol.move(dir) << endl;
    return 0;
}
