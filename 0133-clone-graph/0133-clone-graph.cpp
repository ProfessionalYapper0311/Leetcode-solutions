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