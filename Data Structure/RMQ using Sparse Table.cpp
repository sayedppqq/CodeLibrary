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
#define  MX     100005
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

///Problem Link : https://www.spoj.com/problems/RMQSQ/

const int LOG=20;
int maxPower[MX],ara[MX],sparse[MX][LOG];

void makingSparseTable(int n)
{
    for(int i=0;i<n;i++) sparse[i][0]=ara[i];

    for(int i=1;i<LOG;i++)
    {
        for(int j=0;j+(1<<i)-1<n;j++)
        {
            sparse[j][i]=min(sparse[j][i-1],sparse[j+(1<<(i-1))][i-1]);
        }
    }

}
void preprocess(int n)
{
    maxPower[1]=0;
    for(int i=2;i<=n;i++) maxPower[i]=maxPower[i/2]+1;

    makingSparseTable(n);
}

int RMQ(int L,int R)
{
    int len=R-L+1;
    int maxLogValue=maxPower[len];

    return min(sparse[L][maxLogValue] , sparse[R-(1<<maxLogValue)+1][maxLogValue]);
}
int main()
{
    FIO;

    int n,q;
    cin>>n;
    for(int i=0;i<n;i++) cin>>ara[i];

    preprocess(n);

    cin>>q;

    while(q--)
    {
        int L,R;
        cin>>L>>R;

        cout<<RMQ(L,R)<<nl;
    }
}
