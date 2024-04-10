#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define endl "\n"
#define int long long
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a; i>=b; i--)
using namespace std;
int map[1000][1000];
bool check[1000][1000];
queue<int> dead;
signed main(){
	int h, w, ans=0;
	cin >> h >> w;
	fori(i, 0, h){
		string str;
		cin >> str;
		fori(j, 0, w){
			if(str[j]=='.') map[i][j]=0;
			else map[i][j]=str[j]-'0';
			check[i][j]=false;
		}
	}
	fori(i, 1, h-1) fori(j, 1, w-1){
		if(!map[i][j]) continue;
		int chk=0;
		fori(p, i-1, i+2) fori(q, j-1, j+2){
			if(p==i && q==j) continue;
			if(!map[p][q]) chk++;
		}
		if(chk>=map[i][j]){
			dead.push(i*w+j);
			check[i][j]=true;
		}
	}
	while(dead.size()){
		ans++;
		int l=dead.size();
		while(l--){
			map[dead.front()/w][dead.front()%w]=0;
			dead.push(dead.front());
			dead.pop();
		}
		l=dead.size();
		while(l--){
			int x=dead.front()/w;
			int y=dead.front()%w;
			dead.pop();
			fori(i, x-1, x+2) fori(j, y-1, y+2){
				if(i==x && j==y) continue;
				if(!map[i][j]) continue;
				if(check[i][j]) continue;
				int chk=0;
				fori(p, i-1, i+2) fori(q, j-1, j+2){
					if(p==i && q==j) continue;
					if(!map[p][q]) chk++;
				}
				if(chk>=map[i][j]){
					check[i][j]=true;
					dead.push(i*w+j);
				}
			}
		}
	}
	cout << ans;
}
