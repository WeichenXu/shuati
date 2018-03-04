#include <iostream>
#include <map>
#include <cassert>
#include <cmath>

using namespace std;

// method 1: Use a binary search tree to store intervals
// https://leetcode.com/problems/range-module/discuss/108912/C++-vector-O(n)-and-map-O(logn)-compare-two-solutions
// https://www.cs.cmu.edu/~ckingsf/bioinfo-lectures/intervaltrees.pdf
// 
// method 2: Use a segment tree 
// https://leetcode.com/problems/range-module/discuss/108917/C++-Segmented-Tree-O(logL)-addremove-and-O(logL)-query

class RangeModule {
private:
    struct Node{
        Node* m_left{nullptr}, *m_right{nullptr};
        int m_l{0}, m_r{0};
        bool m_tracked{false};
        Node(int l, int r, bool tracked):m_l(l), m_r(r), m_tracked(tracked){}
        // we remove sub segments when parent interval get setted
        static void remove(Node* &node)
        {
            if (node == nullptr) return;
            remove(node->m_left);
            remove(node->m_right);
            delete node;
            node = nullptr;
        }
        // return tracked for this node range[m_l, m_r) in range[ll, rr)
        bool getTracking(int ll, int rr)
        {
            // in case ll,rr is subrange
            if (m_left == nullptr || m_right == nullptr)    return m_tracked;
            if (ll <= m_l && rr >= m_r)  return m_tracked;
            int mid = m_l + (m_r-m_l)/2;
            bool res = true;
            if (ll < mid) res &= m_left->getTracking(ll, rr);
            if (rr > mid) res &= m_right->getTracking(ll, rr);
            return res;
        }
        bool setTracking(int ll, int rr, bool tracked)
        {
            if (ll <= m_l && rr >= m_r)
            {
                remove(m_left);
                remove(m_right);
                return m_tracked = tracked; 
            }
            int mid = m_l + (m_r-m_l)/2;
            if (m_left == nullptr || m_right == nullptr)
            {
                m_left = new Node(m_l, mid, m_tracked);
                m_right = new Node(mid, m_r, m_tracked);
            }
            bool lTracked, rTrakced;
            lTracked = ll < mid ? m_left->setTracking(ll, rr, tracked):m_left->m_tracked;
            rTrakced = rr > mid ? m_right->setTracking(ll, rr, tracked):m_right->m_tracked;
            return m_tracked = lTracked && rTrakced;
        }
    };
public:
    Node* m_root;
    RangeModule() {
        m_root = new Node(0, pow(10,9), false);
    }

    void addRange(int left, int right) {
        m_root->setTracking(left, right, true);
    }

    bool queryRange(int left, int right) {
        return m_root->getTracking(left, right);
    }

    void removeRange(int left, int right) {
        m_root->setTracking(left, right, false);
    }
};

/*
class RangeModule {
private:
    map<int,int> m_ranges;
public:
    RangeModule() {
    }

    void addRange(int left, int right) {
        // locate overlap
        auto l = m_ranges.upper_bound(left);
        auto r = m_ranges.upper_bound(right);
        if (l != m_ranges.begin())
        {
            --l;
            if (l->second < left) ++l;
        }
        if (l!=r)
        {
            left = min(left, l->first);
            right = max(right, prev(r)->second);
            m_ranges.erase(l,r);
        }
        m_ranges[left] = right;
    }

    bool queryRange(int left, int right) {
        auto it = m_ranges.upper_bound(left);
        return it != m_ranges.begin() && prev(it)->second >= right;
    }

    void removeRange(int left, int right) {
        // locate overlaps, insert two new subranges
        auto l = m_ranges.upper_bound(left);
        auto r = m_ranges.upper_bound(right);
        if (l != m_ranges.begin()) 
        {
            --l;
            if (l->second < left) ++l;
        }
        if (l != r)
        {
            int origLeft = min(left, l->first);
            int origRight = max(right, prev(r)->second);
            m_ranges.erase(l,r);
            if (origLeft < left) m_ranges[origLeft] = left;
            if (origRight > right) m_ranges[right] = origRight; 
        }
    }
};
*/

int main()
{
    RangeModule obj;
    obj.addRange(0, 3);
    obj.addRange(6,10);
    assert(true == obj.queryRange(0,2));
    assert(true == obj.queryRange(7,8));
    assert(false == obj.queryRange(9,11));
    obj.removeRange(2,8);
    assert(true == obj.queryRange(1,2));
    assert(true == obj.queryRange(8,10));
    assert(false== obj.queryRange(1,3));
    assert(false== obj.queryRange(9,11));
    assert(false== obj.queryRange(7,8));
}
