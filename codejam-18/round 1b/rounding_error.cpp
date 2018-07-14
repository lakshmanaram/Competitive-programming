#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(long tt = 1; tt <= t; tt++) {
        long n, l;
        cin >> n >> l;
        vector<long> arr(l);
        long sl = 0;
        for(long i = 0; i < l; i++) {
            cin >> arr[i];
            sl += arr[i];
        }
        if (100 % n == 0){
            cout<<"Case #"<<tt<<": 100\n";
            continue;
        }
        long mval = n-sl;
        set<pair<long, long> > s;
        long target = 1;
        bool targ_flag = false;
        while(target <= mval) {
            double temp = target;
            temp /= n;
            temp *= 100;
            temp -= floor(temp);
            if(temp >= 0.5) {
                targ_flag= true;
                break;
            }
            target++;
        }
        for(long i = 0; i < l; i++) {
            long tar = arr[i];
            while(tar-arr[i] <= mval) {
                double temp = tar;
                temp /= n;
                temp *= 100;
                temp -= floor(temp);
                if(temp >= 0.5) {
                    break;
                }
                tar++;
            }
            s.insert(make_pair(tar - arr[i], i));
        }
        // for(auto it = s.begin(); it != s.end(); it++) {
        //     cout<< it-> first<< " "<< it->second<<endl;
        // }
        long ans = 0;
        while(!s.empty()) {
            if(targ_flag && (target <= s.begin()->first)) {
                if (target <= mval)  {
                    double temp_ans = target;
                    temp_ans /= n;
                    temp_ans *= 100;
                    // cout << ans << " " << temp_ans << " " << temp_ans + ans << endl;
                    ans += round(temp_ans);
                    mval -= target;
                } else {
                    double temp_ans = arr[s.begin()->second];
                    temp_ans /= n;
                    temp_ans *= 100;
                    // cout << ans << " " << temp_ans << " " << temp_ans + ans << endl;
                    ans += round(temp_ans);
                    s.erase(s.begin());
                }
            } else {
                if (s.begin()->first <= mval) {
                    double temp_ans = s.begin()->first + arr[s.begin()->second];
                    temp_ans /= n;
                    temp_ans *= 100;
                    // cout << ans << " " << temp_ans << " " << temp_ans + ans << endl;
                    ans += round(temp_ans);
                    mval -= s.begin()->first;
                    s.erase(s.begin());
                } else {
                    double temp_ans = arr[s.begin()->second];
                    temp_ans /= n;
                    temp_ans *= 100;
                    // cout << ans << " " << temp_ans << " " << temp_ans + ans << endl;
                    ans += round(temp_ans);
                    s.erase(s.begin());
                }
            }
        }
        // cout << ans << endl;
        ans += round((100.0*(double)mval)/n);
        cout<<"Case #"<<tt<<": "<<ans<<"\n";
    }
}