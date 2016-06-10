#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a(5);
    for(int i=0;i<5;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    int i = 4;
    while(i>0){
        if(a[i]==a[i-1])
            break;
        i--;
    }
    if(a[0]==a[1] && a[1] == a[2] && a[3]==a[4] && a[2]!=a[3]){
        if(3*a[0] > 2*a[3])
            cout<<2*a[3];
        else
            cout<<3*a[0];
    }
    else if(i==0)
        cout<<a[0]+a[1]+a[2]+a[3]+a[4];
    else{
        int sum = 0;
        if(i-2 >= 0 && a[i]==a[i-2]){
            for(int j=4; j>i;j--){
                sum += a[j];
            }
            for(int j=i-3; j>=0;j--){
                sum += a[j];
            }
        }else{
            for(int j=4; j>i;j--){
                sum += a[j];
            }
            for(int j=i-2; j>=0;j--){
                sum += a[j];
            }
        }
        cout<<sum;
    }
    return 0;
}
