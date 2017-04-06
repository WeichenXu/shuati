#include <iostream>
#include <stdlib.h>
#include <cassert>

#include <vector>
#include <unordered_map>

// 1. hash_map store mapping between key&first item
// 2. vector store length of items, linked to nx (same key)

using namespace std;

class RandomizedCollection {
public:
    using vec_t = vector<pair<int, int>>;
    using map_t = unordered_map<int, vector<int>>;

    map_t m;
    vec_t v;

    /** Initialize your data structure here. */
    RandomizedCollection() {
        m.clear();
        v.clear();
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        cout << "Insert " << val << endl;
        auto it = m.find(val);
        bool res = it == m.end();
        int size = m[val].size();
        m[val].push_back(v.size());
        v.push_back({val, size});
        print();
        return res;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        cout << "Remove " << val << endl;
        auto it = m.find(val);
        bool res = it != m.end();
        if (it != m.end()){
            auto valIndex = it->second.back();
            auto back = v.back();
            v[valIndex] = back;
            m[back.first][back.second] = valIndex;
            v.pop_back();
            it->second.pop_back();
            if (it->second.empty()){
                m.erase(it);
            }
        }
        print();
        return res;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand()%v.size()].first;
    }

    void print(){
        for (auto i:v){
            cout << i.first << " ";
        }
        cout << endl;
    }
};

int main(){
    RandomizedCollection obj;
    assert (obj.insert(10) == true);
    assert (obj.insert(10) == false);
    assert (obj.insert(20) == true);
    assert (obj.insert(20) == false);
    assert (obj.insert(30) == true);
    assert (obj.insert(30) == false);
    assert (obj.remove(10) == true);
    assert (obj.remove(10) == true);
    assert (obj.remove(30) == true);
    assert (obj.remove(30) == true);
    return 0;
}
