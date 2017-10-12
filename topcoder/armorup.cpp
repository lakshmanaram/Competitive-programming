#include <bits/stdc++.h>
using namespace std;
class ArmorUp{
	public:
	long no_of_steps(long double Damage, long currentHP, long maxHP, int max_steps){
		double k1, k2;
		k2 = -Damage/2.0;
		k1 = 2*maxHP-Damage;
		k1 /= maxHP*2;
		// cout<<k1<<" "<<k2<<endl;
		long ans_steps = 0;
		double c = currentHP;
		long steps = max_steps;
		if(((pow(k1,steps)-1)/(k1-1))*k2 + c*pow(k1,steps) > 0) return max_steps+2;
		while(ans_steps < max_steps) {
			steps = ans_steps + max_steps;
			steps /= 2;
			if(((pow(k1,steps)-1)/(k1-1))*k2 + c*pow(k1,steps) > 0){
				ans_steps = steps+1;
			} else {
				max_steps = steps;
			}
		}
		return ans_steps;
	}
	double minimalDamage(int maxHP, int currentHP, int k){
		long double left = 0;
		long double right = maxHP;
		while(left < right && right-left > 0.000001){
			long double mid = left+right;
			mid /= 2.0;
			long steps = no_of_steps(mid, currentHP, maxHP, k);
			// cout<<left<<" "<<right<<" mid = "<<mid<<" "<<steps<<endl<<endl<<endl;
			if(steps <= k){
				right = mid;
			} else {
				left = mid;
			}
		}
		return left;
	}
};
int main() {
	ArmorUp a;
	cout<<a.minimalDamage(100,20,1);
	return 0;
}