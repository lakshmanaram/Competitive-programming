// Finding the divisors of a range of numbers in O(nlogn) time.
// n is the max value in the range
#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
vector<vll> getDivisors(long n){
    vector<vll> divisors(n+1);
    divisors[0].push_back(-1);
    for(long i=1;i<=n;i++){
        for(long j=i;j<=n;j+=i){
            divisors[j].push_back(i);
        }
    }
    return divisors;
}
int main(){
    long n;
    cin>>n;
    vector<vll> divisors = getDivisors(n);
    for(long i=1;i<=n;i++){
        for(long j=0;j<divisors[i].size();j++){
            cout<<divisors[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
