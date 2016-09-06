#include <stdio.h>
#include <stdlib.h>

int binsearch(int x ,int v[] ,int n)
{
   int low ,high,mid;
   high=n-1;
   while(low<=high){
      mid=(low+high)/2;
      if (x < v[mid])
          high = mid - 1;
      else if (x > v[mid])
             low = mid - 1;
           else
             return mid;
   }
   return -1;
}
