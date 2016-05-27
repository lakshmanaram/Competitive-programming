#include <bits/stdc++.h>
using namespace std;
int main(){
    long n,k;
    string a;
    cin>>n>>k;
    cin>>a;
    long answer = 0;
    long i,j;
    i = 0;
    long aval = 0,bval = 0;
    for(j=i;j<n;j++){
        if(a[j] == 'a')
        aval++;
        else
        bval++;
        if(aval > k && bval > k)
            break;
    }
    answer = max(answer,j-i);
    while(i<n&&j<n){
        if(a[i] == 'a')
            aval--;
        else
            bval--;
        i++;
        j++;
        for(;j<n;j++){
            if(a[j] == 'a')
            aval++;
            else
            bval++;
            if(aval > k && bval > k){
                break;
            }
        }
        answer = max(answer,j-i);
        // cout<<answer<<" i = "<<i<<" j = "<<j<<endl;
    }
    cout<<answer;
    return 0;
}
