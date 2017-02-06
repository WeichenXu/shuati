#include <iostream>
#include <vector>
#include <string>
#include <stack>

#include <cassert>

// 1. apply strategy design patter

// define the interface
class Operations{
public:
    Operations(int left, int right): left_(left), right_(right){}
    int getResult(){
        return doCalculate();
    }
//protected:
    int left_{0}, right_{0};
private:
    virtual int doCalculate() = 0;
};

// implement the interface
class PlusOperations : public Operations{
public:
    PlusOperations(int left, int right): Operations(left, right){}
private:
    int doCalculate(){
        return left_ + right_;
    }
};

class MinusOperations : public Operations{
public:
    MinusOperations(int left, int right): Operations(left, right){}
private:
    int doCalculate(){
        return left_ - right_;
    }
};

class MultiplyOperations : public Operations{
public:
    MultiplyOperations(int left, int right): Operations(left, right){}
private:
    int doCalculate(){
        return left_ * right_;
    }
};

class DivideOperations : public Operations{
public:
    DivideOperations(int left, int right): Operations(left, right){}
private:
    int doCalculate(){
        return left_ / right_;
    }
};

using namespace std;

class Expression{
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
                setOp('+', last, preLast);
                preLast = doOp();
                /*
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
                */
                
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

private:
    shared_ptr<Operations> op_{nullptr};
    void setOp(char op, int left, int right){
        switch(op){
            case '+':
                op_ = make_shared<PlusOperations>(left, right);
                break;
        }
    };
    int doOp(){
        return op_->getResult();
    }
};

int main(){
    Expression sol;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    vector<string> tokens1 = {"4", "13", "5", "/", "+"};
    vector<string> tokens2 = {"3", "-4", "+"};

    assert(sol.evalRPN(tokens) == 6);
    assert(sol.evalRPN(tokens1) == 22);
    assert(sol.evalRPN(tokens2) == -1);

    return 0;
}
