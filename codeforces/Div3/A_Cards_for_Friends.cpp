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
     ll w,h,n;
     cin >> w >> h >> n;
     bool f=false,f2=false;
     if(n==1){
       cout<<"YES\n";
     }else{
     	ll c=1;
        if(w%2==0){
           while(w%2==0){
              w=w/2;
              c*=2;
              
           }
           //cout<<c;
       }
        ll c2=1;
          
               if(h%2==0){

           while(h%2==0){
           	 c2*=2;
              h=h/2;
              //cout<<h<<" ";
             
              
           }
       }
       // cout<<c2;
        
               if((c*c2)>=n){
                 cout<<"YES\n";
               }
               else{
              cout<<"NO\n";
           }
           
           
        }
     }
   

int32_t main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    fast;
    ll t=1;
    cin>>t;
    while(t--)
    	solve();
    	
    return 0;
}