#include<stdio.h>

void Insertion_Sort(int a[],int n){
    int i,j,temp;
    for(int i=1;i<n;i++){
        temp = a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int n;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the Input: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("The Sorted array is: ");
    Insertion_Sort(a,n);
    return 0;
}