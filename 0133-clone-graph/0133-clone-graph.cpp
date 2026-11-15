/*
class Solution {
public:
    unordered_map<Node*, Node*>mp; //globally define the map<old node, new node>

    void DFS(Node* node, Node* clone_node){
        //iterate through the neighbors
        for(Node* n : node->neighbors){
            if(mp.find(n) == mp.end()){
                Node *clone = new Node(n->val); //create the new clone
                mp[n] = clone; //map it to n
                clone_node->neighbors.push_back(clone); //push back the clone
                DFS(n, clone); //recursively call dfs again
            }
            else{
                clone_node->neighbors.push_back(mp[n]); //clone that is mapped to n
            }
        }
    }

    Node* cloneGraph(Node* node) {
          if(!node){
            return nullptr;
          }

          mp.clear(); //clear for every call

          Node* clone_node = new Node(node->val); //create the clone of the given node

          mp[node] = clone_node; //map the cloned node to node

          DFS(node, clone_node);
          return clone_node; //return the cloned node, not the original node
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>mp; //globally define the map<old node, new node>

    void BFS(queue<Node*>&que){
        while(!que.empty()){
            Node *node = que.front();
            Node *clone_node = mp[node];
            que.pop();

            for(Node *n : node->neighbors){
                if(!mp.count(n)){
                    Node *clone = new Node(n->val);
                    mp[n] = clone;
                    clone_node->neighbors.push_back(clone);

                    que.push(n); //insert the new node to be clone
                }
                else{
                    clone_node->neighbors.push_back(mp[n]);
                }
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        mp.clear();

        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;

        queue<Node*>que;
        que.push(node);
        BFS(que);

        return clone_node;
    }
};