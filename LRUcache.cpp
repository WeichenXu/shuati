#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class LRUCache{
    public:
        LRUCache(int capacity):
            capacity_(capacity)
    {
        key_map.reserve(capacity);
    }

        int get(int key) {
            auto it = key_map.find(key);
            if (it == key_map.end()){
                return -1;
            }
            // hit the cache
            hitCache(it);
            return it->second.first;
        }

        void set(int key, int value) {
            auto it = key_map.find(key);
            if (it == key_map.end()){
                if (capacity_ <= 0){
                    return;
                }
                // inserted new cache
                // remove old one if it exceeds capacity
                if (key_map.size() >= capacity_){
                    // remove the last one in list item
                    key_map.erase(list_items.back());
                    list_items.pop_back();
                }
                list_items.push_front(key);
                key_map[key] = {value, list_items.begin()};
            }
            else {
                // hit cache
                hitCache(it);
            }

        }
    private:
        using key_t = int;
        using value_t = int;
        // use a list to store the double linked items
        using list_items_t = list<key_t>;
        list_items_t list_items;
        // use a map to store the mapping between the key and the iterator in the cache
        using pair_t = pair<value_t, list_items_t::iterator>;
        using key_map_t = unordered_map<key_t, pair_t>;
        key_map_t key_map;

        int capacity_{0};
        // utility function to move the item A to list head, update the iterator in list
        void hitCache(key_map_t::iterator &it){
            // move the key ahead
            list_items.erase(it->second.second);
            list_items.push_front(it->first);
            // update the iterator in the map
            it->second.second = list_items.begin();
        }
};

int main(){
    LRUCache cache(10);
    cache.set(0, 10);
    cout << cache.get(0) << endl;
    return 0;
}
