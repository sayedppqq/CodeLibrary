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

///test & Ref : https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/tutorial/
///Manachars algorithm for finding maximum sized palindrome in a string

int man[1000006];
string convertToNewString(string &s)
{
    string temp="@";
    for(int i=0;i<s.size();i++) { temp+='#'; temp+=s[i]; }
    temp+="#$";
    return temp;
}
string manachers(string &s)
{
    string temp=convertToNewString(s);
    int center=0,R=0;

    for(int i=1;i<temp.size()-1;i++)
    {
        int mirror=center-(i-center);

        if(i < R) man[i]=min(man[mirror],R-i);  ///at least as mirror or i-R

        while(temp[i + 1 + man[i]] == temp[i - 1 - man[i]]) man[i]++;  ///until palindrome

        if(i+man[i] > R)
        {
            center=i;  ///next center is i
            R=i+man[i];
        }
    }

    int index,max_pal_size=0;

    for(int i=1;i<temp.size()-1;i++)
    {
        if(max_pal_size<man[i])
        {
            max_pal_size=man[i];
            index=i;
        }
    }
    cout<<max_pal_size<<endl;
    int st=(index-max_pal_size-1)/2;
    return s.substr(st,max_pal_size);

}
int main()
{
    FIO;
    string s;
    cin>>s;
    cout<<manachers(s);
}
