class Solution {
public:
    
    bool canFinish(int nodes, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(nodes );
            vector<int> indeg(nodes , 0);


    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
         indeg[prerequisites[i][0]]++;
    }


//     for (int i = 0; i < nodes; i++)
//     {

//         for (auto it : adj[i])
//         {
//             indeg[it]++;
//         }
//     }


queue<int> q;
vector<int> ans;

for(int i = 0; i < nodes; i++)
{
    if (indeg[i] == 0){
        q.push(i);
        ans.push_back(i);}
}


while (!q.empty())
{

    int node = q.front();
    q.pop();

    for (auto it : adj[node])
    {
        indeg[it]--;
        if (indeg[it] == 0)
        {
            ans.push_back(it);

            q.push(it);
        }
    }
}
return ans.size()==nodes;
    }
};