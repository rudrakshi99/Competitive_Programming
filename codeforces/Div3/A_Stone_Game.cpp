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
#define fr(i,n) for(ll i=0; i<n; i++) cout << arr[i];
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
int str_to_num(string s) {
    int ans = 0;
    reverse(all(s));
    while (s.length()) {
        ans *= 10;
        ans += s.back() - '0';
        s.pop_back();
    }
    return ans;
}


void solve()
{
    ll n, ans = 0;
    cin >> n;
    vector<ll> arr(n);
    ll lar, sm;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    lar = *max_element(arr.begin(), arr.end());
    sm = *min_element(arr.begin(), arr.end());

    auto itl = find(arr.begin(), arr.end(), lar) - arr.begin();
    auto its = find(arr.begin(), arr.end(), sm) - arr.begin();
    //cout << its << " " << itl << "k\n";
    ll in_left = min(itl, its);
    ll in_right = max(itl, its);
    //cout << in_right << " " << in_left << "l\n";
    ll side2 = (n - in_right) + (in_left + 1);
    ll side_r = in_right + 1;
    ll side_l = n - in_left;

    cout << min(side2, min(side_l, side_r)) << "\n";



}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
    fast;
    ll  t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}