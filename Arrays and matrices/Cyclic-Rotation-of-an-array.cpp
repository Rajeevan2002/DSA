void rotate(int arr[], int n)
{
    int p=1;
    int  d=1;
    while(p<=d)
    {
        int last=arr[n-1];
        for(int i=n-1;i>=1;i--)
            arr[i]=arr[i-1];
        arr[0]=last;
        p++;
    }
}


int p=1;
    d=d%n;
    while(p<=d)
    {
        int last=arr[0];
        for(int i=0;i<n-1;i++)
            arr[i]=arr[i+1];
        arr[n-1]=last;
        p++;
    }