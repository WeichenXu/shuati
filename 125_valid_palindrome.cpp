#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length()-1;
        while (l < r){
            char curL = s[l], curR = s[r];
            if (!num_or_char(curL)){
                ++l;
                continue;
            }
            if (!num_or_char(curR)){
                --r;
                continue;
            }
            if (to_lower(s[l++]) != to_lower(s[r--])){
                return false;
            }
        }
        return true;
    }
private:
    bool num_or_char(char ch){
        return ('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'z') ||
            ('A' <= ch && ch <= 'Z');
    }
    char to_lower(char ch){
        if ('A' <= ch && ch <= 'Z'){
            ch -= 'A'-'a';
        }
        return ch;
    }
};

int main(){
    string a = "w1hat ???tahw";
    Solution sol;
    auto res = sol.isPalindrome(a);
    cout << "Res: " << res << endl;
    return 0;
}
