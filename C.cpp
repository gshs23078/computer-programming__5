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
	int n, m, k;
	cin >> n >> m;
	int animal[m][n];
	int idx[m]={0};
	for(int i=0; i<n; i++){
		cin >> k;
		animal[k-1][idx[k-1]++]=i+1;
	}
	for(int i=0; i<m; i++){
		cout << idx[i] << " ";
		for(int j=0; j<idx[i]; j++){
			cout << animal[i][j] << " ";
		}
		cout << endl;
	}
}
