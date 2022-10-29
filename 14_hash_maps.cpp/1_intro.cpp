#include <iostream>
#include <map>
using namespace std;

/*
map: when ever we need to store the key value pairs we use maps.

INBUILT STUFF:  1) MAP - O(log(n)) - run using bst
                    For numeric keys it arranges the keys in sorted order.
                    for alphateic keys it arranges the keys in the alphabetic order.


                2) UNORDERED_MAP - O(1)
                .                               - run using ARRAYS hashing and hash table using hash function.
                                                It does not do any kind of sorting and returns us the 
                                                keys in any order.
*/


int main(){

    //creation
    map<string, int> m;

    //insertion
    //1
    pair<string, int> p = make_pair("devansh", 2);
    m.insert(p);

    //2
    pair<string, int> p2("batra", 1);
    m.insert(p2);
    m["zayka"] = 20;
    //3
    m["mera"] = 3;
    m["mera"] = 5;
    //saari keys ke liye unique entry hogi.


    //search.
    cout<<m["devansh"]<<endl;
    cout<<m.at("mera")<<endl;

    cout<<m["unknownkey"]<<endl; //will return 0 as this creates this entry and then initialize it with 0
    // cout<<m.at("unknownkey2")<<endl; //out of range error would be thrown with this method.

    //size
    cout<<m.size()<<endl;

    cout<<endl;
    //to check presence
    cout<<m.count("bro")<<endl;
    cout<<m.count("devansh")<<endl;
    //count - will return 0 if key is not present in the map, and will create a new key with initial entry as 0.
    // and will return 1 if key is present in the map.
    cout<<m["bro"]<<endl;

    //erase
    m.erase("devansh");


    //iterate the map

    //1
    for(auto i: m){
        cout<<i.first<<" : "<<i.second<<endl;
    }

    cout<<endl;
    //2 -  making iterator
    map<string, int> :: iterator it  = m.begin();

    while(it!=m.end()){
        cout<<it->first<<" : "<<it->second<<endl;//it act as a pointer
        it++;
    }


    return 0;
}