#include <iostream>
#include <string>
#include <vector>

// 1. Formatted strings match, directly 

using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string pattern = "";
        for (const auto& word:sentence){
            pattern += word + " ";
        }
        cout << "Pattern: " << pattern << endl;
        int len = pattern.length(), start = 0;
        // match the sentence by each row
        for (int i=0; i<rows; ++i){
            cout << "Current start: " << start << endl;
            start += cols;
            if (pattern[start%len] == ' '){
                ++start;
            }
            else{
                while(start > 0 && pattern[(start-1)%len] != ' '){
                    cout << pattern[(start-1)%len] << endl;
                    --start;
                }
            }
        }

        cout << "Current start: " << start << endl;
        return start/len;
    }
};

int main(){
    vector<string> sentence = {
        "a",
        "bcd",
        "f"
    };
    Solution sol;
    int rows = 2, cols = 5;
    auto res = sol.wordsTyping(sentence, rows, cols);
    cout << "Could match times: " << res << endl;
    return 0;
}

