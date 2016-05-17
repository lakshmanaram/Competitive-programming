#include<bits/stdc++.h>
using namespace std;
struct node{
	long long val;
	long left, right;
};
int main()
{
	long n;
	cin>>n;
	vector<node> a;
	long maxind,minind;
	for(long i=0;i<n;i++){
		node temp;
		cin>>temp.val;
		temp.right = temp.left = -1;
		if(i!=0){
			if(temp.val > a[maxind].val){
				a[maxind].right = i;
				cout<<a[maxind].val<<" ";
				maxind = i;
			} else if( temp.val < a[minind].val ){
				a[minind].left = i;
				cout<<a[minind].val<<" ";
				minind = i;
			} else {
				long x = 0;
				while(true){
					if(a[x].val < temp.val){
						if(a[x].right == -1){
							a[x].right = i;
							cout<<a[x].val<<" ";
							break;
						} else {
							x = a[x].right;
						}
					} else {
						if(a[x].left == -1){
							a[x].left = i;
							cout<<a[x].val<<" ";
							break;
						} else {
							x = a[x].left;
						}
					}
				}
			}
		} else {
			maxind = minind = 0;
		}
		a.push_back(temp);
	}
	return 0;
}
