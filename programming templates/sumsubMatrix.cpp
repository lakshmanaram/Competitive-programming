// Finding the sum of any submatrix in O(1) time using precomputation in O(mn) time;
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll> > sumMatrix;
void sumsubMatrixinit(vector<vector<ll> > arr){
    sumMatrix = arr;
    for(long i=1;i<arr.size();i++)
        sumMatrix[i][0] += sumMatrix[i-1][0];
    for(long i=1;i<arr.size();i++)
        sumMatrix[0][i] += sumMatrix[0][i-1];
    for(long i=1;i<arr.size();i++){
        for(long j=1;j<arr[0].size();j++){
            sumMatrix[i][j] += sumMatrix[i-1][j] + sumMatrix[i][j-1] - sumMatrix[i-1][j-1];
        }
    }
}
ll sumsubMatrix(ll window_width, ll window_height, ll x, ll y){
    ll result = sumMatrix[x][y];
    if(x-window_width >= 0)
        result -= sumMatrix[x-window_width][y];
    if(y-window_height >= 0)
        result -= sumMatrix[x][y-window_height];
    if(x-window_width >= 0 && y-window_height >= 0)
        result += sumMatrix[x-window_width][y-window_height];
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
    sumsubMatrixinit(arr);
    for(int i=0;i<sumMatrix.size();i++){
        for(int j=0;j<sumMatrix[0].size();j++)
            cout<<sumMatrix[i][j]<<" ";
        cout<<endl;
    }
    while(true){
        ll m,n,a,b;
        cin>>n>>m>>a>>b;
        cout<<sumsubMatrix(n,m,a,b)<<endl;
    }
    return 0;
}
