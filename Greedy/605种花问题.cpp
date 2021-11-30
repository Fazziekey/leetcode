class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = -1,j = 0,count = 0;
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(), 0);
        int size = flowerbed.size();  
        while(j < size){
            while(j < size && flowerbed[j] != 1){
                j++;
            }
            count = count + max((j - i)/2 - 1, 0);
            i = j;
            j++;
        }
        if(count >= n)
            return true;
        else
            return false;
    }
};

