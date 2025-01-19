/*
211. Design Add and Search Words Data Structure
https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
*/
class TrieNode{
    public:
    bool terminal;
    TrieNode* children[26];

    TrieNode(){
        terminal=false;
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr=root;
        for(int i=0;i<word.size();i++){
            int index=word[i]-'a';
            if(curr->children[index]==NULL){
                curr->children[index]=new TrieNode();
            }
            curr=curr->children[index];
        }
        curr->terminal=true;
    }
    
    bool find(string word,TrieNode* curr){
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                for(int j=0;j<26;j++){
                    if(curr->children[j]!=NULL)
                        if(find(word.substr(i+1),curr->children[j])) return true;
                }
                return false; // if above all 26 iteration false then we return false, kyuki find method ne bh false return kar diya
            }
            else{
                int index=word[i]-'a';
                if(curr->children[index]==NULL) return false;
                else curr=curr->children[index];
            }
        }
        return curr->terminal;
    }
    bool search(string word) {
        return find(word,root);
    }
};
