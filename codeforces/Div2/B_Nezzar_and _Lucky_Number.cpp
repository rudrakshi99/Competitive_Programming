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
     

bool lucky(ll n, ll d){
  ll num = n;
  while(num!=0){
    ll y = num%10;
    num/=10;
    if(y==d){
       return true;
    }
  }
  
  return false;
 
 
}
void solve()
{

    ll q, d;
    cin >> q >> d;

    ll arr[q];
    for(ll i=0;i<q;i++){
       cin >> arr[i];
    }

    for(ll i=0;i<q;i++){
      
       if(lucky(arr[i],d)){
         cout<<"Yes\n";
       }
       else{
          bool f = false;
          ll s = arr[i];
          for(ll j=d;j<=arr[i];j+=d){
             s=arr[i]-j;
             if(lucky(s,d)){
                f = true;
                break;
             }
          }
          if(f){
            cout<<"Yes\n";
          }
          else{
           cout<<"No\n";
        }

       }
    }
    
    return;
   
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    #endif
    fast;
    int t=1;
    cin>>t;
    while(t--)
    	solve();
    	
    return 0;
}