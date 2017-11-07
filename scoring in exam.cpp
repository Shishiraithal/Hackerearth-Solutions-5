#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int n,q;
    cin>>n>>q;
    pair<long long int,long long int> arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i].second;
    }
    for(long long int i=0;i<n;i++){
        cin>>arr[i].first;
    }
    sort(arr,arr+n);
    reverse(arr,arr+n);
    for(long long int i=1;i<n;i++){
        arr[i].second= arr[i].second+ arr[i-1].second;
    }
    for(long long int j=0;j<q;j++){
        long long int k;
        cin>>k;
       cout<<arr[k-1].second<<endl;
    }
    return 0;
}

