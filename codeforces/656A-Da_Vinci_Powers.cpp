#include<iostream>
using namespace std;
int main(){
    int a;
    cin>>a;
    long long b = 1;
    while(a--){
        b*=2;
    }
    cout<<b;
    return 0;
}
