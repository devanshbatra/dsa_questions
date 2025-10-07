// converting a character to lowercaase
// We also have an inbuilt functions in C++ called tolower() and toupper() - which is a recommended method

// But this approach is just to understand the concept
#include <iostream>
using namespace std;

char LowerCase(char a){
    if(a>='a' && a<='z' ) return a;
    else{
        return a-'A'+'a';
    }
}

int main(){
    char a, b;
    
    a = 'R';
    b='b';

    cout<<LowerCase(a)<<endl;
    cout<<LowerCase(b)<<endl;


}