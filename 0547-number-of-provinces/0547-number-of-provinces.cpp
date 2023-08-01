class Solution {
public:
    void dfs(int node , vector<vector<int>>& isConnected,vector<int> &vis){
        vis[node]=1;
        for (int i = 0; i < isConnected.size(); i++)
        {
            if(isConnected[node][i]==1 && !vis[i]){
                dfs(i,isConnected,vis);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //given is adjaceny matrix
        int n = isConnected.size();
        vector<int> vis(n,0);
        int count=0;
        for(int i = 0;i<isConnected.size();i++){
            if(!vis[i]){
                count++;
                dfs(i,isConnected,vis);
            }
        }
        return count;
    }
};