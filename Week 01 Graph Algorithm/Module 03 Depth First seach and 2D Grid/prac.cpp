class Solution {
  public:
  
  void dfs(int src, vector<bool>& isvisited, vector<int>& result, vector<int> adj[]) {
        
        isvisited[src] = true;
        result.push_back(src);
        
        for (int child : adj[src]) {
            if (!isvisited[child]) {
                dfs(child, isvisited, result, adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> result;
        vector<bool> isvisited(V, false);
        int src = 0;
        
        dfs(src, isvisited, result, adj);
        
        return result;
    }
};