//We have to implement a suggestion based system which suggest words based on the given prefix
//https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666?leftPanelTab=0

#include <iostream>
#include <vector>
#include <string>
using namespace std;



class TrieNode{
    public:
        char data;
        bool isTerminal;
        TrieNode* children[26];
        
        TrieNode(char d){
            data = d;
            isTerminal = false;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
        }
};

class Trie{
    public:
        TrieNode* root;
        Trie(){
            root= new TrieNode('\0');
        }
        
        void insertUtil(string word, TrieNode* node){
            //base case
            if(word.length()==0){
                node->isTerminal = true;
                return;
            }
            //rc
            char c = word[0];
            int index = c-'a';
            if(node->children[index]==NULL){
                TrieNode* newnode = new TrieNode(c);
                node->children[index] = newnode;
            }
            insertUtil(word.substr(1), node->children[index]);
        }
    
        void insert(string word){
            insertUtil(word, root);
        }
};

//idhar ek tarah se depth first search lagai hai aise tree mein jisme multiple children ho skte hn.
void findAllSugg(TrieNode* node, vector<string>& temp, string prefix){
    if(node->isTerminal){
//         cout<<prefix;
        //yaha aaya hai to matlap node ka data prefix mein already added hai.
        temp.push_back(prefix);
    }
    
    for(int i=0; i<26; i++){
        if(node->children[i]!=NULL){
            prefix+=node->children[i]->data;
            findAllSugg(node->children[i], temp, prefix);
            //backtrack
            prefix.pop_back();
        }
    }
    
}

//approach: ham bas string mein traverse karte jayenge aur trie mein dhoondte jaayenge ki char present hai
//ya nhi , agar hai to find all words below it wala funct call.
// also agli iteration ke liye currPointer ko update bhi krte jayenge.
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie* t = new Trie();
    for(auto i: contactList){
        t->insert(i);
    }
    
    //now trie has all the contacts
    int n = queryStr.length();
    string prefix = "";
    TrieNode* currNode = t->root;
    vector<vector<string>> ans;
    for(int i=0; i<n; i++){
        char currChar = queryStr[i];
//         cout<<endl<<"finding if "<<currChar<<" exists after "<<prefix<<endl;
        prefix+=currChar;
        //char found
        if(currNode->children[currChar-'a']!=NULL){
            vector<string> temp;
            findAllSugg(currNode->children[currChar-'a'], temp, prefix);
            ans.push_back(temp);
            //updating currNode taki next character of string ke liye yaha se he search shuru kare.
            currNode = currNode->children[currChar-'a'];
        }
        else{
            //char not found
            break;
        }
        
    }
    return ans;
}