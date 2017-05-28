#include <iostream>
#include <string>
#include <vector>

// 1st solution. Formatted strings match, directly 
// 2nd solution, DP: generate array which store next index
//                 ** next index might be longer than len of array

using namespace std;

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int size = sentence.size();
        vector<int> nx(size, 0);
        for (int i=0; i<size; ++i){
            int cur = i, len = 0;
            while (len + sentence[cur % size].length() <= cols){
                len += sentence[cur++ % size].length() + 1;
            }
            cout << "Current index: " << i << ", current nx: " << cur << endl;
            nx[i] = cur;
        }

        int k = 0;
        for (int i=0; i<rows; ++i){
            k += nx[k%size] - k%size;
        }
        return k/size;
    }
};

int main(){
    vector<string> sentence = {
        "I",
        "had",
        "apple",
        "pie"
    };
    Solution sol;
    int rows = 4, cols = 5;
    auto res = sol.wordsTyping(sentence, rows, cols);
    cout << "Could match times: " << res << endl;
    return 0;
}

