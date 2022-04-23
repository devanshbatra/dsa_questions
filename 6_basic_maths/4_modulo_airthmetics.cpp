/*
refer to: https://codeforces.com/blog/entry/72527

n mod m (for integers n and m) :==> n − ⌊n/m⌋.m

note
1- mod has lower preceedence than +-* and divide
2- modulo basic airthmetics: 
    (a mod m)+(b mod m) mod m  =  (a+b) mod m
    (a mod m)−(b mod m) mod m  =  (a−b) mod m
    (a mod m)⋅(b mod m) mod m  =  (a⋅b) mod m

    //iska matlab hai ki agar a*b integer overflow ho raha ho toh ==> (a mod m)⋅(b mod m) mod m ---karke usse range mein laakar bhi 
    use kar skte hai.

3- modulo are generally used to represent numbers that are integer overflowed using the above identities.
4 - represent by using - <bigNumber> mod (10^9 + 7)  as 10^9 + 7 is the range for integers so this modulo will result
    only in 0 to 10^9 + 7-1 range.
5- The above identities can be used for the add multiply and subract of this mod representation.
*/