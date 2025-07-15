#include <iostream>
using namespace std;

/*You are required to complete this method */
class Node{
    public:
        Node* links[26];
        
        bool containsKey(char ch){
            return (links[ch - 'a'] != NULL);
        }
        
        Node* get(char ch){
            return links[ch - 'a'];
        }
        
        void put(char ch, Node* node){
            links[ch - 'a'] = node;
        }
};

int countDistinctSubstring(string s) {
    // Your code here
    int count = 0;
    Node* root = new Node();
    
    for(int i = 0; i < s.length(); i++){
        
        Node* node = root; 
        for(int j = i; j < s.length(); j++){
            if(!node -> containsKey(s[j])){
                count++;
                node -> put(s[j], new Node());
            }
            node = node -> get(s[j]);
        }
    }
    
    return count + 1;
}

int main(){
    string s = "abab";

    cout<<countDistinctSubstring(s)<<endl;

    return 0;
}