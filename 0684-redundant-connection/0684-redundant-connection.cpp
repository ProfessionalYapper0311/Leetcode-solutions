class Solution {
public:
    bool dfs(int u, int v, unordered_map<int, vector<int>>&adj, vector<bool>&visited){
        visited[u] = true; //visited first node

        if(u == v){
            return true;
        } //u has reached v

        for(auto &ngbhr : adj[u]){
            if(visited[ngbhr]) continue;

            if(dfs(ngbhr, v, adj, visited)){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        //graph
        unordered_map<int, vector<int>>adj; 
        

        for(int i=0; i<n; i++){
            int u = edges[i][0]; //node 1 
            int v = edges[i][1]; //node 2
            vector<bool>visited(n+1, false); //n+1 steps
            
            //if nodes are there and connectes
            if( adj.count(u) && adj.count(v) && dfs(u, v, adj, visited) ){
                return edges[i]; //connected so return 
            }

            adj[u].push_back(v); //u->v
            adj[v].push_back(u); //v->u
        }
        return {}; //return empty array
    }
};
