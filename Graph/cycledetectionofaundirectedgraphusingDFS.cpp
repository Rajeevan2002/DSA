bool visited[V]={false};
       
       for(int i=0;i<V;i++)
       {
           if(visited[i])
            continue;
       queue<pair<int,int>> q;
       q.push(make_pair(i,-1));
       visited[i]=true;
       
       while(!q.empty())
       {
           pair<int,int> x=q.front(); q.pop();
           
           for(int v:adj[x.first])
           {
               if(!visited[v]){
                q.push(make_pair(v,x.first));
                visited[v]=true;
               }
                
               else if(v!=x.second)
                return true;
           }
       }
       
   }return false;
   }