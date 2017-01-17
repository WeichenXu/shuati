#include <iostream>
#include <string>
#include <vector>

// three cases: 
// 1. original
// 2. part origin + part sub
// 3. pattern replication

using namespace std;

class Solution{
public:
    string encode(string s){
        int len = s.length();
        using dp_2dvec_t = vector<vector<string>>;
        dp_2dvec_t dp = dp_2dvec_t (len, vector<string>(len, ""));
        
        // dp[i][j] : represents the optimal encoded string for s[i, j]
        for (int l=1; l<=len; ++l){
            for (int i=0; i<=len-l; ++i){
                int j = i+l-1;
                // 1. len < 5, the optimal must be original
                dp[i][j] = s.substr(i, l);
                if (l >= 5){ 
                    // 2. encoded by sub optimal solution
                    for(int k=i; k<j; ++k){
                        int sublen = dp[i][k].length() + dp[k+1][j].length(); 
                        if ( sublen < dp[i][j].length() ){
                            dp[i][j] = dp[i][k] + dp[k+1][j];
                        }
                    }

                    // 3. encoded by replicated pattern
                    for(int k=1; k<l; ++k){
                        if (l%k == 0){
                            cout << "Enter branch 3: " << s.substr(i, l) << ", k: " << k << endl;
                            string repeatStr = s.substr(i, k);
                            bool repeated = true;
                            for (int m = 1; m < l/k; ++m){
                                if (s.substr(i+m*k, k) != repeatStr){
                                    repeated = false;
                                    break;
                                }
                            }
                            cout << "All sub repeated" << endl;
                            string num = to_string(l/k);
                            if ( repeated && ( dp[i][i+k-1].length() + num.length() + 2 ) < dp[i][j].length() ){
                                dp[i][j] = num + "[" + dp[i][i+k-1] + "]";
                            }
                        }
                    }
                }
            }
        }

        // debug helper
        for (const auto& row:dp){
            cout << endl;
            for (const auto& str:row){
                cout << str << " ";
            }
        }
        cout << endl;

        return dp[0][len-1];
    }

};

int main(){
    Solution sol;
    string s = "aabcaabcd";
    string s1 = "abbbabbbcabbbabbbc";
    cout << "Encoded: " << s << ", result: " << sol.encode(s1) << endl;
    return 0;
}
