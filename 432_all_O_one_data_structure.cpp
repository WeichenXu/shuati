#include <iostream>
#include <iterator>
#include <cassert>

#include <unordered_map>
#include <unordered_set>
#include <list>

// 1. use Linked Hashmap to record strings with the times

using namespace std;
class AllOne {
public:
    struct level{
        int count; 
        unordered_set<string> strs;
        level(int c) : count(c){}
    };
    
    /** Initialize your data structure here. */
    AllOne() {
        allLevels.clear();
        dict.clear();
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        auto it_dict = dict.find(key);
        levels_t::iterator it_list;
        if (it_dict == dict.end()){
            if (allLevels.empty() || allLevels.front().count != 1){
                allLevels.push_front(level(1));
            }
            it_list = allLevels.begin();
            it_list->strs.insert(key);
        }
        else{
            it_list = it_dict->second;
            int nx_count = it_list->count + 1;
            auto nx_list = next(it_list);
            if (nx_list == allLevels.end() || nx_list->count != nx_count){
                nx_list = allLevels.insert(nx_list, level(nx_count));
            }
            nx_list->strs.insert(key);
            it_list->strs.erase(key);
            if (it_list->strs.empty()){
                allLevels.erase(it_list);
            }
            it_list = nx_list;
        }
        dict[key] = it_list;
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        auto it_dict = dict.find(key);
        if (it_dict != dict.end()){
            auto it_list = it_dict->second;
            int prev_count = it_list->count - 1;
            if (prev_count > 0){
                // if current it_list is at begin or previous != count - 1
                if (it_list == allLevels.begin() || prev(it_list)->count != prev_count){
                    allLevels.insert(it_list, level(prev_count));
                }
                auto prev_list = prev(it_list);
                prev_list->strs.insert(key);
                dict[key] = prev_list;
            }
            else{
                dict.erase(key);
            }
            it_list->strs.erase(key);
            if (it_list->strs.empty()){
                allLevels.erase(it_list);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (allLevels.empty())  return "";
        return *(allLevels.back().strs.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (allLevels.empty())  return "";
        return *(allLevels.front().strs.begin());
    }

    void print_helper(const string& marker){
        cout << marker << endl;
        print();
    }
private:
    using levels_t = list<level>;
    levels_t allLevels;
    unordered_map<string, list<level>::iterator> dict;
    void print(){
        for(auto it = allLevels.begin(); it != allLevels.end(); ++it){
            cout << "Current level: " << it->count << ", elements:" << endl;
            cout << "\t";
            for (const auto& str:it->strs){
                cout << str << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    AllOne obj;
    string key1 = "k1", key2 = "k2";
    assert(obj.getMaxKey() == "");
    obj.inc(key1);
    obj.inc(key2);
    obj.inc(key2);
    obj.inc(key2);
    obj.inc(key2);

    obj.print_helper("First.....");
    
    obj.dec(key2);
    obj.dec(key2);
    obj.print_helper("Second.....");
    return 0;
}
