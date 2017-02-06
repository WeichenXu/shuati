#include <iostream>
#include <vector>
#include <array>
#include <memory>

using namespace std;

// 1. this is a n-ary tree
//    * the size of children is not fixed
//    * the pointer is from the children to the parent
// 2. give the array (tree) and one of the node, delete the node

class N_Array_Tree{
private:
    static constexpr int N{5};
    using node_t = pair<int, int>;
    using node_vec_t = vector<shared_ptr<node_t>>;
    node_vec_t nodes_;
public:
    explicit N_Array_Tree(int n){
        nodes_.resize(n);
        for (int i=0; i<n; ++i){
            nodes_[i] = make_shared<node_t>();
        }
    }

    // use an array to mark whether the current node should be erased 
    // use bfs
    void remove(int index){
        array<int, N> flags = {0};
        flags[index] = 1;
        bool finded = true;
        while(finded){
            finded = false;
            for (int i=0; i<N; ++i){
                if(!flags[i] && flags[nodes_[i]->second]){
                    finded = true;
                    flags[i] = 1;
                }
            }
        }
        for (int i=0; i<N; ++i){
            if (flags[i]){
                nodes_[i] = nullptr;
            }
        }
    }
    node_t& operator[](int index){
        return *(nodes_[index]);
    } 
    // debug helper
    void print() const {
        int i=0;
        for (auto&ptr:nodes_){
            if(ptr != nullptr){
                cout << "Index: " << i << ", val: " << ptr->first << ", parent: " << ptr->second << endl;
            }
            ++i;
        }
    }
};

int main(){
    int size = 5;
    N_Array_Tree tree(size);
    tree[0].second = 0;
    tree[1].second = 0;
    tree[2].second = 1;
    tree[3].second = 1;
    tree[4].second = 2;
    tree.print();
    cout << "After remove index 1" << endl;
    tree.remove(1);
    tree.print();
    return 0;
}
