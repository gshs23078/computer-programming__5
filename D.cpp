#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define int long long
using namespace std;
signed main(){
	int n, m, num=1;
	cin >> n >> m;
	vector<int> ans[n];
	vector<int> now(n, 1);
	queue<int> ppl;
	for(int i=0; i<m; i++){
		int k;cin >> k;ppl.push(k);
	}
	while(ppl.size()){
		for(int i=0; i<n; i++){
			if(ppl.empty()) break;
			now[i]--;
			if(now[i]==0){
				now[i]=ppl.front();
				ans[i].push_back(num++);
				ppl.pop();
			}
		}
	}
	for(int i=0; i<n; i++){
		int l=ans[i].size();
		for(int j=0; j<l; j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
