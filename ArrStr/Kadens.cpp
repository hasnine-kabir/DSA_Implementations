#include<bits/stdc++.h>
using namespace std;
#define ll long long

//all possible sub arrays --

void subarray(){
    int n,cnt=0;  cin >> n;

    vector<int> arr(n);

    for(auto &it : arr) cin >> it;

      for(int i=0; i<n; i++){   // for staring point
        for(int j=i; j<n; j++){   // for ending point
            for(int k=i; k<=j; k++){  //printing every sub array
                cout << arr[k] << " ";
            }
            cout << endl;
            cnt++;
        }
      }
      cout << "Total subarrays: " << cnt << endl;
}
//---------------------------------------------------------------------------

//brute force tc O(n^2)
void maxSubarraySum(){ 
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &it: arr) cin >> it;

    int maxSum = INT_MIN;
    for(int st=0; st<n; st++){
        int currSum=0;
        for(int end=st; end<n; end++){
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
    }
    cout << maxSum << endl;
}



// Kadane's Algorithm for Maximum Subarray Sum

void kadane(){
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &it: arr) cin >> it;

    int currSum=0, maxSum=INT_MIN;
    
    for(int i=0; i<n; i++){
        currSum += arr[i];
        maxSum = max(maxSum,currSum);
        if(currSum < 0) currSum = 0;
    }
    cout << maxSum << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    kadane();

    return 0;
}