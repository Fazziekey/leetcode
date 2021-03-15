#include<iostream>
#include<vector>
using namespace std;
class Sulotion{
    public:
    vector<int> quickSort(vector<int> &num,int l,int r){
        if (l< r)
        {      
            int i = l, j = r, x = num[l];
            while (i < j)
            {
                while(num[j]>=x && i<=j){
                    j--;
                }
                while(num[i]<x && i<=j){
                    i++;
                }
                if(i<j){
                    int temp;
                    temp = num[i];
                    num[i]=num[j];
                    num[j] = temp;
                }
            }
            num[i] = x;
            quickSort(num, l, i - 1); // 递归调用
            quickSort(num, i + 1, r);
        }
        return num;
    }
};

int main()
{
    vector<int> num = {1,23,4,5,6,3,19};

    Sulotion sulotion;
    sulotion.quickSort(num,0,num.size()-1);
    for(int i=0;i<=num.size()-1;i++){
        cout << num[i] << endl;
    }
	return 0;
}
 

