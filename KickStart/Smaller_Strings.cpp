
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



void solve(ll t) {

	ll ans = 0;
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	char s1 = s[0];
	if (n == 1) {
		ans += (s1 - 'a');
	}
	else {
		ans += (s1 - 96);
	}
	ll change = n / 2;

	cout << "Case #" << t << ": " << ans << endl;


}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

#endif
	ll t;
	cin >> t;
	for (ll i = 1; i <= t; i++) {
		solve(i);
	}

}







