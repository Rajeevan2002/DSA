int doUnion(int a[], int n, int b[], int m)  {
        //code here
        unordered_set <int> s (a,a+n);
        for(int i=0;i<m;i++)
            s.insert(b[i]);
            
        return s.size();
    }