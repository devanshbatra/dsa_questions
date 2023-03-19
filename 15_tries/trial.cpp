#include<iostream>
#include<string>

using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            //initialize children with NULL
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
                //ab connect bhi toh karna hai root se
                root->children[index] = child;
            }

            insertUtil(child, word.substr(1));

        }

        void insertWord(string word){
            insertUtil(root, word);
        }


        //search

        bool searchUtil(TrieNode* root, string word){
            //base case
            if(word.length()==0){
                if(root->isTerminal) return true;
                else return false;
            }


            //rc
            int index = word[0]-'a';
            if(root->children[index]!=NULL){
                return searchUtil(root->children[index], word.substr(1));
            }else{
                return false;
            }
        }

        bool searchWord(string word){
            return searchUtil(root, word);
        }


        //deletion
        void deleteUtil(TrieNode* root, string word){
            //base case
            if(word.length()==0){
                if(root->isTerminal) {
                    root->isTerminal = false;
                    cout<<"word deleted successfully!"<<endl;
                }
                else{
                    cout<<"word not found"<<endl;
                }
                return ;
            }


            //rc
            int index = word[0]-'a';
            if(root->children[index]!=NULL){
                deleteUtil(root->children[index], word.substr(1));
            }else{
                cout<<"word not found"<<endl;
                return ;
            }
        }
        
        void deleteWord(string word){
            return deleteUtil(root, word);
        }



};




int main(){

    Trie* t = new Trie();

    t->insertWord("hell");
    t->insertWord("hello");
    t->insertWord("world");
    t->insertWord("word");

    //searching for the word
    cout<<t->searchWord("hell")<<endl;
    cout<<t->searchWord("hel")<<endl;
    cout<<t->searchWord("word")<<endl;
    cout<<t->searchWord("world")<<endl;
    cout<<t->searchWord("wor")<<endl;
    cout<<t->searchWord("worlde")<<endl;


    //deleting a word
    t->deleteWord("helld");
    t->deleteWord("hel");
    t->deleteWord("worl");
    t->deleteWord("hell");
    
    cout<<t->searchWord("hell")<<endl;



    return 0;
}