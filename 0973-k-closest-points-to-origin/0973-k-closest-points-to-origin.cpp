
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y;
            pq.push({dist, {x, y}});
        }

        vector<vector<int>> ans;
        int i = 0;
        while (i++ < k )
        {
            auto p = pq.top();
            pq.pop();
            int x = p.second.first;
            int y = p.second.second;
            ans.push_back({x, y});
        }

        return ans;
    }
};
