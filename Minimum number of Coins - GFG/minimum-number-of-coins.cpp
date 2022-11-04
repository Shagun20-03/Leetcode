//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        //choose the note with highest denoination and keep it subtracting with n
        vector<int> ans;
        int demo[]={1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        int n=10;
        
        for(int i=n-1; i>=0; i--){
            while(N>=demo[i]){
                N-=demo[i];
                ans.push_back(demo[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends