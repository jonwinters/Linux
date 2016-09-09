#include <stdio.h>
#include <stdlib.h>

int main ()
{
int a[5]={4,2,7,3,1};
int temp;
for(int i=0;i<5;i++)
	for(int j=i+1;j<5;j++) {
	 if ( a[i] > a[j] ) {
	 temp = a[j];
	 a[j] = a[i];
	 a[i]= temp;
	 }
	}
for (int i=0;i<5;i++)
	printf("%d ",a[i]);

}
