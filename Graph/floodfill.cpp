class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        vector<vector<bool>> visited(image.size(),vector<bool> (image[0].size(),false));
        
        while(!q.empty())
        {
            auto itr=q.front();
            q.pop();
            int x=itr.first;
            int y=itr.second;
            visited[itr.first][itr.second]=true;
            int val=image[x][y];    
            image[x][y]=newColor;
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
            
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0|| ny<0 ||nx>=image.size() || ny>=image[0].size() || visited[nx][ny] || image[nx][ny]!=val)
                    continue;
                q.push({nx,ny});
            }
        }
        
        return image;
        
    }
};