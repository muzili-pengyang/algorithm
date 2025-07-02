#include <iostream>
#include <vector>
using namespace std;

void swap(int* arr,int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void printarr(int arr[],int n){
    for (int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
    cout <<endl;
}

void selectsort(int* arr,int n){
    for (int i=0; i<n-1; i++){
        int min=i;
        for (int j=i+1; j<n; j++){
            if (arr[j]<arr[min]){
                min=j;
            }
        }

        swap(arr,i,min);
    }
}

void bubblesort(int arr[],int n){
    for(int i=0; i<n-1 ;i++){
        for (int j=0; j<n-1-i; j++){
            if (arr[j]>arr[j+1]){
                swap(arr,j,j+1);
            }
        }
    }
}

void insertsort(int arr[],int n){
    if (arr==nullptr || n<2){
        return;
    }

    for (int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if (arr[j]>arr[j+1]){
                swap(arr,j,j+1);
            }
        }
    }
}



vector <int> randomarray(int n, int v){
    vector <int> arr(n);
    for (int i=0; i<n; i++){
        arr[i]=rand() % v+1;
    }
    return arr;
}

vector<int> copyarray(const vector<int>  arr){
    return arr;
}

bool samearray(const vector<int> &arr1, const vector<int>& arr2){
    return arr1==arr2;
}


int main(){
    int N=10;
    int V=10;
    int testtimes=5;

    srand(time(0));
    cout<<"Start"<<endl;

    for (int i=0; i<testtimes; i++){
        int n=rand() %N;
        vector <int> arr=randomarray(n,V);
        vector <int> arr1=copyarray(arr);
        vector <int> arr2=copyarray(arr);
        vector <int> arr3=copyarray(arr);

        int* arr_ptr=arr.data();
        int* arr1_ptr=arr1.data();
        int* arr2_ptr=arr2.data();
        int* arr3_ptr=arr3.data();

        selectsort(arr1_ptr,n);
        bubblesort(arr2_ptr,n);
        insertsort(arr3_ptr,n);

        if (!samearray(arr1,arr2)|| !samearray(arr2,arr3)){
            cout<<"出错了！"<<endl;

            cout<<"原始数组:";
            printarr(arr_ptr,n);

            cout<<"选择排序：";
            printarr(arr1_ptr,n);

            cout<<"冒泡排序：";
            printarr(arr2_ptr,n);

            cout<<"插入排序：";
            printarr(arr3_ptr,n);

            return 1;
        }

    }

    cout<<"Ended！"<<endl;
    return 0;

}


