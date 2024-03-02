//Link->https://leetcode.com/problems/flood-fill/description/
class Solution {
public:
vector<pair<int,int>>v = {{0,-1},{0,1},{-1,0},{1,0}};
int n,m;
bool vis[105][105];
bool valid(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<m; 
}
void bfs(vector<vector<int>>& image,int sr,int sc,int color)
{
    queue<pair<int,int>>q;
    q.push({sr,sc});
    vis[sr][sc]=true;
    int startcolor = image[sr][sc];
    while(!q.empty())
    {
        pair<int,int>par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        image[a][b] = color; 
        for(int i=0;i<4;i++)
        {
            int ci = a + v[i].first;
            int cj = b + v[i].second;
            if(valid(ci,cj)&& !vis[ci][cj] && image[ci][cj]==startcolor)
            {
                q.push({ci,cj});
                vis[ci][cj]=true;
            }
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
             n = image.size();
             m = image[0].size();
             memset(vis,false,sizeof(vis));
             bfs(image,sr,sc,color);
             return image;

    }
};