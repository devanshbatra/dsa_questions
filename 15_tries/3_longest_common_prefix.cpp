#include <iostream>
#include <string>
using namespace std;

//Given a array of N strings, find the longest common prefix among all strings present in the array.
// https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1

//APPROACH 1: (optimal soln.)
/*
1)We will take the first string and traverse it
    a) for every character of this string index we will compare it with other strings of the same index
    b) if all same then push back the character in the ans.
    c) if not same then return the ans.

TC: if avg string length = m and number of strings = n, then O(mn)
SC: O(1) if ans is not included.
*/
string longestCommonPrefix (string arr[], int N)
{
    // your code here
    string first = arr[0];
    
    int i=0;
    string ans = "";
    //for traversing first characters of first string
    while(i<first.length()){
        //for comparing character with rest of the strings.
        for(int j=1; j<N; j++){
            if( i>=arr[j].length() || arr[j][i]!=first[i]){
                return ans;
            }
        }
        ans+=first[i];
        i++;
        
    }
    
    return ans;
    
}

//APPROACH 2: using tries - not good but just finding application of tries.

/*
1) make trienode and trie class
2) insert the strings into the trie.
3) traverse the trie through recursion.
4) at each node check how many children exist
5) if no. of child  = 1 , then add that  child character to ans string.
6) other wise return.


TC: O(mn) - for inserting the words
SC: O(mn) worst
so uppar wala double loop wala soln. he better tha.
*/

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        
        TrieNode(char d){
            data = d;
            isTerminal = false;
            for(int i=0; i< 26; i++){
                children[i] = NULL;
            }
        }
};

class Trie{
    public:
        TrieNode* root;
        
        Trie(){
            root = new TrieNode('\0');
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

class Solution{
  public:
    
    void solve(string& ans, TrieNode* node ){
        int count = 0;
        TrieNode* onlyChild;
        for(int i=0; i<26; i++){
            if(node->children[i]!=NULL){
                count++;
                onlyChild = node->children[i];
                 
            }
        }
        //base case
        if(count!=1) return;
        
        //rc
        ans+=onlyChild->data;
        solve(ans, onlyChild);
    }
    
    string longestCommonPrefix (string arr[], int N)
    {
        Trie* t = new Trie();
        //insert strings into trie
        for(int i=0; i<N; i++){
            t->insert(arr[i]);
        }
        
        //traverse trie till you get other that one child.
        
        string ans="";
        solve(ans, t->root);
        
        return ans;
        
        
    }
};