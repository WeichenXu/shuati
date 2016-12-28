#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// NP-hard
// 1. bipartite into two classes: borrowers, lenders
// 2. match all opposite
// 3. iterate all possible solutions

using namespace std;

class Solution{
public:
    int minTransfers(vector<vector<int>>& transactions){
        unordered_map<int, int> balance;
        for (const auto& tran:transactions){
            balance[tran[0]] += tran[2];
            balance[tran[1]] -= tran[2];
        }

        vector<int> allBalances;
        for (const auto&it:balance){
            if (it.second){
                allBalances.push_back(it.second);
            }
        }
        printBalance(allBalances);

        // match and remove opposite
        sort(allBalances.begin(), allBalances.end());
        vector<int> remains(allBalances.size(), 0);
        int filterSize = matchOpposite(allBalances, remains);
        printBalance(remains);

        // iterate all solution
        int matchedTrans = (allBalances.size() - filterSize) >> 1;
        return matchedTrans + findMinEdges(remains, 0);
    }

private:
    using nodes_t = vector<int>;
    nodes_t borrowers_, lenders_;
   
    // debug helper, print balance
    void printBalance(const vector<int> b){
        for(auto it:b){
            cout << it << " ";
        }
        cout << endl;
    }

    // match the opposite
    // two pointers, insert all unmatched 
    int matchOpposite(vector<int> &all, vector<int> &remains){
        int i=0, j=all.size()-1;
        int s = 0;
        while(i <= j){
            if (i == j){
                remains[s++] = all[i];
                ++i, --j;
            }
            else{
                if (all[i] == -all[j]){
                    ++i, --j;
                }
                else if (abs(all[i]) > abs(all[j])){
                    remains[s++] = all[i];
                    ++i;
                }
                else{
                    remains[s++] = all[j];
                    --j;
                }
            }
        }

        //erase the remaining part if necessary
        remains.resize(s);

        return s;
    }

    // find the minimum number of transactions
    int findMinEdges( vector<int> &bals, int left){
        int ans = INT_MAX;
        // locate first non-zero balance
        int start = left;
        for (; start<bals.size() && !bals[start]; ++start){}
        // iterate throught all remains
        for (int i=start+1; i<bals.size(); ++i){
            if (bals[i]*bals[start] < 0){
                bals[i] += bals[start];
                ans = min(ans, findMinEdges(bals, start+1) + 1);
                bals[i] -= bals[start];

            }
        }
        return ans < INT_MAX ? ans:0;
    }

};

int main(){
    Solution sol;
    vector<vector<int>> transactions = {{0,1,10}, {1,0,1}, {1,2,5}, {2,0,5}};
    cout << "Answer: " << sol.minTransfers(transactions) << endl;
}
