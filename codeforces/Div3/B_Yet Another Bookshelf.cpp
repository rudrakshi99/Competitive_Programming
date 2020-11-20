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
     int n;
     cin >> n;
     int arr[n];
     int no=0;
     for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]==1){
            no++;
        }

     }
     if(no==1){
       cout<<0<<"\n";
       return;
     }

     int cnt = 0, s;
     int check = 0, one = 0;
     for(int i=0;i<n-1;i++){
        if(arr[i]==1){
           one++;
         }
        if(arr[i]==1 && arr[i+1]==0){
           s=i;
           break;
        }
        if(arr[i]==1 && arr[i+1]==1){
          check++;
       }
     }
     // cout<<one<<"l\n";

     if(check+1 == no){
        cout<<0<<"\n";
        return;
     }


     int ini = s;
     // cout<<s<<"\n";
     for(int i=s+1;i<n;i++){
         if(arr[i]==0){
            cnt++;
           // cout<<"k";
         }
         if(arr[i]==1){
           one++;
         }
         if(one == no){
            // cout<<one<<" "<<no<<"\n";
            // cout<<i<<"oo";
           break;
        }
     }
      // cout<<one<<"l\n";
     cout<<cnt<<"\n";
   
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