ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map<ll, vector<ll> > map;
  
    // create an empty vector of pairs to store
    // subarray starting and ending index
    vector <pair<ll,ll>> out;
  
    // Maintains sum of elements so far
    ll sum = 0;
  
    for (ll i = 0; i < n; i++)
    {
        // add current element to sum
        sum += arr[i];
  
        // if sum is 0, we found a subarray starting
        // from index 0 and ending at index i
        if (sum == 0)
            out.push_back(make_pair(0, i));
  
        // If sum already exists in the map there exists
        // at-least one subarray ending at index i with
        // 0 sum
        if (map.find(sum) != map.end())
        {
            // map[sum] stores starting index of all subarrays
            vector<ll> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
            {
                out.push_back(make_pair(*it + 1, i));
            }
            
        }
        // Important - no else
        map[sum].push_back(i);
    }
  
    // return output vector
    return out.size();
    }
};