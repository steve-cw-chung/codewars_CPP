/* Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search. */

/*
class TrieNode {
public:
    TrieNode *next[26]{};
    bool is_leaf = false;
    TrieNode *get(char c) { return next[c - 'a']; }
    void add(char c) { next[c - 'a'] = new TrieNode; }
};

class WordDictionary {
public:
    WordDictionary() : root(new TrieNode) {}
    void addWord(const string &word) {
        auto p = root;
        for (auto c : word) {
            if (!p->get(c)) p->add(c);
            p = p->get(c);
        }
        p->is_leaf = true;
    }
    bool search(const string &word) {  return search(word, 0, root); }
private:
    bool search(const string &word, int pos, TrieNode *root) {
        if (pos == word.size()) return root->is_leaf;
        if (word[pos] != '.') {
            root = root->get(word[pos]);
            return root ? search(word, pos + 1, root) : false;
        }
        for (auto i = 0; i < 26; ++i)
            if (root->next[i] && search(word, pos + 1, root->next[i]))
                return true;
        return false;
    }
    TrieNode *root;
};
*/

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class WordDictionary {
    
public:
    
    class TrieNode{
        
        public:
            static int const ALPHABET_SIZE = 26;
            TrieNode * children [ALPHABET_SIZE];
            bool endOfWord;
            TrieNode(){
                for(int i =0; i<ALPHABET_SIZE; i++){
                    children[i]=NULL;
                }    
                endOfWord = false;
            }
            
    };
    TrieNode * head;
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode * cur = head;
        int index =0;
        for(int i = 0; i<word.length();i++){
            
            char c = tolower(word[i]);
            index = c- 'a';
            
            if(!(cur->children[index])){
                cur->children[index] = new TrieNode();
            }
               cur = cur->children[index];
        }
        cur->endOfWord = true;
    }
    bool search(string word){
        return search(word,0,head);
    }
    bool search(string word, int pos, TrieNode * cur){
        if(pos==word.size()){return cur->endOfWord;}
        if (word[pos] != '.') {
            int index = word[pos] - 'a';
            cur= cur->children[index];
            return cur ? search(word, pos + 1, cur) : false;
        }
        for (auto i = 0; i < 26; ++i)
            if (cur->children[i] && search(word, pos + 1, cur->children[i]))
                return true;
        return false;
    }