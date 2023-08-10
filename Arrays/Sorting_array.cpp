/*Take the size of the array from the user.
Declare an array of given input size.
Take the input of all elements of the array.
Now run a for loop from 0 to size-1.
And for every element check it from all the next elements to it. If the element is greater than swap that number.
In this way the array will get sorted in ascending order.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    
    cout<<"Enter the size of array: "; cin>>n;
    
    int a[n];
    
    cout<<"\nEnter the elements: ";
    for(int i=0; i<n; i++) cin>>a[i];
      
      
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++) { if(a[i]>a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    cout<<"\nArray after swapping: ";
   
    for(int i=0; i<n; i++)
      cout<<a[i]<<" ";
      
    return 0;
}