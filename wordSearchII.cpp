#include <iostream>
#include <string>
#include <memory>
#include <array>
#include <vector>
#include <unordered_set>

// 1. build a trie for target words
// 2. conduct dfs on each cell

using namespace std;

class Solution{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        if (board.empty()){
            return {};
        }
        // build the trie with the dictionary
        for (const auto& w:words){
            insert(w);
        }

        // do dfs
        row = board.size(), col = board[0].size();
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                vector<vector<bool>> visited = vector<vector<bool>> (row, vector<bool>(col, false));
                string str = "";
                dfs(i, j, board, visited, str, root_);
            }
        }

        vector<string> ans(res.begin(), res.end());
        return ans;
    }

private:
    unordered_set<string> res;

    class node{
    public:
        bool ended_{false};
        bool empty_{true};
        array<shared_ptr<node>, 26> next_;
    };
    shared_ptr<node> root_{make_shared<node>()};

    int row{0},col{0};

    //--Utility--//
    void insert(const string &w){
        auto cur = root_;
        for (int i=0; i<w.length(); ++i){
            auto &pre = cur->next_[w[i]-'a'];
            if (pre == nullptr){
                pre = make_shared<node>();
            }
            cur = pre;
        }
        cur->ended_ = true;
    }

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited, string& str, shared_ptr<node> par){
        cout << "dfs: " << str << ", cur: "<< board[i][j] << endl;
        vector<int> dx={-1,0,1,0},dy={0,1,0,-1};
        visited[i][j] = true;
        char curChar = board[i][j];
        
        if (par->next_[curChar - 'a'] != nullptr){
            str += curChar;
            par = par -> next_[curChar - 'a'];
            if (par->ended_){
                res.insert(str);
            }
            for (int k=0; k<4; ++k){
                int nx_row = i+dx[k], nx_col = j+dy[k];
                if (nx_row >= 0 && nx_row < row && nx_col >= 0 && nx_col < col){
                    if (!visited[nx_row][nx_col]){
                        dfs(nx_row, nx_col, board, visited, str, par);               
                    }
                }
            }
            str.pop_back();
        }
        visited[i][j] = false;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> dict = {{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}};
    vector<string> w = {"eat", "oath"};
    vector<vector<char>> dict1 = {{'a','b'},{'c','d'}};
    vector<string> w1 = {"acdb"};
    auto res = sol.findWords(dict, w);
    for (const auto &w:res){
        cout << w << " ";
    }
    cout << endl;
    return 0;
}
