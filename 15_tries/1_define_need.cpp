/*
WHY DO WE NEED TRIE?
- Suppose there is a problem to make a dictionary of words
    and do the operations like: 
                1) add word
                2) search word
                3) erase/remove word
    -We can do this using map.
    but if we see the worst case where length of every word is l which is equavelent to number of words
    then the complexity of hashing would O(l). so will be the complexity of adding, searching and removing.


    //A better approach is doing it by using tries.
*/

/*
WHAT IS TRIE?
Trie is a tree like data structure in which a single node has multiple elements.

Insertion:
    SEE SCREENSHOT OR VIDEO FOR BETTER EXPLAINATION IN CASE YOU HAVE FORGOT.
    1)Traverse the string that you want to insert into the trie.
    2)Goto root and search if it has the first character.
        i) if yes then goto that node and also continue to second character traversal
        ii) if no then add a new node and then goto that node and continue to traverse the second character.
    3) continue until the string ends.

Searching and Structure of each node.

    structure:
    TrieNode{
        public:
            char data; //har node pe ek character data hoga.
            TrieNode* children[26]; //one node can have multiple children and they can be letters which are 26
                                    //so 26 characters ka array bana dia.
            
            bool isTerminal; //hame ye bhi to pata hona chaiya ki word end yahan ho raha hai ya nahi
            //eg: if we have words like ARMY, TIME, DO. and we search for ARM. then if isTerminal is not used 
            //then the program will traverse the trie till arm and tell that arm is present.(which is wrong). 

    };


*/