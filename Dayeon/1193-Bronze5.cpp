#include <iostream>
using namespace std;

int main() {
    int num;
    int i = 1;
    int a=0,b=0;    //a: 분자, b:분모
    cin>>num;

    while(num>0){
        num-=i;
        i++;
    }
    i--;
    num=num+i;

    if(i%2==1){
        for(int j=0;j<num;j++){
            b++;
        }
        a = i+1-b;
    }
    else{
        for(int j=0;j<num;j++){
            a++;
        }
        b = i+1-a;
    }

    cout<<a<<"/"<<b;

    return 0;
}