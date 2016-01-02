#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
int an;
void f(int n){
    if(n==7&&an!=7){
        ans.push_back(4);
        ans.push_back(3);
        ans.push_back(3);
        ans.push_back(3);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        ans.push_back(1);
        return;
    }
    if(n==9&&an!=9){
        ans.push_back(5);
        ans.push_back(4);
        ans.push_back(4);
        ans.push_back(3);
        ans.push_back(2);
        ans.push_back(2);
        ans.push_back(2);
        ans.push_back(1);
        return;
    }
    if(n==1)
        return;
    if(n%2!=0){
        ans.push_back((n+1)/2);
        ans.push_back((n-1)/2);
        ans.push_back((n-1)/2);
        n = (n+1)/2;
        f(n);
    }else{
        ans.push_back(n/2);
        ans.push_back(n/2);
        ans.push_back(n/2);
        f(n/2);
    }
}
int main(){
    int n,i;
    cin>>n;
    an = n;
    // n=2;
    // while(n<51){
    //     ans.clear();
    //     cout<<n<<endl;
    if(n%2==0){
        cout<<4<<endl;
        for(i=0;i<4;i++){
            cout<<n/2<<" ";
        }
    }else{
        f(n);
        // if(2*n<=ans.size()){
        //     cout<<2*n<<endl;
        //     for(i=1;i<2*n;i++){
        //         cout<<1<<" ";
        //     }
        //     cout<<n-1;
        // }else{
            cout<<ans.size()<<endl;
            for(i=ans.size()-1;i>=0;i--){
                cout<<ans[i]<<" ";
            }
        // }
    }
    // cout<<endl<<endl;
    // n++;}
    return 0;
}
