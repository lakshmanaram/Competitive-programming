#include <bits/stdc++.h>
using namespace std;
bool vis[200];
int n,m;
char mat[10][10];
int excess1[10][10];
int excess2[10][10];
long long ans=0;
void func(int a){
	if(a==n){
		ans++;
		return;
	}
	//int funcflag=0;
	int i=a,j=0;
	for(j=0;j<m;j++)
	{
		if((excess1[i][j]!=-1)&&(vis[excess1[i][j]]==false)&&(vis[excess2[i][j]]==false)){
			// cout<<a<<"    "<<i<<"   "<<j<<endl;
			vis[excess1[i][j]]=true;
			vis[excess2[i][j]]=true;
			func(a+1);
			vis[excess1[i][j]]=false;
			vis[excess2[i][j]]=false;
		}
	}
	// if(funcflag==0)
	// 	return;
}
int main() {
	fill(vis,vis+200,false);
	int val=0;
	int flag=0;
	int tempi,tempj;
	cin>>n>>m;
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			excess1[i][j]=-1;
			excess2[i][j]=-1;
		}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	for(i=n-1;i>=0;i--){
		tempi=i;
		for(j=0;(tempi<n)&&(j<m);j++,tempi++){
			if(flag==0){
				if(mat[tempi][j]!='*'){
					flag=1;
					excess1[tempi][j]=val;
				}
			}
			else if(flag==1){
				if(mat[tempi][j]!='*'){
					excess1[tempi][j]=val;
				}
				else{
					val++;
					flag=0;
				}
			}
		}
		if(flag==1){
			val++;
			flag=0;
		}
	}
	for(j=1;j<m;j++){
		tempj=j;
		for(i=0;(i<n)&&(tempj<m);tempj++,i++){
			if(flag==0){
				if(mat[i][tempj]!='*'){
					flag=1;
					excess1[i][tempj]=val;
				}
			}
			else if(flag==1){
				if(mat[i][tempj]!='*'){
					excess1[i][tempj]=val;
				}
				else{
					val++;
					flag=0;
				}
			}	
		}
		if(flag==1){
			val++;
			flag=0;
		}
	}
	for(i=0;i<=n;i++){
		tempi=i;
		for(j=0;(tempi>=0)&&(j<m);j++,tempi--){
			if(flag==0){
				if(mat[tempi][j]!='*'){
					flag=1;
					excess2[tempi][j]=val;
				}
			}
			else if(flag==1){
				if(mat[tempi][j]!='*'){
					excess2[tempi][j]=val;
				}
				else{
					val++;
					flag=0;
				}
			}
		}
		if(flag==1){
			val++;
			flag=0;
		}
	}
	for(j=1;j<m;j++){
		tempj=j;
		for(i=n-1;(i>=0)&&(tempj<m);tempj++,i--){
			if(flag==0){
				if(mat[i][tempj]!='*'){
					flag=1;
					excess2[i][tempj]=val;
				}
			}
			else if(flag==1){
				if(mat[i][tempj]!='*'){
					excess2[i][tempj]=val;
				}
				else{
					val++;
					flag=0;
				}
			}	
		}
		if(flag==1){
			val++;
			flag=0;
		}
	}
	
	// for(i=0;i<n;i++){
	// 	for(j=0;j<m;j++)
	// 		cout<<excess1[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	// for(i=0;i<n;i++){
	// 	for(j=0;j<m;j++)
	// 		cout<<excess2[i][j]<<" ";
	// 	cout<<endl;
	// }
	func(0);
	cout<<ans;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
