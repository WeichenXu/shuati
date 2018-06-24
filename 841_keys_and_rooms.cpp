class Solution {
    vector<bool> m_visited;
    int m_count;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int size = rooms.size();
        m_visited.resize(size, false);
        ++m_count;
        m_visited[0] = true;
        queue<int> q;
        q.push(0);
        while (not q.empty())
        {
            int i = q.front();
            q.pop();
            for (auto nx:rooms[i])
            {
                if (not m_visited[nx])
                {
                    m_visited[nx] = true;
                    q.push(nx);
                    ++m_count;
                }
            }
        }
        return m_count == size;
    }
};
