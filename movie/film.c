#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>


void showmovies(Item item) {
	printf("Movie:%s Rating:%d \n",item.title,item.rating);
}

char * s_gets(char * st,int n) {
	char *ret_val;
	char *find;
	ret_val = fgets(st,n,stdin);

	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}





int main(int agrc,char **agrv)
{
	List movies;
	Item temp;
	InitializeList(&movies);
	if (ListIsFull(&movies)){
	    fprintf(stderr,"not many available memory!");
		exit(1);
	}
	
	puts("Enter first movies title:");
	
	while (s_gets(temp.title,TSIZE) != NULL && temp.title[0] !='\0') {
		puts("Enter your rating <0-10>:");
		scanf("%d",&temp.rating);
		while (getchar() != '\n')
			continue;
		if (AddItem(temp,&movies) == false) {
			fprintf(stderr,"Problem allocating ram\n");
			break;
		}
		if (ListIsFull(&movies)) {
			puts("memory is now full");
			break;
		}
		puts("Enter next movie title (empty line to stop)");
	}

	if (ListIsEmpty(&movies)) 
		printf("No data entered!\n");
	else {
		printf("Here is the movie list:\n");
		Traverse(&movies,showmovies);
	}
	printf("You enterd %d movies.\n",ListItemCount(&movies));

	EmptyTheList(&movies);
	printf("bye!\n");
	return 0;
}
		   
