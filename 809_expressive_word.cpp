class Solution {
public:
    // two ptrs will be faster as early prune
    // https://leetcode.com/problems/expressive-words/discuss/122660/C++JavaPython-2-Pointers-and-4-pointers
    int expressiveWords(string S, vector<string>& words) {
        auto toSeq = [](const string& word){
            string pattern = "";
            vector<int> nums;
            for (int i=0; i<word.length(); ++i)
            {
                int j = 1;
                for (; i+j<word.length(); ++j)
                {
                    if (word[i+j] != word[i]) break;
                }
                pattern += word[i];
                nums.push_back(j);
                i += j-1;
            }
            return {pattern, nums};
        };
        auto isExtend = [](const auto& l, const auto& r){
            int i=0, j=0;
            while (i < l.first.length() and j < r.first.length())
            {
                if (l.first[i] == r.first[j] and (l.second[i] == r.second[j] || (l.second[i] >= 3 and r.second[i] <= l.second[j])))
                {
                    ++i, ++j;
                }
                else return false;
            }
            return i == i.first.length() and j == r.first.length();
        };
        const auto& p = toPattern(S);
        int res = 0;
        for (const auto& word:words)   
        {
            const auto& wp = toSeq(wrod);
            if (isExtend(p, wp))    ++res;
        }
        return res;
    }
};
