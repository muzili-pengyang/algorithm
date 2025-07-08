#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN=201;
const int MAXM=201;

int mat[MAXN][MAXM];
int arr[MAXM];
int n,m;

int maxSumSubarray(){
    int maxsum=INT_MIN;
    int currentsum=0;
    for(int i=0;i<m;i++){
        currentsum+=arr[i];
        maxsum=max(maxsum,currentsum);
        if(currentsum<0){
            currentsum=0;
        }

    }
    return maxsum;
}

int maxSumSubmatrix(){
    int maxsum=INT_MIN;
    for(int i=0; i<n; i++){
        fill(arr,arr+m,0);//将arr数组中的前m个元素设置为0
        for(int j=i; j<n; j++){
            for(int k=0; k<m;k++){
                arr[k]+=mat[j][k];//累加各子矩阵的列到arr
            }
            maxsum=max(maxsum,maxSumSubarray());
        }
    }
    return maxsum;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin>> n>> m){
        for(int i=0;i<n;i++){
            for(int j=0; j<m;j++){
                cin>> mat[i][j];
            }
        }
        cout<< maxSumSubmatrix()<<endl;
    }
    return 0;
}