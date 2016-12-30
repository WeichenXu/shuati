#include <iostream>
#include <vector>
#include <unordered_set>

// recursive
// whether abbreviate the current char or not

using namespace std;

class Solution{
public:

    void helper(string &word, string pre,  int cur, int count){
        int len = word.length();
        if (cur >= len){
            if (count){
                pre += to_string(count);
            }
            abbrs.push_back(pre);
            return;
        }
        helper(word, pre + (count > 0 ? to_string(count) : "") + word[cur], cur+1, 0);
        helper(word, pre, cur+1, count+1);
    }
    
    vector<string> generateAbbreviations(string word){
        helper(word, "", 0, 0);
        return abbrs; 
    }

private:
    vector<string> abbrs;
};

int main(){
    Solution sol;
    string w = "word";
    auto abbrs = sol.generateAbbreviations(w);
    for (const auto & abbr:abbrs){
        cout << abbr << " ";
    }
    cout<<endl;
    return 0;
}
