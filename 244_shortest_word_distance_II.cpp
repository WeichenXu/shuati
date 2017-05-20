#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class WordDistance {
public:
    WordDistance(vector<string> words) {
        for (int i=0; i<words.size(); i++){
            dict[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        auto& left = dict[word1];
        auto& right = dict[word2];
        auto it_left = left.begin(), it_right = right.begin();
        int res = INT_MAX;
        while(it_left != left.end() && it_right != right.end()){
            res = min(res, abs(*it_left - *it_right));
            if (*it_left <= *it_right)  ++it_left;
            else ++it_right;
        }
        return res;
    }

private:
    unordered_map<string, vector<int>> dict;
};

int main(){
    vector<string> words = {
        "a",
        "b",
        "c",
        "d",
        "b"
    };
    WordDistance wd(words);
    auto res = wd.shortest("b","d");
    cout << "Shortest length: " << res << endl;
    return 0;
}
