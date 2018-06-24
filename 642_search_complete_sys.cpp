#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class AutocompleteSystem {
private:
    struct StringCount{
        string m_str;
        int m_count{0};
    };
    struct Node{
        unordered_map<char, Node*> m_next;
        vector<int> m_words;
    };
    vector<StringCount> m_storage;
    unordered_map<string, int> m_map;
    Node* m_root, *m_cur;
    string m_input;
    void insert(const string& str, int times)
    {
        auto it = m_map.find(str);
        if (it != m_map.end())
        {
            m_storage[m_map[str]].m_count += times;
            return ;
        }
        int idx = m_storage.size();
        m_map[str] = idx; 
        m_storage.push_back({str, times});
        auto* cur = m_root;
        for (auto ch:str)
        {
            auto& nx = cur->m_next[ch];
            if (nx == nullptr) nx = new Node();
            nx->m_words.push_back(idx);
            cur = nx;
        }
    }
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        m_root = new Node();
        m_cur = m_root;
        const int size = sentences.size();
        for (int i=0; i<size; ++i)  insert(sentences[i], times[i]);
        for (auto& p:m_storage) cout << p.m_str << "->" << p.m_count << endl;
    }

    vector<string> input(char c) {
        vector<string> res;
        if (c == '#')
        {
            insert(m_input, 1);
            m_input = "";
            m_cur = m_root;
            return res;
        }
        m_input += c;
        if (m_cur == nullptr)   return res;
        m_cur = m_cur->m_next[c];
        if (m_cur == nullptr)   return res;
        auto ids = m_cur->m_words;
        sort(ids.begin(), ids.end(), [&](int l, int r){return m_storage[l].m_count>m_storage[r].m_count || (m_storage[l].m_count == m_storage[r].m_count and m_storage[l].m_str<m_storage[r].m_str);});
        for (int i=0; i<min(3, static_cast<int>(ids.size())); ++i) res.push_back(m_storage[ids[i]].m_str);
        return res;
    }
};

int main()
{
    vector<string> strs = {"i love you", "i love he", "i love"};
    vector<int> count = {1,2,3};
    AutocompleteSystem sys(strs, count);
    string tes = "i love hehe#i";
    for (int i=0; i<tes.length(); ++i)
    //for (int i=0; i<2; ++i)
    {
        cout << "i == " << i << endl;
        auto res =sys.input(tes[i]);
        for (auto& str:res) cout << str << " ";
        cout << endl;
    }
    return 0;
}
