
class Solution {
public:
int m, n;
vector<string>result; //output stored here
vector<vector<int>>directions{ {1, 0} ,{-1, 0}, {0, 1}, {0, -1} }; //directions
    struct trienode{ //initialize ur trienode
        string word;
        bool EOW;
        trienode *children[26]; //26 letters of alphabet
    };

    trienode *getNode(){ //create a new node and set the para
        trienode *node = new trienode();
        node->word = ""; 
        node->EOW = false; 
        for(int i=0; i<26; i++){ //set all 26 char to null
        node->children[i] = nullptr;
        }
        return node;
    }
    //pass the root and insert all the word
    void insert(trienode *root ,string &word){
        trienode * cur = root;

        //check if the child is present
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            if(!cur->children[ch - 'a']){ //if not create a new node
                cur->children[ch-'a'] = getNode();
            }
            cur = cur->children[ch-'a']; //move to that node
        }
        cur->EOW = true; //end of node
        cur->word = word;   
    }
            void dfs(vector<vector<char>>& board, int i, int j, trienode *root){
            if(i<0 || j<0 || i>=m|| j>=n){
                return; 
            }

            if(board[i][j] == '$' || root->children[board[i][j] - 'a'] == NULL){
                return;
            }

            root = root->children[board[i][j] - 'a'];
            if(root->EOW == true){
                result.push_back(root->word);
                root->EOW = false;
            }

            //dfs after that point
            char temp = board[i][j];
            board[i][j] = '$'; //mark as visitied

            //up down, right , left
            for(auto &dir: directions){
                int new_i = i + dir[0]; 
                int new_j = j + dir[1];

                dfs(board, new_i, new_j, root);
            }

            //exlored, unmarked
            board[i][j] = temp;            
        }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words){
        m = board.size(); //row
        n = board[0].size(); //col

        trienode *root = getNode(); //create root
        for(string &word : words){ //insert the word, create the trie
            insert(root, word);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                char ch = board[i][j];

                if(root->children[ch-'a']){ //word found in trie
                    dfs(board, i, j, root); //call dfs and search for the rest
                } 
            }
        }

        return result;
    }
};