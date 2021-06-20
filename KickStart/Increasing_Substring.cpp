
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



void solve(ll t) {

	ll ans = 1;
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll arr[n + 1];
	arr[0] = 1;
	for (ll i = 1; i < s.length(); i++) {
		if (s[i] > s[i - 1]) {
			ans++;

		} else {
			ans = 1;
		}
		arr[i] = ans;

	}
	cout << "Case #" << t << ": " ;
	for (ll i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";

}


int main() {


	ll t;
	cin >> t;
	for (ll i = 1; i <= t; i++) {
		solve(i);
	}

}







