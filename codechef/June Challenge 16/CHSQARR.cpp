#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
vector<vll > swm2D(vector<vll > arr, ll window_width, ll window_height){
    for(ll j=0;j<arr.size();j++){
        deque<long long> q;
        vll maximumresult(arr[j].size(),0);
        for(long i=0;i<window_height;i++){
            while(!q.empty() && arr[j][i] >= arr[j][q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        maximumresult[window_height-1] = arr[j][q.front()];
        for(long i=window_height;i<arr[j].size();i++){
            while(!q.empty() && arr[j][i] >= arr[j][q.back()])
                q.pop_back();
            while(!q.empty() && q.front() <= i-window_height)
                q.pop_front();
            q.push_back(i);
            maximumresult[i] = arr[j][q.front()];
        }
        arr[j] = maximumresult;
    }
    vll temp(arr[0].size(),0);
    vector<vll> b(arr.size(),temp);
    for(ll j=0;j<arr[0].size();j++){
        deque<long long> q;
        for(long i=0;i<window_width;i++){
            while(!q.empty() && arr[i][j] >= arr[q.back()][j]){
                q.pop_back();
            }
            q.push_back(i);
        }
        b[window_width-1][j] = arr[q.front()][j];
        for(long i=window_width;i<arr.size();i++){
            while(!q.empty() && arr[i][j] >= arr[q.back()][j])
                q.pop_back();
            while(!q.empty() && q.front() <= i-window_width)
                q.pop_front();
            q.push_back(i);
            b[i][j] = arr[q.front()][j];
        }
    }
    return b;
}
vector<vll > sumMatrix;
void sumsubMatrixinit(vector<vll > arr){
    sumMatrix = arr;
    for(long i=1;i<arr.size();i++)
        sumMatrix[i][0] += sumMatrix[i-1][0];
    for(long i=1;i<arr[0].size();i++)
        sumMatrix[0][i] += sumMatrix[0][i-1];
    for(long i=1;i<arr.size();i++){
        for(long j=1;j<arr[0].size();j++){
            sumMatrix[i][j] += sumMatrix[i-1][j] + sumMatrix[i][j-1] - sumMatrix[i-1][j-1];
        }
    }
}
int main(){
    ll m,n;
    cin>>n>>m;
    vll temp(m,0);
    vector<vll > arr(n,temp);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    sumsubMatrixinit(arr);
    int q;
    cin>>q;
    while(q--){
        ll a,b;
        cin>>a>>b;
        ll p = a*b;
        ll ans = LONG_LONG_MAX;
        vector<vll> maxMatrix = swm2D(arr,a,b);
        for(long i = a-1;i<arr.size();i++)
            for(long j = b-1;j<arr[0].size();j++){
                ll result = sumMatrix[i][j];
                if(i-a >= 0)
                    result -= sumMatrix[i-a][j];
                if(j-b >= 0)
                    result -= sumMatrix[i][j-b];
                if(i-a >= 0 && j-b >= 0)
                    result += sumMatrix[i-a][j-b];
                ans = min(ans,p*maxMatrix[i][j] - result);
                if(ans==0) break;
            }
        cout<<ans<<endl;
    }
    return 0;
}
