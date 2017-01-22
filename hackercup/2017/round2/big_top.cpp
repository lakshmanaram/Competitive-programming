#include <bits/stdc++.h>
#define ll long long
#define line pair<double, double>   // x and h
#define mp make_pair
using namespace std;

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
    for(long long tk=1;tk<=t;tk++){\
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
        set<line> st;
        double finalans = 0, prevans = 0;
        for(it = lines.begin();it!= lines.end();it++){
            finalans += prevans;
            double ans = prevans;
            if(st.size() == 0) {
                st.insert(*it);
                ans = (it->second) * (it->second);
                prevans = ans;
                continue;
            }
            x = it->first;
            h = it->second;
            double fx = x - h, bx = x + h;
            double fh = 0, bh = 0;
            set<line>::iterator sit, sit2, sit3;
            sit = st.upper_bound(mp(x,h));
            bool addf = true;
            while(sit != st.begin()) {
                set<line>::iterator sit1;
                sit1 = sit;
                sit1--;
                if ((sit1->first + sit1->second >= x+h) && (sit1->first - sit1->second) <= x-h){
                    addf = false;
                    break;
                }
                if ((sit1->first + sit1->second <= x+h) && (sit1->first - sit1->second) >= x-h){
                    if(st.size() == 1) {
                        ans = 0;
                    }
                    if(sit1 == st.begin()) {
                        ans -= (sit1->second*sit1->second)/2.0;
                        sit2 = sit1;
                        sit2++;
                        ans -= find_area_bet(*sit1, *sit2);
                        ans += (sit2->second*sit2->second)/2.0;
                    } else if ( sit1 == st.end()) {
                        sit1--;
                        ans -= (sit1->second*sit1->second)/2.0;
                        sit2 = sit1;
                        sit2--;
                        ans -= find_area_bet(*sit2, *sit1);
                        ans += (sit2->second*sit2->second)/2.0;
                    } else {
                        sit2 = sit1;
                        sit2++;
                        sit3 = sit2;
                        ans -= find_area_bet(*sit1, *sit2);
                        sit2--;
                        sit2--;
                        ans -= find_area_bet(*sit2, *sit1);
                        ans += find_area_bet(*sit2, *sit3);
                    }
                    st.erase(*sit1);
                } else break;
                sit = st.upper_bound(mp(x,h));
            }
            if(!addf) continue;
            sit = st.upper_bound(mp(x,h));
            while(sit != st.end()) {
                if ((sit->first + sit->second >= x+h) && (sit->first - sit->second) <= x-h){
                    addf = false;
                    break;
                }
                if ((sit->first + sit->second <= x+h) && (sit->first - sit->second) >= x-h){
                    cout<<"deletes greater"<<endl;
                    if(st.size() == 1) {
                        ans = 0;
                    }
                    if(sit == st.begin()) {
                        ans -= (sit->second*sit->second)/2.0;
                        sit2 = sit;
                        sit2++;
                        ans -= find_area_bet(*sit, *sit2);
                        ans += (sit2->second*sit2->second)/2.0;
                    } else if ( sit == st.end()) {
                        sit--;
                        ans -= (sit->second*sit->second)/2.0;
                        sit2 = sit;
                        sit2--;
                        ans -= find_area_bet(*sit2, *sit);
                        ans += (sit2->second*sit2->second)/2.0;
                    } else {
                        sit2 = sit;
                        sit2++;
                        sit3 = sit2;
                        ans -= find_area_bet(*sit, *sit2);
                        sit2--;
                        sit2--;
                        ans -= find_area_bet(*sit2, *sit);
                        ans += find_area_bet(*sit2, *sit3);
                    }
                    st.erase(*sit);
                } else break;
                sit = st.upper_bound(mp(x,h));
            }
            if(!addf) continue;
            sit = st.upper_bound(mp(x,h));
            // if(tk == 1)
            // cout<<ans<<endl;
            if(st.size() == 0) {
                ans = h*h;
            }
            if(sit == st.begin()) {
                // if(tk == 1)
                //     cout<<"in begin"<<endl;
                ans += (h*h)/2.0;
                ans -= (sit->second)*(sit->second)/2.0;
                ans += find_area_bet(mp(x,h), *sit);
            } else if ( sit == st.end()) {
                // if(tk == 1)
                //     cout<<"in end"<<endl;
                ans += (h*h)/2.0;
                sit--;
                ans -= (sit->second)*(sit->second)/2.0;
                ans += find_area_bet(*sit, mp(x,h));
            } else {
                sit2 = sit;
                ans += find_area_bet(mp(x,h), *sit);
                sit--;
                ans += find_area_bet(*sit, mp(x,h));
                ans -= find_area_bet(*sit,*sit2);
            }
            st.insert(mp(x,h));
            // if(tk == 1)
            // cout<<ans<<endl;
            prevans = ans;
        }
        finalans += prevans;
        cout<<finalans<<endl;
        outfile<<"Case #"<<tk<<": "<<finalans<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
