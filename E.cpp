#include <iostream>
#include <queue>
using namespace std;
#define int long long
#define endl "\n"
#define mod 1000000007
signed main(){
	int n, m, k, l=0, ans=1;
	cin >> n >> m >> k;
	k+=2;
	while(1<<l < k) l++;
	l--;
	k-=(1<<l)+1;
	while(l--){
		if(k&1) ans*=m;
		else ans*=n;
		k>>=1;
		ans%=mod;
	}
	cout << ans;
}
