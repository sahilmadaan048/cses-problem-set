#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll d[1000005]={};
    for(int i=1;i<1000005;i++)
    {
        for(int j=i;j<1000005;j+=i)
        {
            d[j]++;
        }
    }
    ll n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        cout<<d[x]<<"\n";
    }
}