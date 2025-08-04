//here is the basics of quicksort algorithm-----

/*
  so we need to choose a  pivot element from the array
    then partition the array in two parts
    one part less then pivot and other greater
    then recursively apply the same logic
    until sorted
    then combine

    TC: O(nlogn) avg case
    TC: O(n^2) worst case

    the pivot will be in correct position after partitioning
*/

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;

    while (true) {
        //boro paowa prjnto right e jabe i++ hobe
        while(i <= high && arr[i]<=pivot){
            i++;
        }
        while(j >= low && arr[j] > pivot){
            j--;
        }

        //i j cross krle loop vangbe
        if (i >= j){
            break;
        }
        swap(arr[i],arr[j]);
    }
    //sob seshe j ar pivot swap
    swap(arr[low],arr[j]);
    return j; //pivot index

} 

void quickSort(int arr[], int low, int high){

    if(low<high){
        int partIndex = partition(arr,low,high);

        //recursive calling
        quickSort(arr,low,partIndex-1);
        quickSort(arr,partIndex+1,high);
    }
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++){
      cin >> arr[i]; 
    }

  quickSort(arr.data(), 0, n - 1);

  for(auto it:arr){
    cout << it << " ";
  }

  
    return 0;
}