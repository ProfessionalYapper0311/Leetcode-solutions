class WDNode{
    public:
    unordered_map<char, WDNode*> children; //hashmap to find and locate words
    bool endofwords = false; //to mark the end of the word
};

class WordDictionary {
public:
    WDNode * root;

    WordDictionary() {
        root = new WDNode();
    }
    
    void addWord(string word) {    
        WDNode * cur = root;
        for(char ch : word){
            if(!cur->children.count(ch)){
                cur->children[ch] = new WDNode();
            }
            cur = cur->children[ch];
        }
        cur->endofwords = true;
    }
    bool searchUtil(WDNode* root, const string& word, int idx){
        WDNode * cur = root;
        for(int i=idx; i<word.size(); i++){ //idx = 0 passed here
            char ch = word[i];

            //special case at ch == '.'
            if(ch == '.'){
                for(auto& [chara, childpointer]: cur->children){
                    if(searchUtil(childpointer, word, i+1)) return true;
                }
                return false;
            }
            //special case end

            //normal case
            if(!cur->children.count(ch)){
                return false;
            }
            cur = cur->children[ch];
        }
        return cur!=nullptr && cur->endofwords;
    }
    bool search(string word) {
        return searchUtil(root, word, 0); //pass the idx of word
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */