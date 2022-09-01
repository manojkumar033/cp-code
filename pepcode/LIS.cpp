class Solution {
public:
    int max_l=0;
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> list(2500,vector<int>());
         list[0].push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            lis(list,nums[i]);
        }
        // for(auto it:list){
        //     if(it.size()){
        //         for(auto itt:it)
        //             cout<<itt<<" ";
        //     }
        //     cout<<endl;
        // }
        return max_l+1;
    }
    
    void lis(vector<vector<int>> &list,int val){
        int i=max_l;
        // cout<<max_l<<endl;
        while(i>=0 && list[i][list[i].size()-1] >= val){
            // cout<<list[i][list[i].size()-1]<<"->";
            i--;
           
        }
        if(i<0){
            list[0][0]=val;
        }
        else{
            list[i+1] = list[i];
            list[i+1].push_back(val);
            max_l = max(max_l,i+1);
        }
        return ;
    }
};
