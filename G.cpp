#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define fastio cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false)
#define int long long
#define endl "\n"
#define MOD (int)1e9+7
using namespace std;
int n, m, k;
bool valid(int x, int y){
	if(x<0 || x>=n) return false;
	if(y<0 || y>=m) return false;
	return true;
}
signed main(){
	fastio;
	cin >> n >> m >> k;
	int map[n][m];
	int dx[]={-1, 1, 0, 0};
	int dy[]={0, 0, -1, 1};
	queue<pair<int, int> > qu;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			map[i][j]=2147483647;
	for(int i=0; i<k; i++){
		int x, y;
		cin >> x >> y;
		map[x-1][y-1]=1;
		qu.push(make_pair(x-1, y-1));
	}
	while(qu.size()){
		int x=qu.front().first;
		int y=qu.front().second;
		for(int k=0; k<4; k++){
			if(valid(x+dx[k], y+dy[k]) && map[x+dx[k]][y+dy[k]]>map[x][y]+1){
				map[x+dx[k]][y+dy[k]]=map[x][y]+1;
				qu.push(make_pair(x+dx[k], y+dy[k]));
			}
		}
		qu.pop();
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
}
