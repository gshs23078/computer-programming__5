#include <iostream>
#include <queue>
using namespace std;
#define int long long
#define endl "\n"
bool map[500][500];
bool valid(int n, int m, int x, int y){
	return (x>=0 && x<n && y>=0 && y<m);
}
int solve(int n, int m, int x, int y, int k){
	int dis=0, last=-1;
	int dx[]={-2, -2, -1, -1, 1, 1, 2, 2};
	int dy[]={-1, 1, -2, 2, -2, 2, -1, 1};
	queue<pair<int, int> > qu;
	qu.push(make_pair(x*m+y, dis));
	while(qu.size()){
		x=qu.front().first/m;
		y=qu.front().first%m;
		dis=qu.front().second;
		if(dis==k) break;
		if(dis==last+1){
			last=dis;
			for(int i=0; i<n; i++)
				for(int j=0; j<m; j++)
					if(map[i][j])
						map[i][j]=false;
		}
		for(int i=0; i<8; i++){
			if(valid(n, m, x+dx[i], y+dy[i])){
				if(map[x+dx[i]][y+dy[i]])
					continue;
				map[x+dx[i]][y+dy[i]]=true;
				qu.push(make_pair((x+dx[i])*m+(y+dy[i]), dis+1));
			}
		}
		qu.pop();
	}
	while(qu.size()){
		x=qu.front().first/m;
		y=qu.front().first%m;
		map[x][y]=true;
		qu.pop();
	}
	int c=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			if(map[i][j]){
				c++;
			}
		}
	return c;
}
signed main(){
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	for(int i=0; i<500; i++)
		for(int j=0; j<500; j++)
			map[i][j]=false;
	x--;y--;n--;m--;
	int xx=x, yy=y, nn=n, mm=m;
	if(x>200){
		xx=200;
		nn-=(x-200);
	}
	if(n-x>200){
		nn-=(n-x-200);
	}
	if(y>200){
		yy=200;
		mm-=(y-200);
	}
	if(m-y>200){
		mm-=(m-y-200);
	}
	nn++;
	mm++;
	cout << (n+1)*(m+1)-solve(nn, mm, xx, yy, k); // 나중에 바꾸기!! 
}
