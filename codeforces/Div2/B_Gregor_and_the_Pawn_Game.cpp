//Rudrakshi

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ld long double
#define all(x) x.begin(), x.end()
#define ull unsigned long long
#define fre(i,n) for (auto i=0; i<n; i++) cout << v[i].first << " " << v[i].second << "\n";
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define fast ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define mod1 1000000007
#define mod2 998244353
#define mod mod1
#define MAX ll(1e3)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//shuffle

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int __lcm(int a, int b) { return (a / __gcd(a, b)) * b; }
int fact(int n) { return n == 0 ? 1LL : n * fact(n - 1) % mod; }
int inverse(int x, int p = mod) { return pow(x, p - 2); }
int nck(int n, int k, int p = mod) {
    return fact(n) * inverse(fact(k), p) % p * inverse(fact(n - k)) % p;
}

void solve()
{

    ll n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    ll arr[2][n];
    for (ll i = 0; i < n; i++) {
        string s = "";
        s += s1[i];
        arr[0][i] = stoi(s) ;

        s = "";
        s += s2[i];
        arr[1][i] = stoi(s) ;


    }
    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (i != 0 && arr[1][i] == 1 && arr[0][i - 1] == 1) {
            arr[0][i - 1] = -1;
            ans++;
        } else if ( arr[1][i] == 1 && arr[0][i] == 0) {
            arr[0][i] = -1;
            ans++;
        }
        else if (i != n - 1 && arr[1][i] == 1 && arr[0][i + 1] == 1) {
            arr[0][i + 1] = -1;
            ans++;
        }
    }
    cout << ans << "\n";
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
