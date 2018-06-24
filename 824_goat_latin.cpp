class Solution {
    unordered_set<char> vowel;
public:
    vector<string> tokenize(string& S)
    {
        stringstream ss;
        ss << S;
        vector<string> tokens;
        string tok;
        while (getline(ss, tok, ' '))
        {
            tokens.push_back(tok);
        }
    }
    string toGoatLatin(string S) {
        auto tokens = tokenize(S);
        string res = "";
        vowel = {'a', 'e', 'i', 'o', 'u'};
        for (int i=0; i<tokens.size(); ++i)
        {
            auto t = tokens[i];
            if (vowel.find(tolower(t[0])==vowel.end()))
            {
                t.push_back(t[0]);
                t.erase(t.begin());
            }
            t.append("ma");
            t.append('a', i+1);
            res.append(t);
            if (i != tokens.size() - 1) res.append(" ");
        }
        return res;
    }
};
