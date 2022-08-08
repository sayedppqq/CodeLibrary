#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define  FIO        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  Fileio     freopen("output.txt","w",stdout);freopen("input.txt","r",stdin);
#define  all(v)     v.begin(),v.end()
#define  rall(v)    v.rbegin(),v.rend()
#define  MEM(a,x)   memset(a,x,sizeof(a))
#define  SZ(v)      v.size()
#define  nl         "\n"
#define  bug        cout<<"bug"<<nl;
#define  pi         acos(-1.0)
#define  ll     long long
#define  pb     push_back
#define  mp     make_pair
#define  pii    pair< int,int >
#define  pll    pair< ll,ll >
#define  vii    vector< int >
#define  vll    vector< ll >
#define  vpi    vector< pii >
#define  vpl    vector<pll>
#define  MX     200005
#define  EPS    1e-12
#define  ss     second
#define  ff     first
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

inline ll powr(int a,int b){ll res=1;while(b){if(b&1) res*=a;a*=a;b/=2;}return res;}
int cases=1;

#ifdef ppqq
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<"  ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif

///******************************************START******************************************
//Ref : https://github.com/sayedgkm/CodeLibrary/blob/master/Graph/Euler_circuit.cpp

multiset<int> adj[MX];
int deg[MX];
bool vis[MX];
vector<int> tour;
void findTour(int u)
{
    while(adj[u].size())
    {
        int v=*adj[u].begin();
        adj[u].erase(adj[u].find(v));
        adj[v].erase(adj[v].find(u));

        findTour(v);
    }
    tour.push_back(u);
}
void dfs(int u)
{
    vis[u]=true;
    for(auto it: adj[u])
    {
        if(vis[it]) continue;
        dfs(it);
    }
}
bool connected(int u,int n)
{
    dfs(u);
    for(int i=1;i<=n;i++) if(!vis[i] && deg[i]) return false;
    return true;
}
bool isEulerCycle(int n)
{
    int st=-1;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]%2) return false;
        if(deg[i]) st=i;
    }

    if(st==-1) return true;
    ///if the graph is already connected no need to check it just return true
    if(connected(st,n)) return true;
    return false;
}
bool isEulerPath(int n)
{
    int st=-1,odd=0;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]%2) odd++;
        if(deg[i]) st=i;
    }

    if(st==-1) return true;
    ///if the graph is already connected no need to check it just return true
    if(connected(st,n) && odd==2) return true;
    return false;
}
void EulerCycle(int n)
{
    if(isEulerCycle(n))
    {
        int st=1;
        for(int i=1;i<=n;i++) if(deg[i]) st=i;
        findTour(st);
        reverse(all(tour));
        for(auto it: tour) cout<<it<<" ";
    }
    else cout<<"IMPOSSIBLE\n";
}
void EulerPath(int n)
{
    if(isEulerPath(n))
    {
        int st=1;
        for(int i=1;i<=n;i++) if(deg[i]%2) st=i;
        findTour(st);
        reverse(all(tour));
        for(auto it: tour) cout<<it<<" ";
    }
    else cout<<"IMPOSSIBLE\n";
}
int main()
{
    FIO;
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++;
        deg[v]++;
    }
}
