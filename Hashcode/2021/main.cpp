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
    ll D,I,S,V,F;
    cin>>D>>I>>S>>V>>F;

    vector<pair<ll,string>> path[S];
    unordered_map<string,pair<ll,ll>> weight;
    for(int i=0;i<S;i++){
        ll u,v;
        string s;
        ll time;
        cin>>u>>v>>s>>time;
        //street - v 
        //path[u].push_back(make_pair(v,s));
        weight[s] = make_pair(time,v);
    }
    vector<string> routes[V];
    for(int i=0;i<V;i++){
        int t;
        cin>>t;
        while(t--){
            string s;
            cin>>s;
            routes[i].push_back(s);
        }
    }
    map<ll,set<string>> mp;
    set<string> intersections;
    vector<ll> count(S+1,0);
    unordered_map<string,ll> ans; // stret - seconds
    ll c=0;
    for(int i=0;i<V;i++){
        c=0;
        for(int j=0;j<routes[i].size();j++){
            if(j!= routes[i].size()-1){
                set<string> vec = mp[weight[routes[i][j]].second];
                // if(find(vec.begin(),vec.end(),routes[i][j])==vec.end())
                vec.insert(routes[i][j]);
                mp[weight[routes[i][j]].second] = vec;
            ans[routes[i][j]]++;
            }
            // if(ans[routes[i][j]] == 0)
            // c++;
            if(j!=0){
                // if(find(intersections.begin(),intersections.end(),routes[i][j]) == intersections.end())
                // {
                //     c++;
                // }
                intersections.insert(routes[i][j]);
            }
        }
         count[i]=c;
    }
    cout<<mp.size()<<"\n";
    for(auto it = mp.begin(); it != mp.end(); ++it) {
        cout<<it->first<<"\n";
        set<string> vec = it->second;
        cout<<vec.size()<<"\n";
        for(auto j : vec){
            cout<<j<<" "<<ans[j];
            cout<<"\n";
        }
       
    }
    
    //set .. street (uniqueness )
    // for intersection -- get streets
    //for each car --- solution -- seconds ++  street
    //map[street] -- seconds

}
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("f.txt", "r", stdin);
    freopen("f_op.txt", "w", stdout);
    
    #endif
    fast;
    int t=1;
    
    while(t--)
        solve();
        
    return 0;
}