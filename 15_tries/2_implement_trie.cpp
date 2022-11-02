#include <iostream>
#include <string>
using namespace std;

//ek to ye ban gayi ek node
class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char d){
            data = d;
            //initializing array and bool .
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }

};

//ab chahiye ek structure jo store kare saari nodes ko (ek root node ke saath connect krke).
class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');//given the root a null character.
        }

        //since we are doing it with recursion, so we need the trienode at different calls so we need
        //another function for the insertion.
        //Think of only one case baaki recursion sambhal lega.

        // babbar method.
        //here we have taken i and increasing it but we can also decrement the first char in the word 
        //every time by using word = word.substr(1)
        //and then we would have to check base case when word lenght reaches to zero.

        void insertWordUtil(string word, int i, TrieNode* node){

            //base case
            if(i>=word.length()) {
                //mark this node as terminal node
                node->isTerminal = true;
                return;
            }

            //recursive calls
            //1) search the node array for the character.
            char c = word[i];
            int charIndex = c-'a'; //assuming only lower case characters.
            if(node->children[charIndex] == NULL ){ //agar node present nhi hai to nyi node bana do
                TrieNode* newnode = new TrieNode(c);
                node->children[charIndex] = newnode;
            }
            insertWordUtil(word, i+1, node->children[charIndex]);//call to next character and next node.
        }

        //main function to insert the word
        void insertword(string word){
            insertWordUtil(word, 0, root); //sending index of word as 0 and start node as root
        }



        //SEARCH - isme babbar wala method se word traverse krenge.
        bool searchUtil(string word, TrieNode* node ){
            //base case
            if(word.length()==0){
                //word to mil gaya but dekh lo terminal node hai ya nhi.
                if(node->isTerminal) return true;
                else return false;
            }
            //rc
            char c = word[0];
            int index = c-'a';
            //agar hai he nhi to return false
            // cout<<"checking if "<<c<<" is present is children of: "<<node->data<<endl;
            if(node->children[index]==NULL) return false;
            
            //rc-bcoz children mein c ki entry present hai
            return searchUtil(word.substr(1), node->children[index]);

        }
        // main search function - util wala recursion.
        bool search(string word){
            return searchUtil(word, root);
        }

        //SIMPLE REMOVAL - It is very simple, we just need to remove the isTerminal of the terminal node and the
                    //word entry would not be considered further.
                    //so first search for the word and then make isTerminal to false.
        
        void removeUtil(string word, TrieNode* node){
            //base case
            if(word.length()==0){
                if(node->isTerminal){
                    node->isTerminal = false;
                    cout<<"word is removed."<<endl;
                    return;
                }
                else{
                    cout<<"word not found, so couldn't be removed"<<endl;
                    return;
                }
            }

            //proc
            char c = word[0];
            int index = c-'a';
            if(node->children[index]==NULL){
                cout<<"word not found, so couldn't be removed"<<endl;
                return;
            }

            //rc
            removeUtil(word.substr(1), node->children[index]);

        }

        void remove(string word){
            removeUtil(word, root);
        }


        //EFFICIENT REMOVAL - In simple removal we saw that whenever we make the isTerminal false we are not
        //                    not deleting any of the extraneous nodes which is a wastage of space.
        //steps for efficient removal
        /*
            1) if word is not present in the trie then return
            2) if word is present and is unique in itself i.e. it is neither a prefix of another word nor it
                has any word as a prefix- then delete all the nodes.
            3) if word is present as prefix of another word- simply turn the isTerminal to false.
            4) if word has another word as a prefix - then start removing the nodes in bottom up manner uptill
                you get another isTerminal = true.

            will implement it later while revising.
        */
        
};

int main(){

    //create a trie.
    Trie* t = new Trie();
    //insertion - Tc: O(L) L: length of word.
    t->insertword("hello");
    t->insertword("arm");
    t->insertword("do");
    t->insertword("time");

    //searching - Tc: O(L) L: length of word.
    string searchWord = "time";
    if(t->search(searchWord)) cout<<searchWord<<" is present."<<endl;
    else cout<<searchWord<<" not present"<<endl;

    //removal - TC: O(L), L: length of word.
    // t->remove("hell"); //will print: could not be removed.
    t->remove("hello");

    //searching hello again to check if removed or not.
    // searchWord = "hello";
    // if(t->search(searchWord)) cout<<searchWord<<" is present."<<endl;
    // else cout<<searchWord<<" not present"<<endl;

    return 0;
}


//ADVANTAGE OF TRIE OVER MAP - in dictionary problem
// we saw that trie also take O(L) time complexity for all three tasks then why it is better.
//1) It uses the space in an efficient manner.
//   suppose we want to save the word - ARM, ARMADILO, ARE, ARJOO.
//   Then map would store an entry for each and every word like it create 5 entries in bucket arrays for A
//   But if we use trie then there would be only one entry for A and R.

//2) Whenever we search somethng on google or zomato then we get automated suggestion that suggest us the 
//   words with the initials typed , this implementation is very much easier and save time complexity in case
//   of tries as we just need to see the available words ahead. and in case of maps we may have to traverse 
//   the whole map again to search for the initials.