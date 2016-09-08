#include <stdio.h>
#include <stdlib.h>



void functl(char *str,void (*fun)(char *str)) {
      fun(str);
}

void fun1(char *str){
     printf("my id is fun1, %s\n",str);
}
void fun2(char *str){
     printf("my id is fun2, %s\n",str);
}

int main(int agrc ,char **agrv)
{
for(int i=0;i<agrc;i++){
    if (i%2 == 1)
       functl(agrv[i],fun2);
    else
       functl(agrv[i],fun1);
}
}


