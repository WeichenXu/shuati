#include <iostream>
#include <string>
#include <sstream>

// use do...while... is more suitable for splitting string

using namespace std;

int main(){
    string str = "dir\n\tsubdir1";
    size_t next = -1;
    size_t cur = 0;
    /* method 1
    while ((next = str.find('\n', cur)) != string::npos){
        string sub = str.substr(cur, next-cur);
        cur = next + 1;
        cout << sub << endl;
    }
    // still need to consider about remaining tail
    */
    /* method 2
    do{
        cur = next + 1;
        next = str.find('\n', cur);
        cout << next << " " << str.substr(cur, next - cur) << endl;
    }
    while(next != string::npos);
    */
    /* method 3
    istringstream ss( str );
    string field;
    while (!ss.eof()){
        getline ( ss, field, '\n');
        cout << field << endl;
    }
    */
    return 0;
}
