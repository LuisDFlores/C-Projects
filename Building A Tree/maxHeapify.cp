#include<iostream>
using namespace std;
void maxHeapify(int *a, int i,int n)
{
    int j , temp;
    temp = a[i];
    j = 2* i;
    while(j <= n)
    {
        if ( j< n && a[j+1]< a[j] )
        j = j + 1;
        
        if (temp > a[j])
        break;
        
        else if (temp <= a[j])
        {
            a[j/2]= a[j];
            j = 2*j;
            
        }
        
    }
    a[j/2]=temp;
    return;
    
}

void create_maxheap(int *a, int n)
{ 
    int i;
    for (i = n / 2; i >= 1; i--)
    {
        maxHeapify(a, i, n);
        
    }
    
}

int main()
{
    int n ,i, x;
    cout<<"Please enter number of elements of the array: \n";
    cin>>n;
    int a[20];
    cout<<"Please enter the elements: \n";
    for(i= 1; i<=n; i++)
    {
        cin>>a[i];
        cout<<endl;
        
    }
    create_maxheap(a,n);
    cout<<"Maximum Heap : \n";
    for(i= 1; i<= n; i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
