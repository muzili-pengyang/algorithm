#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;

const int MAXN=1000000;
int arr[MAXN];
int help[MAXN];
int n;

void mergeSort1(int l, int r){
    if(l==r){
        return ;
    }

    int m=(l+r)/2;
    mergeSort1(l,m);
    mergeSort1(m+1,r);


    int i=l,a=l,b=m+1;
    while(a<=m && b<=r){
        help[i++]=arr[a]<=arr[b]? arr[a++]:arr[b++];
    }

    while(a<=m){
        help[i++]=arr[a++];
    }

    while(b<=r){
        help[i++]=arr[b++];
    }

    for(int j=l;j<=r;j++){
        arr[j]=help[j];
    }

}


void mergeSort2(){
    for(int step=1;step<n;step<<=1){
        int l=0;
        while(l<n){
            int m=l+step-1;
            if(m+1>=n){
                break;
            }

            int r=min(l+(step<<1)-1,n-1);

            int i=l,a=l,b=m+1;

            while(a<=m&& b<=r){
                help[i++]= arr[a]<=arr[b]? arr[a++]:arr[b++];
            }

            while(a<=m){
                help[i++]=arr[a++];
            }

            while(b<=r){
                help[i++]=arr[b++];
            }
            for(int i=l;i<=r;i++){
                arr[i]=help[i];
            }

            l=r+1;

        }
    }
}

