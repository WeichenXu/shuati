#include <iostream>
#include <vector>
#include <memory>
#include <array>
#include <unordered_set>

using namespace std;

class Solution{
public:
    // a prefix trie which return all strings with same prefix
    class prefixTrie{
    public:
        // node of the trie
        class node{
        public:
            int idx_{-1};
            array<shared_ptr<node>, 26> next_;
            unordered_set<int> prefix_;
            node(){}
            ~node(){}
        };
        // get the string with known prefix, 
        unordered_set<int> getPrefix(const string& prefix){
            auto cur = root_; 
            for(const auto ch:prefix){
                cur = cur->next_[ch-'a'];
                if (cur == nullptr){
                    return {};
                }
            }
            return cur->prefix_;
        }
        void insert(string& str, int idx){
            auto cur = root_;
            for(const auto ch:str){
                cur->prefix_.insert(idx);
                auto &next = cur->next_[ch-'a'];
                if (next == nullptr){
                    next = make_shared<node>();
                }
                cur = next;
            }
            // mark the end of the str
            cur->prefix_.insert(idx);
        }
    private:
        shared_ptr<node> root_{make_shared<node>()};
    };
    // find the ith string of the square using backtrace 
    void backtrace(const unordered_set<int>& candidate, vector<string>& square, int i){
        if (i == len_){
            squares_.push_back(square);
        }
        for (int can:candidate){
            square.push_back(words_[can]);
            // next candidates
            string nextPrefix = "";
            for(int j = 0; j <= i; ++j){
                nextPrefix += square[j][i+1];
            }
            unordered_set<int> nextCandidate = trie_.getPrefix(nextPrefix);
            backtrace(nextCandidate, square, i+1);
            square.pop_back();
        }
        return;
    }
    vector<vector<string>> wordSquares(vector<string>& words){
        words_ = move(words);
        if (words_.empty()){
            return squares_;
        }
        len_ = words_[0].length();
        cout << "################"<< endl;
        cout << "Start insert into trie" << endl;
        for (int i=0; i<words_.size(); ++i){
            cout << words_[i] << endl;
            trie_.insert(words_[i], i);
        }
        vector<string> square;
        cout << "################"<< endl;
        cout << "Start finding square" << endl;
        // Do some prefix test
        //auto prefix = trie_.getPrefix("area");
        //for(auto it:prefix){
        //    cout << it << " ";
        //}
        //cout << endl;

        backtrace(trie_.getPrefix(""), square, 0);
        return squares_;
    }
private:
    vector<string> words_;
    vector<vector<string>> squares_;
    prefixTrie trie_;
    int len_;
};
void printRes(vector<vector<string>> &res){
    for (auto && square:res){
        for(auto &str:square){
            cout << str << "\n";
        }
        cout << endl;
    }
}
int main(){
    vector<string> words = {"area","lead","wall","lady","ball"};
    vector<string> words2 = {"abat","baba","atan","atal"};

    Solution sol;
    auto res = sol.wordSquares(words);
    printRes(res);

    auto res2 = sol.wordSquares(words2);
    printRes(res2);
    return 0;
}
