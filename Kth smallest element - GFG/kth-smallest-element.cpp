//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    void quickSelect(int arr[], int l, int r, int k, int p, int &a){
       // cout <<  "*****"<<p << endl;
        for (int i = l; i <= r; i++){
            if (arr[i] < arr[p]){
                swap(arr[i], arr[l]);
                l++;
            }
        }
        swap(arr[l],arr[p]);
        if (l == (k - 1)){
            a = arr[l];
            return;
        }
        else if (l < (k-1)){
           // cout <<  "arr[r] = "<< arr[r]<< endl;
            quickSelect(arr,l+1,r,k,r,a);
            return;
        }
        else{
            //cout <<  "arr[l - 1] = "<< arr[l-1]<< endl;
            quickSelect(arr,0,l-1,k,l-1,a);
            return;
        }
        
    }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int pivot = r;
        int ans = 0;
        quickSelect(arr,l,r,k,pivot,ans);
        return ans;
        
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends