#include <bits/stdc++.h>
#define ll long long
#define line pair<double, double>   // x and h
#define mp make_pair
using namespace std;
struct ans_s {
    line fr, pt, ba;
};

double find_area_bet(line a, line b) {
    double x = b.first - a.first;
    double ans = 0;
    if(a.second + b.second <= x){
        ans = (a.second*a.second + b.second*b.second)/2.0;
    } else {
        double mx, mh;
        mx = (x + a.second - b.second)/2.0;
        mh = a.second - mx;
        ans = mx*(a.second + mh)/2.0;
        mx = x - mx;
        ans += mx*(b.second + mh)/2.0;
    }
    return ans;
}
double find_area(vector<line> arr) {
    double ans = 0;
    for(long i=1; i< arr.size();i++) {
        ans += find_area_bet(arr[i-1],arr[i]);
    }
    ans += (arr[0].second*arr[0].second)/2.0;
    ans += (arr[arr.size()-1].second*arr[arr.size()-1].second)/2.0;
    return ans;
}

int main(){
    ifstream infile;
    ofstream outfile;
    long long t;
    infile.open("input.txt");
    outfile.open("output.txt");
    infile>>t;
    for(long long tk=1;tk<=t;tk++){
        ll n;
        infile>>n;
        ll x, ax, bx, cx;
        ll h, ah, bh, ch;
        infile>>x>>ax>>bx>>cx;
        infile>>h>>ah>>bh>>ch;
        set<line > lines;
        lines.insert(mp(x,h));
        for(ll i=1;i<n;i++) {
            x = (ax*x + bx)%cx + 1;
            h = (ah*h + bh)%ch + 1;
            lines.insert(mp(x,h));
        }
        set<line >::iterator it;
        stack<ans_s> st;
        ans_s temp;
        double fans = 0;
        for(it = lines.begin();it!= lines.end();it++){
            if(st.empty()) {
                temp.pt = *it;
                temp.fr.first = it->first - it->second;
                temp.fr.second = 0;
                temp.ba.first = it->first + it->second;
                temp.ba.second = 0;
                st.push(temp);
            } else {
                x = it->first;
                h = it->second;
                double fx = x - h, bx = x + h;
                double fh = 0, bh = 0;
                while(!st.empty()){
                    if(st.top().fr.first >= fx) {
                        st.pop();
                    } else break;
                }
                if ((st.empty()) || ((st.top().ba.first > fx) && (st.top().ba.first < bx))) {
                    temp.pt = *it;
                    temp.fr.first = fx;
                    temp.fr.second = fh;
                    temp.ba.first = bx;
                    temp.ba.second = bh;
                    st.push(temp);
                }
            }
            vector<ans_s> stv;
            while(!st.empty()) {
                stv.push_back(st.top());
                st.pop();
            }
            reverse(stv.begin(), stv.end());
            for(long i=0; i<stv.size();i++) {
                st.push(stv[i]);
            }
            double ans;
            ans = find_area(stv);
            fans += ans;
        }
        outfile<<"Case #"<<tk<<": "<<fans<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
