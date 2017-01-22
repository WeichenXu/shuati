#include <stdlib.h>

#include <iostream>
#include <string>

// use recursive way
// 

using namespace std;

class Solution{
public:
    string helper(const string&s, int& cur){
        int count = 0, digits = 1;
        string res = "";
        int len=s.length();
        
        while(cur < len){
            char tmp = s[cur];
            cout << tmp << endl;
            if (tmp == '['){
                string repeat = helper(s, ++cur);
                cout << repeat << ", " << count << " times." << endl;
                for(int i=0; i<count; ++i){
                    res += repeat;
                }
                digits = 1, count = 0;
            }
            else if(tmp == ']'){
                return res;
            }
            else if(isdigit(tmp)){
                count += digits * (tmp - '0');
                digits *= 10;
            }
            else{
                res += tmp;
            }
            ++cur;
        }

        return res;
    }

    string decodeString(string s){
        int i=0;
        return helper(s, i);    
    }
};

int main(){
    Solution sol;
    
    string sw = "2[a]";
    string s = "2[a1[b]]3[b]";
    string res = sol.decodeString(s);
    cout << "Ans for " << s << ", is " << res << endl;
    return 0;
}
