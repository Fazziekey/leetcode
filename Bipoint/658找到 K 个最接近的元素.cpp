// 给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

// 整数 a 比整数 b 更接近 x 需要满足：

// |a - x| < |b - x| 或者
// |a - x| == |b - x| 且 a < b
//  

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/find-k-closest-elements
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> nums(k);
        int size = arr.size();
        if(x < arr[0]){
            for(int i = 0;i<k;i++){
                nums[i]=arr[i];
            }
            return nums;
        }else if(x > arr[size - 1]){
            for(int i = 0;i<k;i++){
                nums[i]=arr[size-k+i];
            }
            return nums;
        }
        int begin = 0;
        int end = size -1;
        for(int i = 0;i<size-k;i++){
            if(abs(x - arr[begin]) <= abs(arr[end] -x)){
                end--;
            }else{
                begin++;
            }
        }
        for(int i = 0;i<k;i++){
                nums[i]=arr[begin+i];
            }
            return nums;
    }
};