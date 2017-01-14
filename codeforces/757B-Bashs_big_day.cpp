#include <bits/stdc++.h>
#define pb push_back
using namespace std;
bool arr[1000001];
vector<long> primes;
void markMultiples(int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n ) {
        arr[num] = true;
        ++i;
    }
}
void SieveOfEratosthenes(int n)
{
    if (n >= 2) {
        fill(arr,arr+1000001,false);
        for (int i=2; i<n; ++i)
            if ( arr[i] == false ){
                primes.pb(i);
                markMultiples(i, n);
            }
    }
}
int main()
{
    SieveOfEratosthenes(100001);
    long n;
    cin>>n;
    vector<long> karr(n);
    vector<long> hash(100001,0);
    for(long i=0;i<n;i++){
        cin>>karr[i];
        for(long j=0;j<primes.size() && primes[j]*primes[j] <= karr[i];j++){
            if(karr[i]%primes[j] == 0)
                hash[primes[j]]++;
        }
        if(arr[karr[i]] == false)
            hash[karr[i]]++;
    }
    cout<<max((long)1,*max_element(hash.begin()+2,hash.end()));
    return 0;
}
