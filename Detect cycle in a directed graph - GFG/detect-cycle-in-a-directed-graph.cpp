//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfsCheck(int node, vector<int> adj[], int vis[])
    {
        vis[node]=1;
        //pathVis[node]=1;
        
        //traverse for adjacent nodes
        for(auto it: adj[node])
        {
            //if node is not visited
            if(!vis[it])
            {
                if(dfsCheck(it, adj, vis)==true)
                return true;
            }
            //previously visited and path visited there is a cycle
            //8->9->10->8
            else if(vis[it]==1)
            return true;
        }
        //when no cycle found mark path vis as 0
        vis[node]=2;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        //int pathVis[V]={0};
        
        for(int i=0;i<V;i++) 
        {
            if(!vis[i])
            {
                if(dfsCheck(i, adj, vis)==true)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends