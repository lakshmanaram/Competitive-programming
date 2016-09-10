#include <bits/stdc++.h>
using namespace std;
bool is_degenerate_triangle(long a, long b, long c){
    if((a+b > c) && (a+c > b) && (b+c > a) && (a!=0) && (b!=0) && (c!=0))
        return true;
    return false;
}
void func(long a, long b, long c, long target, long index){
    if(!is_degenerate_triangle(a,b,c))
        cout<<"Error";
    // cout<<a<<" "<<b<<" "<<c<<endl;
    if(a==target && b == target && c == target){
        cout<<index;//<<endl;
        return;
    }
    if(index == 0){
        long newa = (a)/3;
        if(newa < target)
            newa = target;
        func(newa,b,c,target,index+1);
    } else {
        long newb = b - a + 1;
        if(newb < a){
            if(newb < (a+1)/3)
                newb = (a+1)/3;
            if(newb < target)
                newb = target;
            func(newb,a,b,target,index+1);
        } else {
            func(a,newb,b,target,index+1);
        }
    }
}
int main(){
    long n,x;
    cin>>n>>x;
    // for(long i=40;i<100;i++){
    //     n = i;
    //     x = 4;
    if(n > x)
        func(n,n,n,x,0);
    else if(n==x)
        cout<<0<<endl;
    else
        func(x,x,x,n,0);
// }
    return 0;
}
