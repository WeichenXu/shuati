class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (const auto& ni:nestedList){
            cur.push_back(ni);
        }
    }

    int next() {
        auto val = cur.front().getInteger();
        cur.pop_front();
        return val;
    }

    bool hasNext() {
        while(!cur.empty() && !(cur.front().isInteger()) ){
            auto ni = cur.front();
            cur.pop_front();
            // insert in reverse order
            auto nxList = ni.getList();
            int size = nxList.size();
            for (int i=size-1; i>=0; --i){
                cur.push_front(nxList[i]);
            }
        }
        return !cur.empty();
    }
private:
    deque<NestedInteger> cur;
};
