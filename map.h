#ifndef _MAP_H_
#define _MAP_H_
#define FALSE 0
#define TRUE 1


/*declaring struct*/
typedef struct map{
	char* word;
	struct map* next;
}*MapG;

/*user functions to access the map*/
/*create the first element of the list. returns a pointer to the head*/
MapG* CreateList(char* word);

/*insert an element to the end of the list*/
void Push(MapG* head, char* word);

/*search the word in the list and then remove it if we found it*/
int SearchWordAndRemove(MapG* head, char* word);

/*free the memory of all elements in the list*/
void DeletingList(MapG* head);

/*check if A is in B*/
int AcontainedB(MapG* headA, MapG* headB);

#endif
