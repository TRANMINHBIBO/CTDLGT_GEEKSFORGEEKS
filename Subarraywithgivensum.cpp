#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n, s; cin >> n >> s;
	int a[n];
	for(int &x : a) cin >> x;
	ll sum = a[0], r = 0, l = 0;
	while(r < n){
		if(sum < s){
			r++;
			sum += a[r];
			continue;
		}
		else if(sum > s){	
			sum -= a[l];
			l++;
		}
		else if(sum == s){
			cout << l + 1 << ' ' << r + 1 << endl;
			return 0;
		}

	}
	cout << -1 << endl;
}