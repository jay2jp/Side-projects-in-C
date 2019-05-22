#include <stdio.h>
#include <stdlib.h>
//#include <third.h>
struct Node
{
    int data;
    struct Node* next;
};

struct Node *makenode(int number)
{
    struct Node* newnode =
        (struct Node*) malloc(sizeof(struct Node));
    newnode->data  = number;
    newnode->next =  NULL;
 
    return newnode;
}
void insert(struct Node** head, struct Node* current)
{
    struct Node* ptr;
    if (*head == NULL || (*head)->data >= current->data)
    {
        current->next = *head;
        *head = current;
    }
    else
    {
       
      ptr= *head;
        while (ptr->next!=NULL && ptr->next->data < current->data)
        {
            ptr = ptr->next;
        }
        current->next = ptr->next;
        ptr->next = current;
    }
}
void print(struct Node *head)
{

    struct Node *ptr = head;
    while(ptr != NULL)
    {
   
        printf("%d", ptr->data);
      if((ptr->next)!=NULL){
      
        printf("  ");
      }
      
        ptr = ptr->next;
    }
     printf("\n");
         
}
 int duplicate(struct Node *head, int number)
{
    struct Node *ptr = head;
    while(ptr != NULL)
    {
        if((ptr->data)==number){
        return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

void delete(struct Node **head, int target)
{
    struct Node* ptr = *head, *prev;
    if (ptr != NULL && ptr->data == target)
    {
        *head = ptr->next;   
        free(ptr);               
        return;
    }
    while (ptr != NULL && ptr->data != target)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr); 
}


int main ( int argc,char **argv ){

struct Node* first = NULL;
char* filename=argv[1];

FILE *file = fopen ( filename, "r" );
   if ( file != NULL )
   {
      char line [ 100 ]; 
int empty = 0;
      while ( fgets ( line, sizeof line, file ) != NULL )
      {
	if(line[0]=='i'){
	int integer = atoi(&line[2]); 
	if(duplicate(first,integer)!=1){
	struct Node *currentnode = makenode(integer);
    	insert(&first, currentnode);
    	}
	}else if (line[0] == 'd'){
	//issa d
	
	int integer = atoi(&line[2]); 
	if(duplicate(first,integer)!=0){
	 delete(&first, integer);
	}
	}else{
	printf("error\n");//invalid format
	}	
	empty=1;
      }
      fclose ( file );
	if (empty==0){
	printf("error\n");//empty file
	}
   }
   else
   {
	printf("error\n");
   }
   print(first);
   return 0;
}