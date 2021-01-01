
#include <stdio.h> 
  

int min(int x, int y)
{
if(x<=y)
    return x;
else 
    return y; 
} 
  

int findit(int arr[], int x, int n) 
{ 
    int no_of_comp=0;
    int no2 = 0;  
    int no1 = 1;  
    int no = no2 + no1; 
    while (no < n) 
    { 
      no2 = no1; 
      no1 = no; 
      no = no2 + no1; 
    } 

    int flag= -1; 
  
 
    while (no> 1) 
    { 
        int i = min(flag+no2, n-1); 
        ++no_of_comp;
        if (arr[i] < x) 
        { 
           no  =no1; 
           no1 = no2; 
           no2 = no- no1; 
           flag = i; 
        } 
  
       
        else if (arr[i] > x) 
        { 
           no  = no2; 
            no1 = no1 - no2; 
           no2 =no- no1; 
        } 
  
      
        else 
        {   printf("Element found in array\n");
            printf("Element found after %d comparisons\n",no_of_comp);
            return 0;
        }    
    } 
  
     if(no1 && arr[flag+1]==x)
      return flag+1; 
 
    return -1; 
} 
  
int main(void) 
{ 
int n,i,arr[20],x,j,temp;
printf("Enter number of elements: ");
scanf("%d",&n);
printf("Enter the elements:\n");
for(i=1;i<=n;i++)
{
scanf("%d",&arr[i]);
}
for (i = 0; i < n; ++i) 
        {
 
            for (j = i + 1; j < n; ++j)
            {
 
                if (arr[i] > arr[j]) 
                {
 
                    temp=  arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
 
                }
 
            }
 
        }
 
        
       
printf("Enter the number to be searched: ");
scanf("%d",&x);
findit(arr, x, n); 
return 0; 
}

