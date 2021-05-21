
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



void solve(ll t) {

	ll ans = 0, r, c;
	cin >> r >> c;
	ll mat[r][c] ;
	ll org[r][c];
	priority_queue<pair<ll, pair< ll, ll> > >  q; // max heap
	for (ll i = 0; i < r; i++) {
		for (ll j = 0; j < c; j++) {
			cin >> mat[i][j];
			org[i][j] = mat[i][j];
			q.push({mat[i][j], {i, j}});
		}
	}
	vector<vector<bool>> visited(r, vector<bool>(c, false));


	while (!q.empty()) {
		ll t = q.top().first;
		ll x = q.top().second.first;
		ll y = q.top().second.second;
		q.pop();

		if (visited[x][y]) {
			continue;
		}
		visited[x][y] = true;

		if (x + 1 < r and !visited[x + 1][y])
		{
			ll diff = mat[x][y] - mat[x + 1][y];

			if (diff > 1)
			{
				mat[x + 1][y] = mat[x][y] - 1;
				q.push({mat[x + 1][y], {x + 1, y}});
			}
		}

		if (x - 1 >= 0 and !visited[x - 1][y])
		{
			ll diff = mat[x][y] - mat[x - 1][y];

			if (diff > 1)
			{
				mat[x - 1][y] = mat[x][y] - 1;
				q.push({mat[x - 1][y], {x - 1, y}});
			}
		}

		if (y + 1 < c and !visited[x][y + 1])
		{
			ll diff = mat[x][y] - mat[x][y + 1];

			if (diff > 1)
			{
				mat[x][y + 1] = mat[x][y] - 1;
				q.push({mat[x][y + 1], {x, y + 1}});
			}
		}

		if (y - 1 >= 0 and !visited[x][y - 1])
		{
			ll diff = mat[x][y] - mat[x][y - 1];

			if (diff > 1)
			{
				mat[x][y - 1] = mat[x][y] - 1;
				q.push({mat[x][y - 1], {x, y - 1}});
			}
		}
	}

	for (ll i = 0; i < r; i++) {
		for (ll j = 0; j < c; j++) {
			//cout << mat[i][j] << " ";
			ans += (mat[i][j] - org[i][j]);
		}
	}
	cout << "Case #" << t << ": " << ans << endl;


}


int main() {


	ll t;
	cin >> t;
	for (ll i = 1; i <= t; i++) {
		solve(i);
	}

}







