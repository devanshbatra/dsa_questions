//Not a question
#include <iostream>

using namespace std;

int main(){
    cout<<"Enter amt:  ";
    int amt, hundreds=0, fifties=0, twenties=0, ones=0;
    cin>>amt;
    
    switch(100){ //hume intentionally 100 ke equal he lana hai
        case(100):
            if(amt/100>=1){
                hundreds+=amt/100;
                amt= amt-((amt/100)*100);
                cout<<"amt after 100: "<<amt<<endl;
            }
        case 50:
            if(amt/50>=1){
                fifties+=amt/50;
                amt= amt-((amt/50)*50);
                cout<<"amt after 50: "<<amt<<endl;
            }
        case 20:
            if(amt/20>=1){
                twenties+=amt/20;
                amt= amt-((amt/20)*20);
            }
        case 1:
            ones = amt;
    }

    cout<<"Hundreds: "<<hundreds<<"  Fifties: "<<fifties<<"  Twenties: "<<twenties<<"  Ones: "<<ones;

    return 0;
}
    // int n;
    // cin >> n;

    // switch (100)
    // {
    // case 100:
    //     if ((n / 100) > 0)
    //     {
    //         cout << "100s: " << (n / 100) << endl;
    //         n -= ((n / 100) * 100);
    //     }
    // case 50:
    //     if ((n / 50) > 0)
    //     {
    //         cout << "50s: " << (n / 50) << endl;
    //         n -= ((n / 50) * 50);
    //     }
    // case 20:
    //     if ((n / 20) > 0)
    //     {
    //         cout << "20s: " << (n / 20) << endl;
    //         n -= ((n / 20) * 20);
    //     }
    // case 1:
    //     cout << "1s: " << n << endl;
    //     break;
    // }

