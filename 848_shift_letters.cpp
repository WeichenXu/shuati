class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int total_shift = 0;
        const int size = S.length();
        for (int i=size-1; i>=0; --i)
        {
            total_shift += shifts[i];
            total_shift %= 26;
            S[i] = (S[i]-'a'+total_shift)%26 + 'a';
        }
        return S;
    }
};
