#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int clr,int i ,vector<vector<int>>& graph,vector<int> &color){
        // cout<<i<<" "<<clr<<endl;
        color[i]=clr;
        for(auto adj:graph[i]){
            if(color[adj]==-1) {if(!dfs(!clr,adj,graph,color)){return false;}}
            else if(color[adj]==clr) {return false;}
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        //well use dfs
        //bipartitle means no cycle or two adjacent doest have sam
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if (dfs(0,i,graph,color)==false) return false;
            }
        }
        return true;
    }
};