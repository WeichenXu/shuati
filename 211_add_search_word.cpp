#include <iostream>
#include <string>
#include <memory>

#include <vector>

#include <cassert>

using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = make_shared<node_t>();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto cur = root;
        for(const auto ch:word){
            auto &nx = cur->children[ch-'a'];
            if (nx == nullptr){
                nx = make_shared<node_t>();
            }
            cur = nx;
        }
        cur->ended = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchDfs(root, word, 0);
    }

private:
    class node_t{
    public:
        bool ended{false};
        vector<shared_ptr<node_t>> children;
        node_t ():ended(false), children(26, nullptr){}
    };

    shared_ptr<node_t> root;
    bool searchDfs(shared_ptr<node_t> cur, const string& word, int i){
        cout << "Search for word: " << word << ", in dfs at index: " << i << endl;
        for (int j=i; j<word.length(); ++j){
            cout << "Reaching index: " << j << endl;
            if (cur == nullptr){
                return false;
            }
            char c = word[j];
            if (c == '.'){
                for (int k=0; k<26; ++k){
                    if (searchDfs(cur->children[k], word, j+1)){
                        return true;
                    }
                }
                return false;
            }
            else {
                cur = cur->children[c-'a']; 
            }
        }

        return (cur != nullptr && cur->ended);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

int main(){
    WordDictionary wd; 
    vector<string> words = {
        "a",
        "a",
        "bad",
        "dad",
        "mad"
    };
    for (const auto& w:words){
        wd.addWord(w);
    }
    
    for (const auto& w:words){
        cout << w << endl;
        assert(wd.search(w) == true);
    }    

    assert(wd.search(".a") == false);
    assert(wd.search("a.") == false);
    assert(wd.search("a..") == false);
    assert(wd.search("sad") == false);
    assert(wd.search(".ad") == true);
    assert(wd.search("dad") == true);
    assert(wd.search("b..") == true);

    return 0;
}
