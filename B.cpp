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
	int n, k, now=0;
	cin >> n >> k;
	queue<int> qu;
	for(int i=1; i<=n; i++)
		qu.push(i);
	while(qu.size()){
		for(int i=1; i<k; i++){
			now=qu.front();
			qu.pop();
			qu.push(now);
		}
		now=qu.front();
		cout << now << " ";
		qu.pop();
	}
}
