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

int Partition(int array[], int low, int high){

  int pivot = array[low];
  int i = low;
  int j = high;

  while(true){
    while(array[i] <= pivot && i <= high){
      i++;
    }
    while(array[j] > pivot && j >= low){
      j--;
    }
    if(i >=j){
      break;
    }
    swap(array[i],array[j]);
  }
  swap(array[low]/*which is pivot*/, array[j]);
  return j; //index of pivot
}

// reversed -----------------------

int RevPartition(int array[], int low, int high) {
    int pivot = array[low];
    int i = low;
    int j = high;

    while (true) {
        // For descending order
        while (array[i] >= pivot && i <= high) {
            i++;
        }
        while (array[j] < pivot && j >= low) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(array[i], array[j]);
    }
    swap(array[low], array[j]);
    return j; // index of pivot
}


void qSort(int array[],int low, int high){
  if(low  < high){
    int j = Partition(array, low, high);
    qSort(array, low,j);
    qSort(array,j+1,high);
  }

}
void RevqSort(int array[],int low, int high){
  if(low  < high){
    int j = RevPartition(array, low, high);
    RevqSort(array, low,j);
    RevqSort(array,j+1,high);
  }

}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;//size
  cin >> n;
  int array[n];
  vector<int> vec;
  while(n--){
    int x;
    cin >> x;
    vec.push_back(x);
  }
  cout << "sorted array is: ";
  qSort(vec.data(), 0, vec.size() - 1);
  for(auto it: vec){
    cout << it << " ";
  }
  
  cout << "\nReversed sorted array is: ";
  RevqSort(vec.data(), 0, vec.size() - 1);
  for(auto it: vec){
    cout << it << " ";
  }
}