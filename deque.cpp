#include <iostream>
#include <list>
#include <unordered_map>
template<class Obj>
class deque{
// support O(1) time for following operation
public:
    void push_back(const Obj& item){
        item_list_.push_back(item);
        iterator_map_[offset_ + size_++] = std::prev(item_list_.end());
    }
    void pop_back(){
        if (size_ > 0){
            item_list_.erase(iterator_map_[offset_ + --size_]);
            iterator_map_.erase(size_);
        }
    }
    void push_front(const Obj& item){
        --offset_, ++size_;
        item_list_.push_front(item);
        iterator_map_[offset_] = item_list_.begin();
    }
    void pop_front(){
        if(size_ > 0){
            item_list_.erase(iterator_map_[offset_]);
            iterator_map_.erase(offset_);
            --size_;
            ++offset_;
        }
    }
    Obj operator[](int idx){
        auto it = iterator_map_[idx+offset_];
        return *it;
    }
private:
    using item_list_t = std::list<Obj>;
    using iterator_map_t = std::unordered_map<int,typename std::list<Obj>::iterator>;
    item_list_t item_list_;
    iterator_map_t iterator_map_;
    // the number of items inserted(deleted) in the head
    int offset_{0};
    int size_{0};
};

int main(){
    deque<int> dq;
    dq.push_back(0);
    dq.push_back(1);
    dq.pop_back();
    std::cout << dq[0] << std::endl;
    dq.push_front(-1);
    std::cout << dq[1] << std::endl;
    dq.pop_front();
    std::cout << dq[0] << std::endl;
    return 0;
}
