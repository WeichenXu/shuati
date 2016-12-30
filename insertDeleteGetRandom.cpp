#include <stdlib.h>

#include <iostream>
#include <vector>
#include <unordered_map>
// use a vector to store all vals in the set
// use a hash map to store <val, index in the vec>

using namespace std;

class RandomizedSet{
public:
    RandomizedSet(){
        m.clear();
        v.clear();
    }

    bool insert(int val){
        if (m.find(val) != m.end()){
            return false;
        }

        v.push_back(val);
        m[val] = v.size()-1;
        return true;
    }

    bool remove(int val){
        if (m.find(val) == m.end()){
            return false;
        }
    
        // swap with last element in the vec, and erase last one
        auto last = v.back();
        v[m[val]] = last;
        m[last] = m[val];
        m.erase(val);
        v.pop_back();
        return true;
    }

    int getRandom(){
        return v[rand() % v.size()];
    }

private:
    using vec_t = vector<int>;
    using map_t = unordered_map<int, int>;

    vec_t v;
    map_t m;
};

int main(){
    RandomizedSet obj;
    bool p1 = obj.insert(1);
    bool p2 = obj.insert(2);
    bool p3 = obj.insert(3);
    cout << obj.getRandom() << endl;

    p1 = obj.remove(1);
    p2 = obj.remove(2);

    cout << obj.getRandom() << endl;

    return 0;
}
