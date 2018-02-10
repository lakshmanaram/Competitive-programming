#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;

class FrogSquare{
public:
    bool cmp(long a, long b, long d){
        a = abs(a);
        b = abs(b);
        if(a*a + b*b >= d*d) return true;
        return false;
    }
    int minimalJumps(int n, int d, int sx, int sy, int tx, int ty) {
        if(cmp(sx-tx, sy-ty, d)) return 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cmp(sx-i, sy-j, d)){
                    if(cmp(tx-i, ty-j, d)){
                        return 2;
                    }
                }
            }
        }
        vector<pair<long, long> > corners_s, corners_t;
        if(cmp(sx, sy, d)) corners_s.pb(mp(0, 0));
        if(cmp(tx, ty, d)) corners_t.pb(mp(0, 0));
        if(cmp(sx, sy - (n-1), d)) corners_s.pb(mp(0, n-1));
        if(cmp(tx, ty - (n-1), d)) corners_t.pb(mp(0, n-1));
        if(cmp(sx - (n-1), sy, d)) corners_s.pb(mp(n-1, 0));
        if(cmp(tx - (n-1), ty, d)) corners_t.pb(mp(n-1, 0));
        if(cmp(sx - (n-1), sy - (n-1), d)) corners_s.pb(mp(n-1, n-1));
        if(cmp(tx - (n-1), ty - (n-1), d)) corners_t.pb(mp(n-1, n-1));
        if(corners_s.size() == 0 || corners_t.size() == 0) return -1;
        for(int i=0;i<corners_s.size();i++){
            for(int j=0;j<corners_t.size();j++){
                if(cmp(corners_s[i].first - corners_t[j].first, corners_s[i].second - corners_t[j].second, d)) return 3;
            }
        }
        for(int i=0;i<corners_s.size();i++){
            for(int j=0;j<corners_t.size();j++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(cmp(corners_s[i].first - i, corners_s[i].second - j, d) && cmp(i - corners_t[j].first, j - corners_t[j].second, d)) return 4;
                    }
                }
            }
        }
        return -1;
    }
};
int main() {
    FrogSquare fs;
    cout<<fs.minimalJumps(10, 7, 4, 4, 5, 5)<<endl;
    return 0;

}