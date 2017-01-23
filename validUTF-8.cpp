#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool validUtf8(vector<int>& data){
        int count=0;
        for (auto c:data){
            if (!count){
                // multi-char header
                if((c>>5) == 0b110){
                    count = 1;
                }
                else if((c>>4) == 0b1110){
                    count = 2;
                }
                else if((c>>3) == 0b11110){
                    count = 3;
                }
                // single-char
                else if ((c >> 7)){ 
                    return false;
                }
            }
            else{
                if ((c >> 6) != 0b10){
                    return false;
                }
                --count;
            }
        }
        return count==0;
    }
};

int main(){
    Solution sol;
    vector<int> data = {235, 140, 4};
    cout << sol.validUtf8(data) << endl;
}
