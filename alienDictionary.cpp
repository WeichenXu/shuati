#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <unordered_set>
// Use topological sort

using namespace std;

class Solution {
private:
    using link_t = vector<bool>;
    using graph_t = vector<link_t>;
    using alpha_t = unordered_set<char>;
    string res_{""};
    using path_t = deque<int>;
    link_t visited_;
    path_t path_;
    
    // topological sort using dfs
    // return false if cycle found
    bool topologicalSort(graph_t& graph, char cur){
        cout << "Path: ";
        for (auto it:path_){
            cout << char(it+'a') << " ";
        }
        cout << endl;
        cout << "Cur: " << cur << endl;
        int idx = cur-'a';
        if (visited_[idx]){
            return true;
        }
        visited_[idx] = true;
        path_.push_back(idx);
        for(int i=0; i<26; ++i){
            if (graph[idx][i]){
                if (find(path_.begin(), path_.end(), i) != path_.end() || !topologicalSort(graph, static_cast<char>('a'+i))){
                    return false;            
                }
            }
        }
        path_.pop_back();
        res_ += cur;
        return true;
    }

public:
    string alienOrder(vector<string>& words){
        // init graph data structure
        link_t empty_link = link_t(26, false);
        graph_t graph = graph_t(26, empty_link);
        // construc the graph
        alpha_t alphas;
        int words_size = words.size();
        for(int i=0; i<words_size; ++i){
            int len = words[i].length();
            for (int j = 0; j<len; ++j){
                alphas.insert(words[i][j]);
            }
            // the first word:"word", link 'w'->'o', 'o'->'r', 'r'->'d'
            if(i){
                auto &prev = words[i-1];
                auto &cur = words[i];
                int compare_len = min(prev.length(), cur.length());
                int j;
                for (j=0; j<compare_len; ++j){
                    if (prev[j] != cur[j]){
                        break;
                    }
                }
                // if j arrive compare_len
                if (j == compare_len){
                    // prev = cur + '...'
                    if (j < prev.length()){
                        return "";
                    }
                    continue;
                }
                graph[prev[j]-'a'][cur[j]-'a'] = true;
            }
        }
        // return the topological sort of the graph
        visited_ = link_t(26, false);
        for (auto i : alphas){
            cout << i << " ";
            cout << "link to: ";
            for (int j=0; j<26; ++j){
                if(graph[i-'a'][j]){
                    cout << static_cast<char>('a'+j) << " ";
                }
            }
            cout << endl;
            if (!topologicalSort(graph, i)){
                return "";
            }
        }
        reverse(res_.begin(), res_.end());
        return res_;
    }
};

int main(){
    Solution sol;
    vector<string> dict = {"wrt", "wrf", "er", "ett", "rftt"};
    vector<string> dict2 = {"z", "z"}; 
    vector<string> dict3 = {"aac", "aabb", "aaba"};
    cout << "Ans: \n" << sol.alienOrder(dict3) << endl;
    return 0;
}
