#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <string>
#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(NULL);cout.tie(NULL);ios::sync_with_stdio(false)
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
int main(){
	fastio;
	int m, n, k, d=0, f;
	cin >> n >> m >> k;
	queue<int> q;
	q.push(0);
	while(q.size()){
		f=q.front();
		q.pop();
		if(n>0){
			q.push(f+1);
			q.push(f+1);
			n--;
		}
		else if(m>0){
			q.push(f+1);
			m--;
		}
		else k--;
	}
	if(!k) cout << f;
	else cout << "impossible.";
}
