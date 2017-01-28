#include <iostream>
#include <vector>
#include <string>

// 1. count the times of the chars
// 2. sort the count
// 3. rearrange using greedy

using namespace std;

class Solution{
private:
    class node{
    public:
        node (char ch, int count):
            ch_(ch), count_(count){}
        char ch_{'#'};
        int count_{0};
    };
public:
    string rearrangeString(string str, int k){
        // count the times
        int len=0;
        vector<node> chars;
        for (int i=0; i<26; ++i){
            chars.push_back(node('a'+i, 0));
        }
        for (auto ch:str){
            ++ chars[ch-'a'].count_;
            ++ len;
        }
        sort(chars.begin(), chars.end(), [](const node& left, const node& right){ return left.count_ > right.count_; });
        cout << len << endl;

        string res(len, '#');
        // arrange the keys
        int cur = 0;
        for (int i=0; i<26; ++i){
            cur %= len;
            int c = chars[i].count_, last = cur;
            char ch = chars[i].ch_;
            cout << "For char: " << 'a' + i << ", count: " << c << ", start at: " << last << endl;
            
            // assign location for each char
            for (int j=0; j<c; ++j){
                while(res[cur] != '#'){ cur = (cur+1) % len; }
                // can not find possible space
                cout << cur << ", ";
                if (!j){
                    last = cur;
                }
                else if (abs(cur-last) < k){
                    return "";
                }
                res[cur] = ch;
                cout << res << endl;
                if (j != c-1){
                    cur = (cur+k) % len;
                }
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    string str = "aabbccdd", str1 = "aabbcc";
    int k = 5, k1 =3;
    cout << "Ans: " << sol.rearrangeString(str, k) << endl;
}
