#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sortAll(x) (x).begin(), (x).end()
#define rsortAll(x) (x).rbegin(), (x).rend()
#define N 1e5 + 7
#define mod 1e9 + 7
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl "\n"

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


int binarySearch(int arr[], int n, int target){
    int left = 0, right = n - 1;

    while(left <= right){
        int middle = left + (right - left) / 2;

        if(arr[middle] == target)
            return middle;
        else if(arr[middle] < target)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}
int main() {
    fastio;

    int n; cin >> n;

    int arr[n];
    for(int i=0; i < n; i++){
        cin >> arr[i];
    }
    cout << endl;
    cout << "What to find? " << endl;
    int target;
    cin >> target;

    sort(arr, arr+n);

    int res = binarySearch(arr, n,target);

    if(res != -1){
        cout << "found at " << res << endl;
    } else cout << "Not found";

    
    return 0;
}