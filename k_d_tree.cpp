#include <iostream>
#include <memory>
#include <array>
#include <vector>

#include <assert.h>

using namespace std;

class k_d_tree{
public:
    using point_t = array<int, 2>;
    k_d_tree(int d):dimension(d){
    }
    ~k_d_tree(){}
    
    void insert(const point_t& pt){
        root = insert_recursive(pt, root, 0);
    }

    bool find(const point_t& pt) const {
        return find_recursive(pt, root, 0);
    }

    vector<point_t> range_query(point_t &upLeft, point_t &downRight){
        vector<point_t> pts;
        range_query_helper(root, 0, upLeft, downRight, pts);
        return pts;
    }
    
    /*
    array<int, 2> nearest_neighbor(){
    
    }
    */
private:
    class node{
    public:
        node(const array<int, 2>& v){
            val = v;
        }
        array<int, 2> val;
        shared_ptr<node> left{nullptr}, right{nullptr};
    };
    int dimension{0};
    shared_ptr<node> root;

    bool find_recursive(const point_t &pt, shared_ptr<node> cur, int depth) const{
        if (cur == nullptr){
            return false;
        }    
        // compare the elements
        if (pt == cur->val){
            return true;
        }
        int d = depth%dimension, v = cur->val[d];
        if (pt[d] <= v){
            return find_recursive(pt, cur->left, depth+1);
        }
        return find_recursive(pt, cur->right, depth+1);
    }
    
    shared_ptr<node> insert_recursive(const point_t& pt, shared_ptr<node> cur, const int depth){
        if (cur == nullptr){
            return make_shared<node>(pt);
        }
        int d = depth%dimension, v = cur->val[d];
        if (pt[d] <= v){
            cur->left = insert_recursive(pt, cur->left, depth+1);
        }
        else{
            cur->right = insert_recursive(pt, cur->right, depth+1);
        }
        return cur;
    }

    bool inBound(const point_t &pt, const point_t &upL, const point_t &doR){
        
        for (int i=0; i<2; ++i){
            if ( (pt[i] - upL[i]) * (pt[i] - doR[i]) > 0)
                return false;
        }
        return true;
    }
    void range_query_helper(shared_ptr<node> cur, int depth, const point_t &upL, const point_t &doR, vector<point_t>& res){
        if (cur == nullptr){
            return;
        }
        cout << "Range search... " << cur->val[0] << ", " << cur->val[1] 
             << ", " << inBound(cur->val, upL, doR) << endl;
        cout << "Bound " << upL[0] << ", " << upL[1] << "; " << doR[0] << ", " << doR[1] << endl;
        if (inBound(cur->val, upL, doR)){
            res.push_back(cur->val);
        }
        int d = depth%dimension, v = cur->val[d];
        if (v >= doR[d]){
            range_query_helper(cur->left, depth+1, upL, doR, res); 
        } 
        else if (v < upL[d]){
            range_query_helper(cur->right, depth+1, upL, doR, res);
        }
        else {
            range_query_helper(cur->left, depth+1, upL, doR, res);
            range_query_helper(cur->right, depth+1, upL, doR, res);
        }
        return;
    }
};

// Test Insert/Find of the 2-d-tree
int main(){
    vector<array<int, 2>> pts={
        {0,0},
        {0,1},
        {-1, 2},
        {-2, -1}
    };
    k_d_tree t(2);
    for(const auto&pt:pts){
        t.insert(pt);
    }

    for(const auto&pt:pts){
        assert( t.find(pt) == true );
    }
    
    cout << "Pass the Find tests" << endl;

    assert( t.find({-1, -1}) == false );
    assert( t.find({1, -1}) == false );
    assert( t.find({1, 2}) == false );
    
    cout << "Pass the NOT Find tests" << endl;
    array<int, 2> uL = {-2, -1}, dR = {0, 1};
    auto res = t.range_query(uL, dR);
    for (const auto&pt:res){
        cout << pt[0] << ", " << pt[1] << endl;
    }
    //assert( res.size() == 2);
    return 0;
}
