vector <int> commonElements (int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
        {
            //code here.
            int i=0,j=0,k=0;
            vector<int> ans;
            while (i < n1 && j < n2 && k < n3) 
            {
                // If x = y and y = z, print any of them and move
                // ahead in all arrays
                if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
                    if(ans.size()!=0 && ar1[i]!=ans[ans.size()-1])
                        ans.push_back(ar1[i]);
                    else if(ans.size()==0)
                        ans.push_back(ar1[i]);
                    i++;
                    j++;
                    k++;
                }
         
                // x < y
                else if (ar1[i] < ar2[j])
                    i++;
         
                // y < z
                else if (ar2[j] < ar3[k])
                    j++;
         
                // We reach here when x > y and z < y, i.e., z is
                // smallest
                else
                    k++;
            }
            return ans;
        }
