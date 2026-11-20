class Solution {
public:
    set<vector<int>> st;
    void getAllcom(int idx, vector<vector<int>>& ans, vector<int>& curr , int tar, vector<int>& can)
    {
        if(can.size() == idx || tar < 0)
        {
            if(tar == 0)
            {
                sort(curr.begin(),curr.end());

                if(st.find(curr) == st.end())
                {
                    ans.push_back(curr);
                    st.insert(curr);
                }
            }
            return;
        }

        if(tar == 0)
        {
            sort(curr.begin(),curr.end());

            if(st.find(curr) == st.end())
            {
                ans.push_back(curr);
                st.insert(curr);
            }
        }

        curr.push_back(can[idx]);

        getAllcom(idx +1, ans, curr, tar - can[idx], can);

        curr.pop_back();
        
        getAllcom(idx +1, ans, curr, tar, can);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        // sort(candidates.begin(), candidates.end());
        getAllcom(0, ans, curr, target, candidates);

        return ans;
    }
};