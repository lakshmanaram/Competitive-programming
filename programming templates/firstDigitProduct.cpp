// Algorithm to find the first digit of a large product of numbers without having to multiply them.
// value of 10^fractional_part(log value) gives the first digit
#include <bits/stdc++.h>
using namespace std;
int ffd(double x){
    // find first digit
    return pow(10,x-floor(x));
}
double getLog(vector<long long> arr){
    double log_value = 0;
    for(long i=0;i<arr.size();i++){
        log_value += log10(arr[i]);
    }
    return log_value;
}
int main(){
    long n;
    cin>>n;
    vector<long long> arr(n);
    for(long i=0;i<n;i++)
        cin>>arr[i];
    cout<<ffd(getLog(arr));
    // cout<<" "<<getLog(arr)<<" "<<pow(10,getLog(arr));
    return 0;
}
