class Solution {
public:
    bool isPalindro(const string& str, int& l, int& r)
    {
        while (l < r)
        {
            if (str[l] != str[r])   return false;
            ++l, --r;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0, r=s.length()-1;
        if (isPalindro(s, l, r))    return true;
        int l1=l+1, r1=r, l2=l, r2=r-1;
        return isPalindro(s, l1, r1) || isPalindro(s, l2, r2);
    }
};
