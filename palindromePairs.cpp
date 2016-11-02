class Solution {
    private:
        class trieNode{
            public:
                array<shared_ptr<trieNode>, 26> children_;
                int idx_{-1};
                unordered_set<int> list_;
                trieNode(){}
                ~trieNode(){}
        };

        // data member
        shared_ptr<trieNode> root_{};
        vector<vector<int>> pairs_;

        // utility function
        void add(string& str, int pos){
            int len = str.length();
            auto cur = root_;    
            for(int i = len-1; i>=0; --i){
                // if w[0,i] is palindro
                if (isPalindro(str, 0, i)){
                    cur->list_.insert(pos);
                }
                auto& next = cur->children_[str[i]-'a'];
                if (next == nullptr){
                    next = make_shared<trieNode>();
                    //cout << (len-1-i) << " " << str[i] << endl;
                }
                cur = next;
            }
            // update the cur idx to denote this node represent str
            cur->idx_ = pos;
            cur->list_.insert(pos);
        }

        void printPairs() const{
            for(const auto& vec:pairs_){
                for (const auto i:vec){
                    cout << i << " ";
                }
                cout <<endl;
            }
        }

        // 1. when str a ends, all candidates in a can be added
        // 2. if a get part match with b, b must end at current node
        void search(string& str, int pos){
            auto cur = root_;
            int len = str.length();
            //cout << "Searching for " << str << endl;
            for (int i=0; i<len; ++i){
                //cout << i << endl;
                if (cur->idx_ != -1 && cur->idx_ != pos && isPalindro(str, i, len-1)){
                    pairs_.push_back(move(vector<int>{pos, cur->idx_}));
                }
                cur = cur->children_[str[i]-'a'];
                if (cur == nullptr){
                    return;
                }
            }
            //cout << "end node " << cur->idx_<<endl;
            for (const auto i:cur->list_){
                if (i != pos){
                    pairs_.push_back(move(vector<int>{pos, i}));
                }
            }
            //printPairs();
        }
    public:
        bool isPalindro(string& str, int i, int j) const{
            while (i < j){
                if (str[i++] != str[j--]){
                    return false;
                }
            }
            return true;
        }
        vector<vector<int>> palindromePairs(vector<string>& words){
            pairs_.clear();
            root_ = make_shared<trieNode>();
            // add the word into the trie
            for(int i=0; i<words.size(); ++i){
                add(words[i], i);
            }
            // search each word
            for(int i=0; i<words.size(); ++i){
                search(words[i], i);
            }
            return pairs_;
        }
};
