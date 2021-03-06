#include<bits/stdc++.h>

#define EXP 100000
#define siz 1000005
#define ll long long

using namespace std;

ll arr[siz],output[siz];

void countsort(int n,ll place)
{
    int i,freq[EXP]={0};
    for(i=0;i<n;i++)
    {
        freq[(arr[i]/place)%EXP]++;
        output[i]=0;
    }
    for(i=1;i<EXP;i++)
        freq[i]+=freq[i-1];
    for(i=n-1;i>=0;i--)
    {
        output[freq[(arr[i]/place)%EXP]-1]=arr[i];
        freq[(arr[i]/place)%EXP]--;
    }
    for(i=0;i<n;i++)
    {
        arr[i]=output[i];
        printf("%lld ",arr[i]);
    }
 printf("\n");
}

void radixsort(int n,ll maxx)
{
    for(ll i=1;maxx/i;i*=EXP)
    {
        countsort(n,i);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    ll maxx=-1;
    for(int i=0;i<n;i++)
    {
       scanf("%lld",&arr[i]);
       maxx=max(maxx,arr[i]);
    }
    radixsort(n,maxx);
    return 0;
}
