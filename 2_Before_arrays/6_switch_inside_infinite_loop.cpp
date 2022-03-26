#include <iostream>

using namespace std;

int main(){
    int n=1, flag=1;
    while(1){
        switch(1){
            case 1: 
                cout<<"N is one"<<endl;
                exit(EXIT_SUCCESS);
                // exit(EXIT_FAILURE);
                // exit(0);
                // exit(1);
                break;
            default:
                cout<<"default called"<<endl;
        }
    }
    return 0;
}
