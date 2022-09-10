/*
1) to find whether a float number is equivalent to integer or not. like 1.0 is equivalent and 1.2 is not

    if(ciel(n)==floor(n)) then yes else not.
    or
    int temp = n;
    float afterpoint = n-temp;
    if(afterpoint==0) yes
    else no;


2) To find whether a number is in the powers of another number let's say 3

    like 27 = 3X3X3 or 3X3X3X3X3 etc.

    we have to find whether this x is positive or not here: 
        27 = 3^x;
        take log
        log(27) = xlog(3);
        float x = log(27)/log(3);
        now check if x is integer equivalent or not. 

*/