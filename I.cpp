#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
bool valid(int x, int y){
	if(x<0 || x>=n) return false;
	if(y<0 || y>=m) return false;
	return true;
}
int main(){
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	x--;y--;
	int dx[]={-2, -2, -1, -1, 1, 1, 2, 2};
	int dy[]={-1, 1, -2, 2, -2, 2, -1, 1};
	int map[n][m];
	queue<int> qu;
	qu.push(x*m+y);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			map[i][j]=-1;
	map[x][y]=0;
	while(qu.size()){
		x=qu.front()/m;
		y=qu.front()%m;
		for(int k=0; k<8; k++){
			if(valid(x+dx[k], y+dy[k]) && map[x+dx[k]][y+dy[k]]==-1){
				qu.push((x+dx[k])*m+(y+dy[k]));
				map[x+dx[k]][y+dy[k]]=map[x][y]+1;
			}
		}
		qu.pop();
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
}
