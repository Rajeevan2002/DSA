 vector<int> leaders(int a[], int n){
        // Code here
     int max_till=0;
    vector <int> v;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>=max_till)
        {
            v.push_back(a[i]);
            max_till=a[i];
        }
    }
    reverse(v.begin(),v.end());
    return v;
        
    }