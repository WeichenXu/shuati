#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include <cassert>

using namespace std;

class Solution{
public:
    int evalRPN(vector<string>& tokens){
        stack<int> nums;
        
        // 1. tokens
        // 2. calculate the updated result
        for (auto&t:tokens){
            if (isdigit(t[0]) || t.length() > 1){
                nums.push(stoi(t));            
            }
            else{
                // if no more than two nums left
                if (nums.size() < 2){
                    return 0;
                }
                int last = nums.top();
                nums.pop();
                int preLast = nums.top();
                nums.pop();
                switch(t[0]){
                    case '+':
                        preLast += last;
                        break;
                    case '-':
                        preLast -= last;
                        break;
                    case '*':
                        preLast *= last;
                        break;
                    case '/':
                        if (!last){
                            return 0;
                        }
                        preLast /= last;
                        break;
                    default:
                        return 0;
                }

                // push the res to the stack
                nums.push(preLast);
            }
        }

        // return the top of the nums, which should be only single one element
        if (nums.size() != 1){
            return 0;
        }
        return nums.top();
    }
};

int main(){
    Solution sol;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens1 = {"4", "13", "5", "/", "+"};
    vector<string> tokens2 = {"3", "-4", "+"};

    assert(sol.evalRPN(tokens) == 9);
    assert(sol.evalRPN(tokens1) == 6);
    assert(sol.evalRPN(tokens2) == -1);

    return 0;
}
