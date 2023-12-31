class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<int, pair<int, int>>> pq; //max heap
        for(int i =0; i< points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y; //beautiful 
            pq.push({dist, {x,y}}); //beautiful - defalt operator checks 1st mem of pair 
            if(pq.size() > k) //beautiful 
            {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int x = p.second.first;
            int y = p.second.second;
            ans.push_back({x,y});
        }

        return ans;
    }
};