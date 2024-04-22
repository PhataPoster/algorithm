#include<stdio.h>
void printarray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
        
    }
    printf("\n");
}
void marg(int arr[],int mid,int low,int high){
    int i,j,k,B[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            B[k]=arr[i];
            i++;
            k++;
        }
        else{
            B[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        B[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high){
        B[k]=arr[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=B[i];
    }
}
void margsort(int arr[],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        margsort(arr,low,mid);
        margsort(arr,mid+1,high);
        marg(arr,mid,low,high);
    }
}



int main(){
    int arr[]={2,3,5,1,2,8};
    int n=sizeof(arr)/sizeof(int);
    printarray(arr,n);
    margsort(arr,0,n-1);
    printarray(arr,n);

}