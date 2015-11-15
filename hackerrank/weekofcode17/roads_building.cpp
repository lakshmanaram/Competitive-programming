#include<bits/stdc++.h>
using namespace std;
long n;
class gr{
public:
	long parent;
	long pcost;
	vector<long> nodes;
	vector<long> costs;
};
gr bgraph[100001];
bool bfsb[100001];
queue<long> bfsq;
void bfs(int a)
{
	// cout<<"ENTERING LOOP QUEUE: ";
	// queue<long> itq = bfsq;
	// while(!itq.empty()){
	// 	cout<<itq.front()<<" ";
	// 	itq.pop();
	// }
	// cout<<endl;

	bfsb[a] = true;
	// cout<<"**"<<a<<"**"<<endl;
	vector<long>::iterator it,it1;
	for(it = bgraph[a].nodes.begin(),it1 = bgraph[a].costs.begin();it!=bgraph[a].nodes.end();it++,it1++)
	{
		if(bfsb[*it]==false){
			bgraph[*it].parent = a;
			bgraph[*it].pcost = *it1 + bgraph[a].pcost;
			bfsq.push(*it);
		}
		else{
			long temp = *it1 + bgraph[a].pcost;
			if(bgraph[*it].pcost > temp){
				bgraph[*it].pcost = temp;
				bgraph[*it].parent = a;
			}
		}
		// cout<<"Parent: "<<a<<" Child: "<<*it<<" Cost: "<<bgraph[*it].pcost<<endl;
	}
	bfsq.pop();
	if(bfsq.empty())
		return;
	bfs(bfsq.front());
}
void insertbg(long a,long b,long c){
		vector<long>::iterator it;
		for(it=bgraph[a].costs.begin();it!=bgraph[a].costs.end();it++){
			if(*it>c)
				break;
		}
		long it1 = it - bgraph[a].costs.begin();
		bgraph[a].costs.insert(it,c);
		bgraph[a].nodes.insert(bgraph[a].nodes.begin()+it1,b);
		// cout<<endl<<"Costs: ";
		// for(it = bgraph[a].costs.begin();it!=bgraph[a].costs.end();it++)
		// 	cout<<*it<<" ";
		// cout<<endl<<"Nodes: ";
		// for(it = bgraph[a].nodes.begin();it!=bgraph[a].nodes.end();it++)
		// 	cout<<*it<<" ";
		// cout<<endl;
		bgraph[a].pcost = LONG_MAX;
		bgraph[b].pcost = LONG_MAX;
		return;
}
int main()
{
	long m;
	cin>>n>>m;
	long x,y,z;
	fill(bfsb,bfsb+n,false);
	while(m--){
		cin>>x>>y>>z;
		insertbg(x,y,z);
		insertbg(y,x,z);
	}
	bfsq.push(1);
	bgraph[1].parent = 0;
	bgraph[1].pcost = 0;
	bfs(1);
	vector<long> ansarr,ansc;
	long no=0;
	for(;n!=0;)
	{
		ansarr.push_back(n);
		ansc.push_back(bgraph[n].pcost);
		no++;
		// cout<<"--"<<ansc[no-1]<<"--\n";
		n = bgraph[n].parent;
	}
	// cout<<"++++++"<<no<<"+++++++++"<<endl;
	long long ans=0;
	for(int i=0;i<no-1;i++){
		for(int j=i+1;j<no;j++){
	//		cout<<"+++++++"<<ans<<"+++++++"<<endl;
			ans += ansc[i] - ansc[j] -1; 
		}
	}
	cout<<ans;
	return 0;
}