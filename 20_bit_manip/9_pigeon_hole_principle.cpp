//Pigeon hole principle - It states that if there is a set A of n pigeons and a set B of m holes and pigeons
// n are greater than m holes. If all the pigeons fly to set into holes than any one hole will contain more
//than one pigeon for sure.(or can say - at worse).

//question - You're given N 64 bit integers such that any two consecutive numbers differ by just one bit.
// Your job is to find out if there are 4 such integers such that their xor is equal to 0. If
// found, print Yes else No. constraint n<=1e9.

//solution - If we want solve this by brute force then it will take O(n^4) time complexity. we will take an
//element i will xor with j from 0 to n-1 with k from 0 to n-1 and with l from 0 to n-1. which will take
//order of n^4 complexity which is not suitable here.

//statement : I can say using pigeon hole principle that if n>=130 then Ans is yes always. why bcz, 
//suppose there are numbers A1, A2, A3, A4, ............ A127, A128, A129, A130.
//and since every consecutive number is just one bit different from other so, xor of A1, A2 = 0000010000. 
//where 1 can be any where. Let's suppose we say it's 0000000000000000001, for A2,A4 its 000000000000010. 
//we are trying so that we do not get answer or getting far from ans. After 64 pairs we will have
//all unique xors but the 65th pair will be having xor equal to some other already computed xor.
//so in this way 4 integers will have xor = 0.

//now for n<130 we can easily compute it in n^4 complexity.
