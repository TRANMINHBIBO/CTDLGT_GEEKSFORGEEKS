#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[500][500];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void loang(int i, int j,int x1, int x2, int y1, int y2){
	a[i][j] = 2;
	for(int k = 0; k < 8; k++){
		int inew = i + dx[k];
		int jnew = j + dy[k];
		if(inew >= x1 - 1 && inew <= x2 - 1 && jnew >= y1 - 1 && jnew <= y2 - 1){
			loang(inew, jnew, x1, x2, y1, y2);
		}
	}
}
int main(){
	int n, m; cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cin >> a[i][j];
	}	
	int q; cin >> q;
	for(int i = 1; i <= q; i++){
		int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
		for(int i = x1 - 1; i <= x2 - 1; i++){
			for(int j = y1 - 1; j <= y2 - 1; j++){
				if(a[i][j] == 1){
					loang(i, j, x1, x2, y1, y2);
				}
			}
		}
		int res = 0;
		for(int i = x1 - 1; i <= x2 - 1; i++){
			for(int j = y1 - 1; j <= y2 - 1; j++){
				if(a[i][j] == 2){
					res++;
				}
			}
		}
		cout << res << endl;

	}
}