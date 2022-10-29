//The unordered map is implemented using hash function.

//some terms
//bucket array: 
//It is the array which stores the key value pairs of the map.
// key is the index of the array and value is the data stored in the array.
// The string , float or integer to int conversion for storing in index of this bucket array is done through
// the hash code.

//hash code roles: 1) conversion  2) uniform distribution
//It is responsible for converting the string, char, or float or any other data type of key or value provided
//into integer for storing it in the bucket array.
//hash code also has another work i.e. uniform distribution
// do diff. plain text ke liye same hash code aa gaya to collision ho jayega.
// so the hash codes should be uniformly distributed.

//compression function:
// If the bucket array size is just 10 and the key value is returned as 126 by the hash code, then the 
// compression function role is to convert that bigger value with in the range of 0-10(size of the bucket array)


//collision : means do alag plain text ke liye same hash code generate hona.


//COLLISION HANDLING
// 1) open hashing / SAPERATE CHAINING(LINKED LIST METHOD)
/*
    Agar do text ka same hash code aaya hai, then open hashing say ki daal do dono ko ek he index mein
    ab ye jo index hai wo ek linked list ka head store karega.
    aur uss linked list mein jitni bhi keys same aa rhi thi unki value aayengi.
    ab aisa nhi hoga ki 100 length ki ll. ban rahi hai, as hash func. are strong enough but kabhi kabhi ho
    jata hai.
    iss method ko SAPERATE CHAINING  bhi bolte hain.
    see ss.
*/

// 2) closed addressing
/*
    agar diff. plane text ke liye same hash code generate hua hai, then open addr. says that check any other
    index to insert the key.
    Now, any other means which one: this depends on a function ki kahan try karna hai ab.
    H i(a) = h(a) + f i(a) (initial index + function.)
    Types of functions:
    i) linear probing:  here f of i(a) = i. where is the attemp number.
                        Jonsa attempt hai utni he position plus krke try karo.
    
    ii) quadratic probing: here f of i = i^2
                            agar 7th index pe gaye aur kuch pehle se pada hai.
                            f(0) = 0;

                            ab f(1) = 1;
                            8th index pe gaye, agar kuch pada h

                            ab f(2) = 4
                            7 +4 = 11th index pe gaye and so on...  

*/

//COMPLEXITY ANALYSIS of hashing n words
/*
let say n->total number of words and k->avg word length
    Hash Code : TC-> O(K) but if n>>>>k then TC~O(1).
    So, Total complexity for hashing the whole arr of words: O(N).

    ANOTHER THEORY OF CREATING BOXES.
    If we say that N is the number of entries in map.
    b-> NO. OF BOXES AVAILABLE. 

    so number of entries in a box = n/b.

    n/b==> also called load factor.
    we always ensure that n/b < 0.7.
    means n>b - if 100 entries aa rhi hain , to atleast 120-130 boxes to ho.
    taaki kahi overlapping na ho jaaye.

    //if n increases and n/b should be 0.7 the we need to also increase b(number of boxes.).
    //for that we need to perform rehashing
    //REHASHING
    //1) increase bucket size(let say double). n/b==n/2b
    //2) saari entries ko dobara hash kar diya.(bcoz bucket size change ho gaya na). 

Insertion ke liye ye tha.
Same is the stuff for deletion and searching.
*/



