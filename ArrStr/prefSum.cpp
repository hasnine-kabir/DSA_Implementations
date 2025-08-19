 //formula for prefix sum
 // pref[i] = pref[i-1]+arr[i-1]

//range sum query
// sum(l,r) = pref[r+1] - pref[l]
// sum(l,r) = pref[r] - pref[l-1] this one is for 1-based indexing






#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,q;
    cin >> n >> q;

    vector<int>arr(n);
    for(int i = 0; i<n; i++){  // original array input
        cin >> arr[i];
    }

    vector<ll> pref(n+1);
    for(int i = 1 ; i<=n ; i++){
        pref[i]= pref[i-1]+arr[i-1];
    }

    for(int i = 0; i<q; i++){
        int l,r;
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << endl;
    }

    return 0;
}