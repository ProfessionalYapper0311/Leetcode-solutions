class Solution {
public:
    bool getTopologicalCheck(unordered_map<int, vector<int>> &adj, int nc, vector<int> &indegree){
        queue<int>que;  
        int count = 0;

        for(int i=0; i<nc; i++){
            if(indegree[i] == 0){
                count++;
                que.push(i);
            }
        }

        while(!que.empty()){
            int u = que.front(); que.pop();

            for(int &v: adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    count++;
                    que.push(v);
                }
            }
        }
        if(count == nc) return true;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>>adj;
        vector<int>indegree(numCourses, 0);

        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];

            //b --> a (a, bz)
            adj[b].push_back(a);
            indegree[a]++;
            }

            return getTopologicalCheck(adj, numCourses, indegree); //send graph, nc, indegree
        }
};




















/*
class Solution {
public:
    bool topologicalSortCheck(unordered_map<int, vector<int>> &adj, int num_c, vector<int> &indegree){
        queue<int>que; //create a queue
        int visited = 0;

        for(int i=0; i<num_c; i++){
            if(indegree[i] == 0){ //no incoming nodes, pusht 2 queue
                visited++; //visited node
                que.push(i);
            }
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(auto &v : adj[u]){ //from u to v no. of nodes visited
                indegree[v]--; //one node visited, less incoming nodes, we can go from u to v
                if(indegree[v] == 0){
                    visited++;
                    que.push(v);
                }
            }
        }
        if(visited == num_c) return true; //i was able to finsih all courses, no cycle

        return false; //means there was a cycle and courses were left
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //plot the graph for kahn's algo or bfs, topo sort for dfs -> cycle detection

        unordered_map<int, vector<int>> adj; //1 -> 0, 3 etc
        vector<int> indegree(numCourses, 0); //nodes incoming

        for(auto &vec: prerequisites){
            int a = vec[0];
            int b = vec[1];
            //b-->a
            adj[b].push_back(a);
            // -->a or towards a
            indegree[a]++;
        }

        return topologicalSortCheck(adj, numCourses, indegree);
    }
};
*/
