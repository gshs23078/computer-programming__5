#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define int long long
#define endl "\n"
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)
using namespace std;
bool cmp(pair<int, int> p1, pair<int, int> p2){
	if(p1.second==p2.second)
		return p1.first<p2.first;
	return p1.second<p2.second;
}
signed main(){
	int n, m;
	cin >> n >> m;
	int prev[n]={0};
	bool inqueue[n]={0};
	queue<int> todo[n];
	vector<int> used[m+1];
	fori(i, 0, n){
		int a;
		cin >> a;
		fori(j, 0, a){
			int k;
			cin >> k;
			todo[i].push(k);
		}
	}
	queue<int> touse[m+1];
	while(1){
		vector<pair<int, int> > Touse[m+1];
		int chk=0;
		fori(i, 0, n){
			if(todo[i].empty()){
				chk++;
				continue;
			}
			if(inqueue[i]) continue;
			Touse[todo[i].front()].push_back(make_pair(i, prev[i]));
			inqueue[i]=true;
		}
		if(chk==n) break;
		fori(i, 1, m+1){
			sort(Touse[i].begin(), Touse[i].end(), cmp);
			int ppp=Touse[i].size();
			fori(j, 0, ppp)
				touse[i].push(Touse[i][j].first);
		}
		fori(i, 1, m+1){
			if(touse[i].empty()) continue;
			todo[touse[i].front()].pop();
			used[i].push_back(touse[i].front());
			prev[touse[i].front()]=i;
			inqueue[touse[i].front()]=false;
			touse[i].pop();
		}
	}
	fori(i, 1, m+1){
		int l=used[i].size();
		cout << l << " ";
		fori(j, 0, l)
			cout << used[i][j]+1 << " ";
		cout << endl;
	}
}
