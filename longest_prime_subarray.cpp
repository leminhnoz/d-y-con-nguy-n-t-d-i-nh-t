#include<bits/stdc++.h>
#define lp 10000005
using namespace std;
bool f[lp+1];
bool kt(int n)
{
    if(n<2) return false;
    for(int i=2;i*i<=n;i++)
{
    if(n%i==0) return false;
}
    return true;
}
void sieve()
{
    fill(f,f+1+lp,true);
    f[0]=f[1]=false;
    for(int i=2;i*i<=lp;i++)
{
    if(f[i])
{
    for(int j=i*i;j<=lp;j+=i)
    f[j]=false;
}
}
}
void sub1(int n,vector <int> &a)
{
    int highest=0,current=0;
    for(int i=0;i<n;i++)
{
    if(kt(a[i])) current++;
    else current=0;
    highest=max(highest,current);
}
    cout<<highest;
}
void sub2(int n,vector<int> &a)
{
    int highest=0,current=0;
    for(int i=0;i<n;i++)
{
    if(f[a[i]]) current++;
    else current=0;
    highest=max(highest,current);
}
    cout<<highest;
}
int main()
{
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    if(n>=100) 
{
    sieve();
    sub2(n,a);
}
    else sub1(n,a);
    return 0;
}