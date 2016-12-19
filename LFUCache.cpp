#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache{
private:
    using key_t = int;
    using value_t = int;
    // a list of key with same frequency 
    using index_list_t = list<int>;
    
    // a list of unique frequency list
    class level;
    using level_list_t = list<level>;
    class node{
    public:
        value_t value_;
        index_list_t::iterator index_iter_;
        level_list_t::iterator level_iter_;
        node(){}
        ~node(){}
    };
    class level{
    public:
        int freq_{0};
        index_list_t index_;
        level(int freq):freq_(freq){}
        ~level(){}
    };

    // store the key to pair_t
    using key_pair_t = unordered_map<key_t, node>;

    // data member
    key_pair_t key_pair_;
    level_list_t levels_;
    int capacity_{0};
    int size_{0};

    // utility function hit cache
    // update index_iterator & level_iterator in both node and cache
    // get the ++freq, insert a new level if necessary
    void hitCache(const key_t& key){
        auto& n = key_pair_[key];
        auto const cur_level_iter = n.level_iter_;
        level_list_t::iterator pre_level_iter;
        int freq = cur_level_iter->freq_ + 1;

        // insert or update new level ahead
        if (cur_level_iter == levels_.begin()){
            level head(freq);
            levels_.push_front(head);
            pre_level_iter = levels_.begin();
        }
        else{
            auto tmp = prev(cur_level_iter);
            if (tmp->freq_ == freq){
                pre_level_iter = tmp;
            }
            else{
                level cur(freq);
                levels_.insert(cur_level_iter, cur);
                pre_level_iter = (++tmp);
            }
        } 

        pre_level_iter->index_.push_front(key);
        // remove the original index iter
        auto& cur_level_ = n.level_iter_->index_;
        cur_level_.erase(n.index_iter_);
        if (cur_level_.empty()){
            levels_.erase(cur_level_iter);
        }

        // update the node
        n.level_iter_ = pre_level_iter;
        n.index_iter_ = pre_level_iter->index_.begin();
    }

public:
    // utility function for debug
    // print the cache
    void printCache(){
        cout << "#############################" <<endl;
        cout << "Size: " << size_ << ", Levels: " << levels_.size() << endl;
        // print each level
        for (const auto& it : levels_){
            cout << "Freq: " << it.freq_ << endl;
            cout << "Keys: ";
            for (auto key:it.index_){
                cout << key << " ";
            }
            cout << endl;
        }
    }

    LFUCache(int capacity):capacity_(capacity){
        key_pair_.clear();
    }

    // find the element in the key_pair
    // return -1 if not in the cache
    int get(int key){
        if (key_pair_.find(key) == key_pair_.end()){
            return -1;
        }
        hitCache(key);
        return key_pair_[key].value_;
    }

    // update if in cache
    // insert if not
    // remove the LF one if oversize
    void set(int key, int value){
        if (key_pair_.find(key) == key_pair_.end()){
            // remove LR if reach capacity
            if (size_ == capacity_ && !levels_.empty()){
                auto& last_level = levels_.back();
                int last_key = last_level.index_.back();
                key_pair_.erase(last_key);
                last_level.index_.pop_back();
                if (last_level.index_.empty()){
                    levels_.pop_back();
                }
                -- size_;
            }
            if (size_ < capacity_){
                level zero_level(0);
                zero_level.index_.push_front(key);
                levels_.push_back(zero_level);
                node insert;
                insert.level_iter_ = prev(levels_.end());
                insert.index_iter_ = insert.level_iter_->index_.begin();

                key_pair_[key] = insert;
                ++ size_;
            }
            else {
                return;
            }
        }
        auto& n = key_pair_[key];
        n.value_ = value;
        hitCache(key);
    }

};

int main(){
    LFUCache cache(0);
    cache.set(1, 1);
    cache.set(2, 2);
    cout << "get(1): " << cache.get(1) << endl;
    cache.set(3, 3);
    cout << "get(2): " << cache.get(2) << endl;
    cout << "get(3): " << cache.get(3) << endl;
    cache.set(4, 4);
    cout << "get(1): " << cache.get(1) << endl;
    cout << "get(3): " << cache.get(3) << endl;
    cout << "get(4): " << cache.get(4) << endl;
    return 0;
}
