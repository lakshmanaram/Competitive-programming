// Finding the maximum of each window subarray in a matrix in O(mn) time.
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> swm1D(vector<ll> arr, long window_size){
    deque<long long> q;
    vector<ll> maximumresult;
    for(long i=0;i<window_size;i++){
        maximumresult.push_back(0);
        while(!q.empty() && arr[i] >= arr[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    maximumresult[window_size-1] = arr[q.front()];
    for(long i=window_size;i<arr.size();i++){
        while(!q.empty() && arr[i] >= arr[q.back()])
            q.pop_back();
        while(!q.empty() && q.front() <= i-window_size)
            q.pop_front();
        q.push_back(i);
        maximumresult.push_back(arr[q.front()]);
    }
    return maximumresult;
}
vector<vector<ll> > matrixTranspose(vector<vector<ll> > arr){
    vector<ll> temp(arr.size(),0);
    vector<vector<ll> > result(arr[0].size(),temp);
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++)
            result[j][i] = arr[i][j];
    }
    return result;
}
vector<vector<ll> > swm2D(vector<vector<ll> > arr, ll window_width, ll window_height){
    for(ll i=0;i<arr.size();i++){
        arr[i] = swm1D(arr[i],window_height);
    }
    arr = matrixTranspose(arr);
    for(ll i=0;i<arr.size();i++){
        arr[i] = swm1D(arr[i],window_width);
    }
    arr = matrixTranspose(arr);
    return arr;
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
    vector<vector<ll> > test;
    test = swm2D(arr,2,2);
    for(int i=0;i<test.size();i++){
        for(int j=0;j<test[0].size();j++)
            cout<<test[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    test = swm2D(arr,2,3);
    for(int i=0;i<test.size();i++){
        for(int j=0;j<test[0].size();j++)
            cout<<test[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    test = swm2D(arr,3,1);
    for(int i=0;i<test.size();i++){
        for(int j=0;j<test[0].size();j++)
            cout<<test[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
