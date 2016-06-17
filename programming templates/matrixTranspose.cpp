// Transpose a given matrix
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll> > matrixTranspose(vector<vector<ll> > arr){
    vector<ll> temp(arr.size(),0);
    vector<vector<ll> > result(arr[0].size(),temp);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++)
            result[j][i] = arr[i][j];
    }
    return result;
}
int main(){
    ll m,n;
    cin>>n>>m;
    vector<ll> temp(m,0);
    vector<vector<ll> > arr(n,temp);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    arr = matrixTranspose(arr);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
