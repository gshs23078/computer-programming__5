#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define fastio cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false)
#define endl "\n"
#define MOD (int)1e9+7
using namespace std;
int h, w;
bool map[4000][4000];
bool valid(int x, int y){
	if(x<0 || x>=h) return false;
	if(y<0 || y>=w) return false;
	return true;
}
struct MAP{
	int where;
	int dis;
};
queue<MAP> qu;
int main(){
	fastio;
	MAP t;
	cin >> h >> w;
	int dx[]={-1, 1, 0, 0};
	int dy[]={0, 0, -1, 1};
	int final;
	string str;
	for(int i=0; i<h; i++){
		cin >> str;
		for(int j=0; j<w; j++){
			if(str[j]=='#')
				map[i][j]=true;
			else if(str[j]=='.')
				map[i][j]=false;
			else if(str[j]=='S'){
				map[i][j]=true;
				t.where=i*w+j;t.dis=0;
				qu.push(t);
			}
			else if(str[j]=='G'){
				map[i][j]=false;
				final=i*w+j;
			}
		}
	}
	while(qu.size()){
		int x=qu.front().where/w;
		int y=qu.front().where%w;
		int dis=qu.front().dis;
		if(qu.front().where==final) break;
		for(int k=0; k<4; k++){
			if(valid(x+dx[k], y+dy[k]) && !map[x+dx[k]][y+dy[k]]){
				map[x+dx[k]][y+dy[k]]=true;
				t.where=(x+dx[k])*w+(y+dy[k]);
				t.dis=dis+1;
				qu.push(t);
			}
		}
		qu.pop();
	}
	cout << qu.front().dis;
	return 0;
}
