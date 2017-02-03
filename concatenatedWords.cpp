#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <memory>

// 1. build the trie for all the words
//    a. use a set to store all the start and end words 
// 2. confirm each word if it can be contaneted by the words in the trie
//    a. mark 1. the current inner word 2. the already matched string index
// 3. !!! to simply the case like 'a', 'aaa'
//    sort the strings in ascending length, if the string can be concatenated do NOT build

using namespace std;

class Solution {
public:
    class node{
    public:
        char val_{'*'};
        unordered_set<int> end_;
        vector<shared_ptr<node>> child_{26, nullptr};
        node(char val): val_(val){}
    };

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        words_ = move(words);
        // sort the words using length

        sort (words_.begin(), words_.end(), [](const string& left, const string& right){return left.length() < right.length(); });
        // 1. search/build the trie
        for (int i=0; i<words_.size(); ++i){
            string w = words_[i];
            if (searchSubStr(w, 0, w.length(), 0)){
                res_.push_back(w);
            }
            else{
                cout << w << " ";
                insert(words_[i], i);
            }
        }

        return res_;
    }

private:
    shared_ptr<node> root_{make_shared<node>('*')};

    //-- Utility funciton for the trie --//
    void insert(const string& word, int index){
        auto cur = root_;
        for (auto ch:word){
            auto& nx = cur->child_[ch-'a'];
            if (nx == nullptr){
                nx = make_shared<node>(ch);
            }
            cur = nx;
        }
        cur->end_.insert(index);
    }

    // Find the next valid substr in the trie
    // push to the result if matched end 
    bool searchSubStr(const string& word, int start, int len, int size){
        if (start >= len){
            if (size < 2){
                return false;
            }
            return true;;
        }

        // search the substr from start
        bool founded = false;
        auto cur = root_;
        for (int i=start; i<len; ++i){
            char ch = word[i];
            cur = cur->child_[ch-'a'];
            if (cur == nullptr){
                return false;
            }
            for (auto it:cur->end_){
                founded = searchSubStr(word, i+1, len, size+1);
                if (founded){
                    return founded;
                }
            } 
        }

        return founded;
    }

    vector<string> res_;
    vector<string> words_;
};

int main(){
    Solution sol;
    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    auto res = sol.findAllConcatenatedWordsInADict(words);
    for (const auto&w:res){
        cout << w << " ";
    }
    cout << endl;
    return 0;
}
