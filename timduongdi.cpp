#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int n; 
int a[100][100];
void loang(int i, int j){
	a[i][j] = 0;
	for(int k = 0; k < 8; k++){
		int inew = i + dx[k];
		int jnew = j + dy[k];
		if(inew >= 0 && inew < n && jnew >= 0 && jnew < n && a[inew][jnew] == 1){
			loang(inew, jnew);
		}
	}
}
int main(){
	cin >> n ;
	int s, t, u, v; cin >> s >> t >> u >> v;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}	
	
	loang(s - 1, t - 1);
	
	if(a[u - 1][v - 1] == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}