class ExamRoom {
    list<int> m_l;
    unordered_map<int, list<int>::iterator> m_map;
    int m_size;
public:
    ExamRoom(int N) {
        m_size = N-1;
    }

    int seat() {
        if (m_l.empty())
        {
            m_l.push_back(0);
            m_map[0] = m_l.begin();
            return 0;
        }
        auto it = m_l.begin();
        auto insert = it;
        int maxD = -1, pos = -1, pre=-1, dis;
        while(1)
        {
            int cur = it==m_l.end()?m_size:*it;
            if (it == m_l.begin()) dis = cur-0-1;
            else if (it == m_l.end()) dis = cur-pre-1;
            else dis = (cur-pre)/2 - 1;
            if (dis > maxD)
            {
                maxD = dis;
                if (it == m_l.begin())  pos = 0;
                else if (it == m_l.end())   pos = m_size;
                else pos = pre+dis+1;
                insert = it;
            }
            if (it == m_l.end())    break;
            pre = *(it++);
        }
        //cout << pos << endl;
        m_map[pos] = m_l.insert(insert, pos);
        return pos;
    }

    void leave(int p) {
        m_l.erase(m_map[p]);
        m_map.erase(p);
    }
};
