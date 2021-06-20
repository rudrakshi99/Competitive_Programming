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
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    bool f = false;
    ll in1, in2, min = LONG_MAX;
    for (ll i = 0; i < n - 1; i++) {
        if ((arr[i + 1] - arr[i]) < min) {
            f = true;
            in1 = i;
            in2 = i + 1;
            min = ((arr[i + 1] - arr[i]));
        }
    }
    vector<ll> s, lar;

    for (ll i = 0; i < n; i++) {
        if ((in1 == i || in2 == i) ) {
            continue;
        }
        if (arr[i] <= arr[in1]) {
            s.push_back(arr[i]);
        }
        else if ( arr[i] > arr[in1]) {
            lar.push_back(arr[i]);

        }

    }

    cout << arr[in1] << " ";

    for (ll i = 0; i < lar.size(); i++) {
        cout << lar[i] << " ";
    }
    for (ll i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << arr[in2] << " ";

    cout << "\n";
}

int32_t main() {
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