#include <iostream>
#include <math.h>
// 1. list all possible palindrome candidate
//    test whether it can be multiple of two n-digit numbers
using namespace std;

class Solution{
public:
    using long_t = long long int;

    int largestPalindrome(int n){
        long_t maxNum = pow(10,n) - 1, minNum = maxNum/10;
        long_t palindrome = maxNum * maxNum;
        long_t left = palindrome/pow(10,n);

        // construct the candidate pairs
        for(; left>minNum; --left){
            palindrome = createPalindrome(left);
            for(long_t i = maxNum; i > minNum; --i){
                long_t j = palindrome/i;
                if (j > i){
                    //cout << "Palindro: " << palindrome << ", i: " << i << ", j:" << j << endl;
                    break;
                }
                if (palindrome%i == 0 && j > minNum){
                    return palindrome%1337;
                }
            }
        }
      
        return 9;
    }   

private:
    long_t createPalindrome(long_t left){
        long_t tmp = left;
        while(tmp){
            left = left * 10 + (tmp % 10);
            tmp /= 10;
        }
        return left;
    }
};

int main(){
    Solution sol;
    int n = 1;
    cout << "Largest palindrome is " << sol.largestPalindrome(n) << ", when n is " << n << endl; 
}
