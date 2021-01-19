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
#define mod 1000000007
#define mod2 998244353

#define MAX ll(1e3)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//shuffle

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int __lcm(int a, int b) { return (a / __gcd(a, b)) * b; }
int fact(int n) { return n == 0 ? 1LL : n * fact(n - 1) % mod; }
int inverse(int x, int p = mod) { return pow(x, p - 2); }
int nck(int n, int k, int p = mod) {
    return fact(n) * inverse(fact(k), p) % p * inverse(fact(n - k)) % p;
}
// long long calculate(long long p, long long q) 
// { 
//     long long mod = 998244353, expo; 
//     expo = mod - 2; 
 
//     while (expo) { 
 
      
//         if (expo & 1) { 
//             p = (p * q) % mod; 
//         } 
//         q = (q * q) % mod; 
 
        
//         expo >>= 1; 
//     } 
//     return p; 
// } 

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
    string s, ans="";
    cin >> n;
    cin >> s;
     vector<ll> v;
     char k= s[0];
     ll a ;
     if(k=='1'){
      a =1;
    }
    else{
      a =0;
     
    }
  
    ll b =1;
    
    ll p  = a+b;
    ans+='1';
   
    // for(ll i=1;i<s.length();i++){
    //    cout<<s[i]<<" ";
    // }
    for(ll i=1;i<s.length();i++){
        k = s[i];
        //cout<<k<<" ";
        if(k=='1'){
          a =1;
          if((a+1)!=p){
              p = a+1;
              ans+="1";
           }
           else{
             p = a+0;
              ans+="0";

           }
      }
      else{
          a =0;
          if((a+1)!=p){
              p = a+1;
              ans+="1";
           }
           else{
             p = a+0;
              ans+="0";

           }

      }
           

     }
     cout<<ans<<"\n";

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