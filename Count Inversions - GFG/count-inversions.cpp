//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long count = 0;
void merge(long long arr[], long long low, long long mid, long long high){
    long long int s1 = mid - low + 1, s2 = high - mid;
    long long int a[s1], b[s2];
    for(long long int i = 0; i < s1; i++){
        a[i] = arr[low + i];
    }
    for (long long int i = 0; i < s2; i++){
        b[i] = arr[mid + 1 + i];
    }
    long long int ind1 = 0, ind2 = 0, i = low;
    while(ind1 < s1 and ind2 < s2){
        if (a[ind1] <= b[ind2]){
            arr[i] = a[ind1];
            ind1++;
        } else {
            arr[i] = b[ind2];
            count += s1 - ind1;
            ind2++;
        }
        i++;
    }
    while(ind1 < s1){
        arr[i] = a[ind1];
        ind1++;
        i++;
    }
    
    while(ind2 < s2){
        arr[i] = b[ind2];
        ind2++;
        i++;
    }
}

    
    void mergeSort(long long arr[], long long low, long long high){
        if (low >= high)
            return;
        long long int mid = (low + high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long int low = 0;
        long long int high = N - 1;
        mergeSort(arr,low,high);
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends