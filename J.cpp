#include <iostream>
#include <queue>
using namespace std;
int f(int p){
	return (p+10000)%10000;
}
int main(){
	int now, pw, n, ans;
	cin >> now >> pw;
	cin >> n;
	int no[1001]={0};
	bool c[10001]={0};
	for(int i=0; i<n; i++){
		cin >> no[i];
	}
	queue<pair<int, int> > qu;
	int d[]={-1000, -100, -10, -1, 1, 10, 100, 1000};
	qu.push(make_pair(now, 0));
	while(qu.size()){
		now=qu.front().first;
		ans=qu.front().second;
		if(now==pw) break;
		for(int i=0; i<8; i++){
			bool chk=false;
			if(c[f(now+d[i])]) continue;
			for(int j=0; j<n; j++){
				if(no[j]==f(now+d[i])){
					chk=true;
					break;
				}
			}
			if(chk) continue;
			c[f(now+d[i])]=true;
			qu.push(make_pair(f(now+d[i]), ans+1));
		}
		qu.pop();
	}
	cout << ans;
}
