class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        for(int i = 0;i<arr.size()-k;i++){
            arr.pop_back();
        }
        return arr;
    }
};