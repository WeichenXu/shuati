#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        //use a string to store the current path, a vector of int to store index
         // use dfs to find the possible longest path
        size_t cur;
        size_t next = -1;
        size_t len = input.length();
        vector<int> levels={0};
        int maxLen = 0;
        do{
            cur = next + 1;
            next = input.find('\n', cur);
            // get the entry of the file/dir
            string entry = input.substr(cur, next - cur);
            bool isFile = false;
            int level = decodeEntry(entry, isFile);
            cout << "Level:" << level << ", entry:" << entry << endl;
            // if isFile update max path len
            // else update path levels
            if (isFile){
                maxLen = max(maxLen, levels[level-1]+int(entry.size()));
            }
            else{
                if (level >= levels.size()){
                    levels.push_back(0);
                }
                levels[level] = levels[level-1] + entry.length()+1;
            }
            // move to next field
        }
        while (next != string::npos);
        return maxLen;
    }
private:
    // return the number of "\t" ahead and remove them
    // update the isFile flag
    int decodeEntry(string &entry, bool &isFile){
        int len = entry.length();
        int i = 0;
        while (i < len && entry[i] == '\t'){
            ++i;
        }
        entry = entry.substr(i);
        if (entry.find('.') != string::npos){
            isFile = true;
        }
        return i+1;
    }
};

int main(){
    Solution sol;
    string test = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    int res = sol.lengthLongestPath(test);
    cout << "MaxLen:" << res << endl;
    return 0;
}
