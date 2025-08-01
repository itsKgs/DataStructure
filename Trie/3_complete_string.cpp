// User function Template for C++
#include <iostream>
#include <vector>
using namespace std;

struct Node{
    
    Node *links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    
    Node *get(char ch){
        return links[ch - 'a'];
    }
    
    void put(char ch, Node *node){
        links[ch - 'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
        Node *root;
        
    public:
        Trie(){
            root = new Node();
        }
        
        void insert(string word){
            
            Node* node = root;
            
            for(int i = 0; i < word.length(); i++){
                if(!node -> containsKey(word[i])){
                    node -> put(word[i], new Node());
                }
                node = node -> get(word[i]);
            }
            node -> setEnd();
        }
        
        bool checkIfPrefixExists(string word){
            
            Node* node = root;
            
            for(int i = 0; i < word.length(); i++){
                if(node -> containsKey(word[i])){
                    node = node -> get(word[i]);
                    if(node -> isEnd() == false) return false;
                }
                else{
                    return false;
                }
            }
            return true;
        }
        
        
};

//class Solution {
//    
//    public:
//
//    
//};

string longestString(vector<string> &words) {
    // code here
    Trie trie;
    
    for(auto &it: words){
        trie.insert(it);
    }
    
    string longest = "";
    
    for(auto &it: words){
        if(trie.checkIfPrefixExists(it)){
            if(it.length() > longest.length()){
                longest = it;
            }
            else if(it.length() == longest.length() && it < longest /*(lexically small)*/){
                longest = it;
            }
        }
    }
    
    if (longest == "") return "";
    return longest;
    
}

int main(){
    
    vector<string> s{"p", "pr", "pro", "probl", "problem", "pros", "process"};

    cout<<longestString(s)<<endl;

    return 0;
}