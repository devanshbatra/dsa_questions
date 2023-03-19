// https://leetcode.com/problems/word-break/description/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

//We could use unord map in place of trie here but we just wanted to implement trie as complexity of searching
//is also low with trie

//approach:
//here we will be using the trie just for the purpose of storing and searching of word

//so first add all the words in the trie
// also design a searching algo in trie.

//recursive solution:
//traverse the string.
//start from index=0;
//at every index see if the word formed till now(stored in processString) is found in the trie or not.
//if not found then continue with next index.
//if word found in trie - then we have two options.
//either continue with same processString.
//or clear the string and go to next index.
//see this example: ["hell","hello","world"] and string : "helloworld"

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }

};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        //insertion
        void insertUtil(TrieNode* root, string word){
            //base case
            if(word.length()==0){
                root->isTerminal = true;
                return;
            }


            //rc
            int index = word[0]-'a';
            TrieNode* child;

            if(root->children[index]!=NULL){
                child = root->children[index];
            }
            else{
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            insertUtil(child, word.substr(1));

        }

        void insertWord(string word){
            insertUtil(root, word);
        }

        //search words
        bool searchUtil(TrieNode* root, string word){
            //base case
            if(word.length()==0){
                if(root->isTerminal==true) return true;
                else return false;
            }

            //rc
            int index = word[0]-'a';
            if(root->children[index]!=NULL){
                return searchUtil(root->children[index], word.substr(1));
            }
            else return false;
        }


        bool searchWord(string& word){
            return searchUtil(root, word);
        }

};


bool solve(string word, Trie* t, unordered_map<string, bool>& dp){
    //base case
    //kabhi word pura 0 length ka hoga he nahi. - tabhi ho sakta h, agar left poora poora word he ho aur t mein present ho.
    //so usi ko base case bana lete hn
    if(t->searchWord(word)) return true;

    if(dp.count(word)) return dp[word];

    //rc
    int n = word.length();
    for(int i=0; i<n; i++){
        //make partition at i 0->i & i+1->n-1
        string left = word.substr(0, i+1);
        string right = word.substr(i+1);


        //check if left is found in trie
        if(t->searchWord(left)){
            bool restOfString = solve(right, t, dp);
            if(restOfString==true) return dp[word] = true;
        }

    }

    //agar ab tak true return nahi hua h means is word se toh nhi ho pa rha.
    return dp[word] = false;

}


bool wordBreak(string s, vector<string>& wordDict) {
    Trie* t = new Trie;
    for(auto& st: wordDict){
        t->insertWord(st);
    }
    
    unordered_map<string, bool> dp; //different strings can exist for different indexes.
    return solve(s, t, dp);

    
}