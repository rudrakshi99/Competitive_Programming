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
     
 int check(vector<int>&a , int k){
            int total=0;
            int n=a.size();
            int sum=0;
            int j=0;
            for(int i=0;i<n;i++){
                sum+=a[i];
                if(sum==k){
                    total+=(i-j);
                    j=i+1;
                    sum=0;
                }
                else if(sum>k){
                    return -1;
                }
            }
            return total;
 }

void solve()
{
    
     int n;
            cin>>n;
            vector<int>a(n);
            int total=0;
            for(int i=0;i<n;i++){
                cin>>a[i];
                total+=a[i];
            }
            int ans=n-1;
            for(int i=1;i*i<=total;i++){
                if(total%i==0){
                    int f1=i;
                    int f2=total/i;
                    int a1=check(a,f1);
                    int a2=check(a,f2);
                    // cout<<f1<<" "<<a1<<"\n";
                    // cout<<f2<<" "<<a2<<"\n";
                    if(a1!=-1)
                        ans=min(ans,a1);
                    if(a2!=-1)
                        ans=min(ans,a2);
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