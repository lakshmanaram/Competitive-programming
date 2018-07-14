#include <bits/stdc++.h>
using namespace std;
long long get_bin(string s) {
    long long ans = 0;
    long long mul = 1;
    for (long i = 0; i < s.size(); i++) {
        if (s[i] == 'C') {
            mul <<= 1;
        } else {
            ans += mul;
        }
    }
    return ans;
}
int main(){
    long tk;
    cin >> tk;
    for (long t = 1; t <= tk; t++) {
        long long n;
        string s;
        cin >> n >> s;
        bool ans_reached = false;
        bool no_change = false;
        long ans = 0;
        string prev_s = "";
        while (prev_s != s) {
            prev_s = s;
            // cout << s << " " << get_bin(s) << " ";
            if (get_bin(s) <= n) {
                ans_reached = true;
                break;
            }
            for (long j = s.size() - 1; j >= 1; j--) {
                if (s[j] == 'S' && s[j-1] == 'C') {
                    s[j] = 'C';
                    s[j-1] = 'S';
                    ans++;
                    break;
                }
            }
            // cout << s << " " << get_bin(s) << endl;
        }
        if (!ans_reached)
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        else
            cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
