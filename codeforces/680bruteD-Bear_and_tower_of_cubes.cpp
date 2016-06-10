#include<bits/stdc++.h>
using namespace std;
int main(){
    long long m;
    cin>>m;
    if(m<=7){
        cout<<m<<" "<<m;
    }else{
        long i = cbrt(m);
        vector<long long> arr(i+1,0);
        vector<long long>::iterator lit;
        vector<long long> extra(i+1,0);
        arr[i] = pow(i,3);
        extra[i] = 1;
        long long max_extra = 1;
        for(--i;i>1;i--){
            long long temp = m - pow(i,3);
            lit = upper_bound(arr.begin(),arr.end(),temp);
            lit--;
            label:
            if(max_extra <= extra[distance(arr.begin(),lit)]+1){
                arr[i] = pow(i,3)+*lit;
                extra[i] = extra[distance(arr.begin(),lit)]+1;
            }else{
                lit--;
                if(distance(arr.begin(),lit)> i)
                    goto label;
                arr[i] = arr[i+1];
                extra[i] = extra[i+1];
            }
        }
        long long temp = m - 7;
        lit = upper_bound(arr.begin(),arr.end(),temp);
        lit--;
        arr[i] = 7+*lit;
        extra[i] = extra[distance(arr.begin(),lit)]+7;
        cout<<extra[1]<<" "<<arr[1]<<endl;
    }
    return 0;
}
