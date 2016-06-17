// Finding the maximum of each window in an array in O(n) time.
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
int main(){
    ll arr[] = {1, 2, 3, 11, 7, 6, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<ll> v(arr, arr + sizeof(arr) / sizeof (arr[0]));
    vector<ll> test;
    test = swm1D(v,2);
    for(long i=0;i<test.size();i++){
        cout<<test[i]<<" ";
    }
    cout<<endl;
    test = swm1D(v,3);
    for(long i=0;i<test.size();i++){
        cout<<test[i]<<" ";
    }
    cout<<endl;
    return 0;
}
