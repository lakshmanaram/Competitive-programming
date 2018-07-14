#include <bits/stdc++.h>
using namespace std;
int main(){
    long tk;
    scanf("%ld", &tk);
    for (long t = 1; t <= tk; t++) {
        long n;
        scanf("%ld", &n);
        vector<long long> arr(n);
        vector<long long> even, odd;
        for (long i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
            if (i & 1)
                odd.push_back(arr[i]);
            else
                even.push_back(arr[i]);
        }
        sort (even.begin(), even.end());
        sort (odd.begin(), odd.end());
        int even_no = 0;
        int odd_no = 0;
        long ans = -1;
        for (long i = 0; i < n; i++) {
            if (i & 1) {
                arr[i] = odd[odd_no++];
            } else {
                arr[i] = even[even_no++];
            }
            if (i != 0) {
                if(arr[i] < arr[i-1]){
                    ans = i-1;
                    break;
                }
            }
        }
        if (ans == -1)
            printf("Case #%ld: OK\n", t);
        else
            printf("Case #%ld: %ld\n", t, ans);
    }
    return 0;
}
