//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int a[], int b[], int c[], int n1, int n2, int n3)
        {
            //code here.
            vector<int>temp;
            int i = 0, j = 0,k = 0;
            while(i < n1 and j < n2){
                if (a[i] == b[j]){
                    temp.push_back(a[i]);
                    i++;
                    j++;
                }
                else if (a[i] < b[j]){
                    i++;
                }
                else{
                    j++;
                }
            }
            i = 0; 
            j = 0;
            set<int>anss;
            while(i < n3 and j < temp.size()){
                if (c[i] == temp[j]){
                    anss.insert({c[i]});
                    i++;
                    j++;
                }
                else if (c[i] < temp[j]){
                    i++;
                }
                else{
                    j++;
                }
            }
            vector<int>ans;
            for(auto x:anss){
                ans.push_back(x);
            }
            return ans;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends