#include<iostream>
#include<vector>
using namespace std;

const int maxN = 100005;
int arr[maxN];
int suc[maxN];

void megerSort(int low,int high){
	if(low ==  high) {//如果二者相等 		
		return ;
	}
	
	int mid = (low+high)/2;
	megerSort(low,mid); ;//左区间
	megerSort(mid+1,high);//右区间
	
	int i = low,j = mid+1;//两个区间的下限
	int tempI = low; 
	while(i<=mid && j<=high){
		if(arr[i] <= arr[j] ){ //注意不要少了这个等于号 
			suc[tempI++] = arr[i++];	
		}
		if(arr[i] > arr[j]){
			suc[tempI++] = arr[j++];
		}
	}
	while( j<=high ){//赋值多余的部分 
		suc[tempI++] = arr[j++];
	}
	while(i <= mid ){//赋值多余的部分 
		suc[tempI++] = arr[i++];
	}
	
	for(int i = low;i<=high;i++){
		arr[i] = suc[i];//赋值回去 
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> arr;
	for(int i = 0;i<n;i++){
		cin >> arr[i];
	}
	megerSort(0,n-1);
	
	for(int i = 0;i<n;i++)
		cout << arr[i]<<" ";
	cout <<"\n";
}
