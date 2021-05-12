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
#define  MX     1000006
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

///Problem Link : https://codeforces.com/problemset/problem/113/B

const long long MOD[]  = {1000000007LL, 2117566807LL,1000000007LL};
const long long BASE[] = {1572872831LL, 1971536491LL,1000003LL};
long long pwr0[MX],pwr1[MX],HASH0[MX],HASH1[MX];

void init()
{
    pwr0[0]=1;pwr1[0]=1;
    for(int i=1;i<MX;i++)
    {
        pwr0[i]=(pwr0[i-1] * BASE[0]) % MOD[0];
        pwr1[i]=(pwr1[i-1] * BASE[1]) % MOD[1];
    }
}

void Construct(string &s)
{
    HASH0[0]=0;HASH1[0]=0;
    for(int i=1;i<=s.size();i++)
    {
        HASH0[i]=(HASH0[i-1] * BASE[0] + s[i-1]) % MOD[0];
        HASH1[i]=(HASH1[i-1] * BASE[1] + s[i-1]) % MOD[1];
    }
}

long long GetForwardHash0(int l,int r)
{
    long long hash0 = (HASH0[r] - HASH0[l-1]* pwr0[r-l+1]) % MOD[0];
    if(hash0<0) hash0+=MOD[0];
    return hash0;
}

long long GetForwardHash1(int l,int r)
{
    long long hash1 = (HASH1[r] - HASH1[l-1]* pwr1[r-l+1]) % MOD[1];
    if(hash1<0) hash1+=MOD[1];
    return hash1;
}

int main()
{
    FIO;
    init();

    string s,t1,t2;
    cin>>s>>t1>>t2;

    Construct(t1);
    ll hash_t1_0=GetForwardHash0(1,t1.size());
    ll hash_t1_1=GetForwardHash1(1,t1.size());

    Construct(t2);
    ll hash_t2_0=GetForwardHash0(1,t2.size());
    ll hash_t2_1=GetForwardHash1(1,t2.size());

    Construct(s);

    vector<pair<ll,ll>> v;

    int i=1,j=t1.size();
    while(i<=s.size() && j<=s.size())
    {
        if(GetForwardHash0(i,j)==hash_t1_0 && GetForwardHash1(i,j)==hash_t1_1)
        {
             int ii=i,jj=i+t2.size()-1;
             while(ii<=s.size() && jj<=s.size())
             {
                 if(GetForwardHash0(ii,jj)==hash_t2_0 && GetForwardHash1(ii,jj)==hash_t2_1 && jj>=j)
                    v.pb({GetForwardHash0(i,jj),GetForwardHash1(i,jj)});
                 ii++;
                 jj++;
             }
        }
        i++;
        j++;
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    cout<<v.size();
}
