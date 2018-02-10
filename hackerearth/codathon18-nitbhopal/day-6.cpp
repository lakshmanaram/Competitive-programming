#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define all(s) s.begin(), s.end()
#define point pair<double, ll>
using namespace std;
int main(){
	long t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		vector<vector<double> > arr(4);
		for(long i=0;i<n;i++){
			int ch;
			double x;
			cin>>ch>>x;
			arr[ch-1].push_back(x);
		}
		sort(all(arr[2]));
		sort(all(arr[3]));
		ll max3, max4;
		max3 = max4 = 0;
		set<point> s3, s4;
		map<ll, long> m3, m4;
		long n3, n4;
		n3 = arr[2].size();
		n4 = arr[3].size();
		for(long i=0;i<arr[2].size();i++){
		    s3.insert(mp(arr[2][i], max3));
		    m3[max3] = i;
		    max3 += arr[2][i];
		}
		for(long i=0;i<arr[3].size();i++){
		    s4.insert(mp(arr[3][i], max4));
		    m4[max4] = i;
		    max4 += arr[3][i];
		}
		bool flag = false;
		double ans = 0, base, tans = 0;
		for(int iv = 1; iv < 3; iv++) {
		    for(int jv = iv+1; jv < 4;jv++) {
		        for(int kv = jv+1; kv <= 4; kv++) {
		            for(long i=0;i<arr[iv-1].size();i++){
            			for(long j=0;j<arr[jv-1].size();j++){
            				// // cout<<"point 1 x = "<<iv<<" y = "<<arr[iv-1][i]<<endl;
            				// // cout<<"point 2 x = "<<jv<<" y = "<<arr[jv-1][j]<<endl;
            				// double slope = arr[jv-1][j] - arr[iv-1][i], m;
            				// slope /= jv - iv;
            				// m = slope;
            				// m *= kv - iv;
            				// m += arr[iv-1][i];
            				// base = sqrt((jv-iv)*(jv-iv) + (arr[jv-1][j]-arr[iv-1][i])*(arr[jv-1][j]-arr[iv-1][i]));
            				// double sinval = fabs(cos(atan(slope)));
            				// // cout<<"slope = "<<slope<<endl;
            				// // cout<<"point 3: x = "<<kv<<" y = "<<m<<endl;
            				// // cout<<"sin val = "<<sinval<<" base = "<<base<<endl;
            				// double temp = 0;
            				// if(kv == 3) {
            				// 	auto it = s3.lower_bound(mp(m, 0));
            				// 	double before = max3;
            				// 	double after = 0;
            				// 	long ind = n3;
            				// 	// cout<<"m = "<<m<<endl;
            				// 	// for(auto iti = s3.begin(); iti != s3.end(); iti++){
            				// 		// cout<<iti->first<<" "<<iti->second<<endl;
            				// 	// }
            				// 	if(it != s3.end()){
            				// 		point val = *it;
            				// 		before = val.second; 
            				// 		after = max3 - val.second;
            				// 		ind = m3[val.second];
            				// 	}
            				// 	// cout<<(ind)*m<<" "<<before<<" & "<<after<<" "<<(n3-ind)*m<<endl;
            				// 	temp = (ind)*m - before;
            				// 	temp += after - (n3-ind)*m;
            				// } else {
            				// 	auto it = s4.lower_bound(mp(m, 0));
            				// 	double before = max4;
            				// 	double after = 0;
            				// 	long ind = n4;
            				// 	if(it != s4.end()){
            				// 		point val = *it;
            				// 		before = val.second; 
            				// 		after = max4 - val.second;
            				// 		ind = m4[val.second];
            				// 	}
            				// 	temp = (ind)*m - before;
            				// 	temp += after - (n4-ind)*m;
            				// }
            				// // cout<<"max3 = "<<max3<<" max4 = "<<max4<<" n3 = "<<n3<<" n4 = "<<n4<<endl;
            				// // cout<<"temp = "<<temp<<endl;
            				// temp *= sinval;
            				// ans += base*temp;


            				double temp = 0;
            				double m = (kv-iv)*(arr[jv-1][j] - arr[iv-1][i]);
            				m /= (jv-iv);
            				m += arr[iv-1][i];
            				if(kv == 3) {
            					auto it = s3.lower_bound(mp(m, 0));
            					double before = max3;
            					double after = 0;
            					long ind = n3;
            					if(it != s3.end()){
            						point val = *it;
            						before = val.second; 
            						after = max3 - val.second;
            						ind = m3[val.second];
            					}
            					// cout<<(ind)*m<<" "<<before<<" & "<<after<<" "<<(n3-ind)*m<<endl;
            					temp = before - (ind)*arr[iv-1][i];
            					temp *= (jv-iv);
            					temp -= (kv-iv)*(arr[jv-1][j] - arr[iv-1][i])*(ind);
            					temp = -temp;
            					double ttemp = after - (n3-ind)*arr[iv-1][i];
            					ttemp *= (jv-iv);
            					ttemp -= (kv-iv)*(arr[jv-1][j] - arr[iv-1][i])*(n3-ind);
            					temp += ttemp;
            				} else {
            					auto it = s4.lower_bound(mp(m, 0));
            					double before = max4;
            					double after = 0;
            					long ind = n4;
            					if(it != s4.end()){
            						point val = *it;
            						before = val.second; 
            						after = max4 - val.second;
            						ind = m4[val.second];
            					}
            					temp = before - (ind)*arr[iv-1][i];
            					temp *= (jv-iv);
            					temp -= (kv-iv)*(arr[jv-1][j] - arr[iv-1][i])*(ind);
            					temp = -temp;
            					double ttemp = after - (n4-ind)*arr[iv-1][i];
            					ttemp *= (jv-iv);
            					ttemp -= (kv-iv)*(arr[jv-1][j] - arr[iv-1][i])*(n4-ind);
            					temp += ttemp;
            				}
            				ans += temp;
            				for(long k=0;k<arr[kv-1].size();k++){
            				    double temp = fabs((jv-iv)*(arr[kv-1][k] - arr[iv-1][i]) - (kv-iv)*(arr[jv-1][j] - arr[iv-1][i]));
            				    tans += temp;
            				}
            				if(fabs(ans-tans) > 0.1 && !flag) {

            					flag = true;
            					cout<<t<<" ";
            				cout<<"====================================\n";
            				    cout<<ans<<" "<<tans<<endl;
            				cout<<"====================================\n";
            				}

            			}
		            }
		        }
		    }
		}
		ans /= 2.0;
		// printf("%.9lf\n", ans);
        cout << std::fixed;
        cout << std::setprecision(9);
        cout << ans << endl;
        // cout <<"correct ans = "<<tans<<endl;
	}
	return 0;
}