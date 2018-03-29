#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <memory>
#include <algorithm>

using namespace std;

// build two trie
// 1. prefix trie
// 2. suffix trie
class Trie{
struct Node{
    array<unique_ptr<Node>, 26> m_next;
    vector<int> m_words;
};
public:
    Trie(){
        m_root = make_unique<Node>();
    }
    void insert(const string& str, int idx)
    {
        auto* cur = m_root.get();
        cur->m_words.push_back(idx);
        for (size_t i=0; i<str.length(); ++i)
        {
            auto& nx = cur->m_next[str[i]-'a'];
            if (not nx)
            {
                nx = make_unique<Node>();
            }
            cur = nx.get(); 
            cur->m_words.push_back(idx);
        }
    }
    vector<int> find(const string& str) const
    {
        auto* cur = m_root.get();
        for (size_t i=0; i<str.length(); ++i)
        {
            auto& nx = cur->m_next[str[i]-'a'];
            if (not nx) return {};
            cur = nx.get();
        }
        return cur->m_words;
    }
    unique_ptr<Node> m_root;
};
class WordFilter {
public:
    Trie pre, suf;
    WordFilter(vector<string> words) {
        // build prefix & suffix trie
        for (int i=0; i<words.size(); ++i)
        {
            pre.insert(words[i], i);
            reverse(words[i].begin(), words[i].end());
            suf.insert(words[i], i);
        }
    }

    int findFirstIntersact(const vector<int>& l, const vector<int>& r)
    {
        auto lIt = l.begin(), rIt = r.begin();
        while (lIt != l.end() && rIt != r.end())
        {
            if (*lIt == *rIt)   return *lIt;
            else if (*lIt < *rIt) ++rIt;
            else ++lIt;
        }
        return -1;
    }
    int f(string prefix, string suffix) {
        auto preVec = pre.find(prefix);
        reverse(suffix.begin(), suffix.end());
        auto sufVec = suf.find(suffix);
        cout << preVec.size() << "\t" << sufVec.size() << endl;
        cout << preVec[0] << "\t" << sufVec[0] << endl;

        reverse(preVec.begin(), preVec.end());
        reverse(sufVec.begin(), sufVec.end());
        return findFirstIntersact(preVec, sufVec);
    }
};

int main()
{
    WordFilter f({"abbbababbb","baaabbabbb","abababbaaa","abbbbbbbba","bbbaabbbaa","ababbaabaa","baaaaabbbb","babbabbabb","ababaababb","bbabbababa"});
    //cout << f.f("a", "e") << endl;
    //cout << f.f("a", "c") << endl;
    //cout << f.f("app", "c") << endl;
    cout << f.f("", "abaa") << endl;
}
