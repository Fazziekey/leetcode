// 给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

//  

// 示例 1：

// 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// 输出： True
// 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
// 示例 2:

// 输入: nums = [1,2,3,4], k = 3
// 输出: false
//  

// 提示：

// 1 <= k <= len(nums) <= 16
// 0 < nums[i] < 10000
// 每个元素的频率在 [1,4] 范围内

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/partition-to-k-equal-sum-subsets
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto n:nums)sum+=n;
        cout << sum;
        if(sum%k!=0)return false;
        int target = sum/k;
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int> v(k,0);
        return dfs(nums,v,0,target);
    }
    bool dfs(vector<int>& nums,vector<int>& v,int index,int target){
        if(index==nums.size()){
            for(auto n:v){
                if(n!=target)return false;
            }
            return true;
        }
        for(int i=0;i<v.size();i++){
            cout << i << ":" << v[i] << " ";
        }
        cout << endl;
        for(int i=0;i<v.size();i++){
            if(v[i]+nums[index]>target)continue;
            v[i]+=nums[index];
            if(dfs(nums,v,index+1,target))return true;
            v[i]-=nums[index];
        }
        return false;
    }
};

int main(){
    vector<int> nums = {2,9,4,7,3,2,10,5,3,6,6,2,7,5,2,4};
    int k = 7;
    Solution s;
    cout<<s.canPartitionKSubsets(nums,k)<<endl;
    return 0;
}