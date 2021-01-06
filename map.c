#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

struct map{
		char* word;
		struct map* next;
};
		
typedef struct map MapG;

/*create the first element of the list. returns a pointer to the head*/
MapG* CreateList(char* word)
{
	MapG* head = (MapG*)malloc(sizeof(MapG));
	if (head == NULL) exit(1);
	head->word = word;
	head->next = NULL;
	return head;
}

/*insert an element to the end of the list*/
void Push(MapG* head, char* word)
{
	MapG* current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	/*current now points to last node*/
	/*create new node*/
	MapG* new_word = (MapG*)malloc(sizeof(MapG));
	if (new_word == NULL) exit(1);//Fail in case of an error
	new_word->word = word;
	new_word->next = NULL;
	current->next = new_word;
}

/*search the word in the list and then remove it if we found it*/
int SearchWordAndRemove(MapG* head, char* word)
{
	MapG* current = head;
	while ((strcmp(current->word, word)!=0) && (current->next != NULL))
	{
		current = current->next;
	}
	if (strcmp(current->word ,word)==0)/*"deleting" a word we found*/
	{
		current->word="1";
		return TRUE;
	}
	return FALSE;
}

/*free the memory of all elements in the list*/
void DeletingList(MapG* head)
{
	MapG* current = head;
	MapG* before = current;
	while (current->next != NULL)
	{
		before = current;
		current = current->next;
		free(before);/*free memory at the end*/
	}
}

/*check if A is in B*/
int AcontainedB(MapG* headA, MapG* headB){
	MapG* mapA = headA;
	MapG* mapB = headB;
	int flag = TRUE;
	while ((mapA->next !=NULL) && (flag==TRUE))
	{
		flag = SearchWordAndRemove(mapB, mapA->word);
		mapA = mapA->next;
	}
	if (flag==TRUE)
	{
		flag = SearchWordAndRemove(mapB, mapA->word);
	}
	return flag;
}

		
