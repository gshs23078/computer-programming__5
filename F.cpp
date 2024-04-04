#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
	int m, n;
	cin >> n >> m;
	vector<int> v(n);
	queue<int> qu;
	for(int i=0; i<m; i++){
		int x;
		cin >> x;
		v[x-1]=1;
		qu.push(x-1);
	}
	while(qu.size()){
		int x=qu.front();
		if(x+1<n && (v[x+1]>v[x]+1 || v[x+1]==0)){
			v[x+1]=v[x]+1;
			qu.push(x+1);
		}
		if(x-1>=0 && (v[x-1]>v[x]+1 || v[x-1]==0)){
			v[x-1]=v[x]+1;
			qu.push(x-1);
		}
		qu.pop();
	}
	int chk=0;
	for(int i=0; i<n; i++)
		if(v[i]==1) chk++;
//	if(chk!=m) cout << "거짓말!!\n";
	for(int i=0; i<n; i++)
		cout << v[i] << " ";
}
