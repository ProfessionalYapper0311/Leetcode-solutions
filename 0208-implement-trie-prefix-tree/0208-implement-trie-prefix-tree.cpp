class TrieNode{
    public:
        unordered_map<char,TrieNode*>children; //hashmap 
        bool endofwords = false; //mark the end of word
};

class Trie {
public:
    TrieNode* root;
    Trie() { 
        root = new TrieNode(); //initialize root to null
    }
    
    void insert(string word) {
        TrieNode* cur = root; //curr to null root

        for(char ch: word){ //iterate through words
            if(!cur->children.count(ch)){ //if not found
                cur->children[ch] = new TrieNode(); //create a new node
            }
            cur = cur->children[ch]; //move to new child and repeat
        }
        cur->endofwords = true; //mark the end as true
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char ch: word){
            if(!cur->children.count(ch)){ //not found
                return false; //false
            }
            cur = cur->children[ch]; //move to next child
        }
        return cur->endofwords; //if true then true or false
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root; //cur to root

        for(char ch: prefix){ //iterate through the prefix
            if(!cur->children.count(ch)){  //not found
                return false; //fasle
            }
            cur = cur->children[ch]; //move to next child
        }
        return true; //true
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */