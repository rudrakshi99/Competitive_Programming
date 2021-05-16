
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll r, c;
vector<vector<ll>> grid;
vector<vector<pair<ll, ll>>> downandright;
vector<vector<pair<ll, ll>>> topandleft;



ll rec(ll i, ll j, bool isHorizontal) {
    ll x;
    if (!isHorizontal && downandright[i][j].first != -1) return downandright[i][j].first;
    if (isHorizontal && downandright[i][j].second != -1) return downandright[i][j].second;

    downandright[i][j].first = grid[i][j];
    downandright[i][j].second = grid[i][j];

    if (grid[i][j] == 0) {
        if (i + 1 < r) rec(i + 1, j, false);
        if (j + 1 < c) rec(i, j + 1, true);
        return 0;
    }

    if (i + 1 < r) {
        x = rec(i + 1, j, false);
        downandright[i][j].first += x;
    }
    if (j + 1 < c) {
        x = rec(i, j + 1, true);
        downandright[i][j].second += x;
    }

    if (!isHorizontal) return downandright[i][j].first;
    else return downandright[i][j].second;
}



ll rec1(ll i, ll j, bool isHorizontal) {
    ll x;
    if (!isHorizontal && topandleft[i][j].first != -1) return topandleft[i][j].first;
    if (isHorizontal && topandleft[i][j].second != -1) return topandleft[i][j].second;


    topandleft[i][j].first = grid[i][j];
    topandleft[i][j].second = grid[i][j];


    if (grid[i][j] == 0) {
        if (i - 1 >= 0) rec1(i - 1, j, false);
        if (j - 1 >= 0) rec1(i, j - 1, true);
        return 0;
    }

    if (i - 1 >= 0) {
        x = rec1(i - 1, j, false);
        topandleft[i][j].first += x;
    }
    if (j - 1 >= 0) {
        x = rec1(i, j - 1, true);
        topandleft[i][j].second += x;
    }

    if (!isHorizontal) return topandleft[i][j].first;
    else return topandleft[i][j].second;
}

void solve(ll t) {

    ll u, v, x;

    cin >> r >> c;
    grid = vector<vector<ll>>(r, vector<ll>(c));
    for (ll i = 0; i < r; i++)for (ll j = 0; j < c; j++)cin >> grid[i][j];

    downandright = vector<vector<pair<ll, ll>>> (r, vector<pair<ll, ll>>(c, { -1, -1}));
    topandleft = vector<vector<pair<ll, ll>>> (r, vector<pair<ll, ll>>(c, { -1, -1}));

    rec(0, 0, true);
    rec1(r - 1, c - 1, true);


    ll ans = 0;

    for (ll i = 0; i < r; i++) {
        for (ll j = 0; j < c; j++) {
            if (grid[i][j] == 1) {
                ll top = topandleft[i][j].first;
                ll down = downandright[i][j].first;
                ll left = topandleft[i][j].second;
                ll right = downandright[i][j].second;


                if (min(left, top) >= 2 &&  max(left, top) >= 4) {
                    u = min(left, top);
                    v = max(left, top);
                    
                    ll total = min(u-1,v/2-1) + min(u/2-1,v - 1);
                    //cout << i + 1 << " " << j + 1 << " " << total << endl;
                    ans += total;
                }
                if (min(left, down) >= 2 && max(left, down) >= 4) {
                    u = min(left, down);
                    v = max(left, down);
                    ll total = min(u-1,v/2-1) + min(u/2-1,v - 1);
                    //cout << i + 1 << " " << j + 1 << " " << total << endl;
                    ans += total;
                }
                if (min(right, top) >= 2 && max(right, top) >= 4) {
                    u = min(right, top);
                    v = max(right, top);
                    x = min(u , v / 2);
                    ll total = min(u - 1,v/2-1) + min(u/2-1,v - 1);
                    //cout << i + 1 << " " << j + 1 << " " << total << endl;
                    ans += total;
                }
                if (min(right, down) >= 2 && max(right, down) >= 4) {
                    u = min(right, down);
                    v = max(right, down);
    
                    ll total = min(u-1,v/2-1) + min(u/2-1,v - 1);
                    //cout << i + 1 << " " << j + 1 << " " << total << endl;
                    ans += total;
                }

            }
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






