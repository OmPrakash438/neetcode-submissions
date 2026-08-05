class TrieNode{
public:
    TrieNode* link[26];
    bool flag = false;

    TrieNode(){
        for(int i = 0; i < 26; i++)
            link[i] = nullptr;
    }

    bool containsChar(char ch){
        return (link[ch - 'a'] != NULL);
    }

    void put(char ch, TrieNode* node){
        link[ch - 'a'] = node;
    }

    TrieNode* get(char ch){
        return link[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class PrefixTree {
TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* dummy = root;
        for(int i=0; i<word.size(); i++){
            if(!dummy->containsChar(word[i])){
                dummy->put(word[i], new TrieNode());
            }

            dummy = dummy->get(word[i]);
        }

        dummy->setEnd();
    }
    
    bool search(string word) {
        TrieNode* dummy = root;
        for(int i=0; i<word.size(); i++){
            if(!dummy->containsChar(word[i])){
                return false;
            }

            dummy = dummy->get(word[i]);
        }

        return dummy->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* dummy = root;
        for(int i=0; i<prefix.size(); i++){
            if(!dummy->containsChar(prefix[i])){
                return false;
            }

            dummy = dummy->get(prefix[i]);
        }

        return true;
    }
};
