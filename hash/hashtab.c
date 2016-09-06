#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define HASHSIZE 101


char *strdup(char *s) {//copy val to ram
     char *p;
     p=(char *)malloc(strlen(s)+1);
     if(p!=NULL)
        strcpy(p,s);//dest,source
     else
        return NULL; //0 replace NULL
     return p;
}

struct nlist {
     struct nlist *next;//next node
     char *key;//key_value
     char *value;//text_value
};

typedef struct nlist node;

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s) {
     unsigned hashval;
     
     for (hashval=0;*s!='\0';s++)
        hashval = *s + 25 * hashval;
     return hashval % HASHSIZE; //hashval % hashsize won't bigger than hashsize
}

node *find(char *s) {
     node *np;
     for(np = hashtab[hash(s)]; np != NULL; np = np->next){
         if(strcmp(s,np->key) == 0)
            return np;
     }
     return NULL;
}

node *put(char *key ,char *value) {
     node *np;
     unsigned hashval;
     if( (np = find(key)) == NULL) { //not find it 
        np=(struct nlist *)malloc(sizeof(*np));        //malloc create sizeof just request size of val not a *
        if ( np == NULL || (np->key = strdup(key)) == NULL)
           return NULL;//np not malloc success! or strcpy key failed!
        hashval = hash(key);
        np->next = hashtab[hashval]; //new node's next node point is old first node point
        hashtab[hashval] = np;
       }else//find it
          free((void *) np->value); //delete pre value val 
       if ( (np->value = strdup(value)) == NULL ) // insert new value val into nlist node
          return NULL;//value not copy to np->value
       return np;
}

char *get(char *key){     
     node *np;
     if((np=find(key))!=NULL)
        return np->value;
     else 
        return NULL;
}


void freeHashtab(){
     node *np,*tempnode;
     for(int i=0;i<HASHSIZE;i++){
       np=hashtab[i];
       if(np==NULL)
          continue;
       while(np!=NULL){
           tempnode=np->next;
          //printf("%s:%s\n",np->key,np->value);
           np->key=NULL;np->value=NULL;
           free(np);
           np=tempnode;
        } 
     }
}
 
int main(int argc ,char **argv) {
   node *np;
   char *value;
   char s[15];
   char a[15];
   for(int i=0;i<100000;i++){
     sprintf(s,"jack%d",i);
     sprintf(a,"%d",i) ;
     if (put(s,a)==0) {
        printf("put failed!\n");
        return 0;
      }
   }
   for(int i=0;i<100000;i++){
   sprintf(s,"jack%d",i);
   if ((value = get(s))!=NULL)
      printf("%s:%s\n",s,value);
   }
   
   if ((np = find("ja"))==NULL)
      printf("not find ja!\n");
   freeHashtab();
      
}        
