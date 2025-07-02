#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector <int> randomarray(int n,int v){
    vector <int> arr(n);
    for(int i=0; i<n; i++){
        arr[i]=rand()%v+1;
    }
    return arr;
}

bool right(const vector<int> &arr, int num){
    for(int cur:arr){
        if (num==cur){
            return true;
        }
    }
    return false;
}

bool exist(const vector<int> &arr, int num){
    if(arr.empty()){
        return false;
    }

    int l=0,r=arr.size()-1,m=0;
    while(l<=r){
        m=l+(r-l)/2;
        if (arr[m]==num){
            return true;
        }else if(arr[m]<num){
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return false;
}

int findleft1(const vector<int> &arr,int num){
    int l=0,r=arr.size()-1,m=0;
    int ans=-1;
    while(l<=r){
        m=l+(r-l)/2;
        //在有序表中查找num，有则返回num所在下表，否则返回数组中大于num的最小值下标
        if(arr[m]>=num){
            ans=m;
            r=m-1;
        }
        else{
            l=m+1;
        }

        // //在有序表中查找num，无论有无num都返回大于num的最小值下标
        // if(arr[m]>num){
        //     r=m-1;
        //     ans=m;
        // }else if(arr[m]<num){
        //     l=m+1;
        // }else {
        //     return ans=m+1;
        // }
    }
    return ans;
}

int findleft2(const vector<int> &arr,int num){
    int l=0,r=arr.size()-1,m=0;
    int ans=-1;
    while(l<=r){
        m=l+(r-l)/2;


        //在有序表中查找num，无论有无num都返回大于num的最小值下标
        if(arr[m]>num){
            r=m-1;
            ans=m;
        }else if(arr[m]<num){
            l=m+1;
        }else {
            return ans=m+1;
        }
    }
    return ans;
}

int findright(const vector<int>&arr,int num){
    int l=0,r=arr.size()-1,m=0;
    int ans=-1;
    while(l<=r){
        m=l+(r-l)/2;
        if(arr[m]<=num){
            ans=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return ans;
}

int findpeak(const vector<int>&arr){
    int n=arr.size()-1;
    if(arr.size()==0){
        return -1;
    }
    if (arr[0]>arr[1]){
        return 0;
    }
    if (arr[n-1]<arr[n]){
        return n;
    }

    int l=1,r=n-1,m=0,ans=-1;
    while(l<=r){
        m=(l+r)/2;
        if(arr[m]<arr[m-1]){
            r=m-1;
        }else if(arr[m]<arr[m+1]){
            l=m+1;
        }else{
            ans=m;
            break;
        }
    }
    return ans;
}

int main(){
    int N=10;
    int V=1000;
    int testTimes=500;
    srand(time(0));
    cout<<"测试开始！"<<endl;

    for(int i=0; i< testTimes;i++){
        int n=rand()%N;
        vector <int> arr=randomarray(n,V);
        sort(arr.begin(),arr.end());

        int num=rand()%V +1;
        if (findleft1(arr,num)!=findleft2(arr,num)){
            cout<<"出差了！"<<endl;
            cout<<"数组：";
            for(int x:arr){
                cout<< x <<" ";
            }
            cout << endl;
            cout<< "num="<< num<<endl;

            cout<< findleft1(arr,num)<< "   "<<findleft2(arr,num)<<endl;
            return 1;
        }
        

    }
    cout<< "测试结束！"<<endl;
    return 0;
}