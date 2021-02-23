#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ld long double 
#define ull unsigned long long
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
    ll m, t2, t3, t4;
    cin >> m >> t2 >> t3 >> t4;
    vector< string > v[m];
    string s;
    for(ll i=0;i<m ;i++){
       ll k ;
       cin >> k;
       for(ll j=0;j<k;j++){
          cin >> s;
          v[i].push_back(s);
       }
    }
   
   ll no =0;
   vector<pair<ll, vector<ll> > > ans;
   
   ll itr = 0;
   ll itm =0;
   while(m>0){
       if(t2<=0 && t3 <=0 && t4<=0){
           break;
       }
        
       if(t2 >0 && m>=2){
            pair<ll, vector<ll>> pair1;
           pair1.first = 2;
           pair1.second.push_back(itm++);
           pair1.second.push_back(itm++);
           ans.push_back(pair1);
           m=m-2;
           t2--;
           no++;
       }
     
       else if(t3 >0&& m>=3){
           pair<ll, vector<ll>> pair1;
           pair1.first = 3;
           pair1.second.push_back(itm++);
           pair1.second.push_back(itm++);
           pair1.second.push_back(itm++);
           ans.push_back(pair1);
           
           t3--;
           m=m-3;
           no++;
       }
       else if(t4 >0  && m>=4){

            pair<ll, vector<ll>> pair1;
           pair1.first = 4;
           pair1.second.push_back(itm++);
           pair1.second.push_back(itm++);
           pair1.second.push_back(itm++);
           pair1.second.push_back(itm++);
           ans.push_back(pair1);
            
           t4--;
           m=m-4;
           no++;
       }
       else{
           break;
       }
   }

   cout << no <<"\n";

   for(ll i=0;i<ans.size();i++){
      cout << ans[i].first <<" ";
      ll p = ans[i].first ;
      ll itp = 0;
      while(p--){
          cout << ans[i].second[itp] <<" ";
         itp++;
      }
      cout <<"\n";
   }


   
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("b_little_bit_of_everything.in", "r", stdin);
    freopen("output_b.txt", "w", stdout);
    
    #endif
     fast;
    int t=1;
    
    while(t--)
        solve();
        
    return 0;
}