#include "linkedList.h"

LinkedList * linkedList()
{
   LinkedList * theList = (LinkedList *)calloc(1, sizeof(LinkedList));
   theList->head = (Node *)calloc(1, sizeof(Node));
   theList->head->data = NULL;
   theList->size = 0;
   return theList;
}

void addLast(LinkedList * theList, Node * nn)
{
   Node * cur = theList->head->next;
   if(theList->size == 0)
   {
      if(nn != NULL)
      {
         Node * temp = theList->head->next;
         free(temp);
         theList->head->next = nn;
         theList->size = theList->size + 1;
      }
   }
   else
   {
      if(nn != NULL)
      {
         while(cur->next != NULL)
         {
            cur = cur->next;
         }
         cur->next = nn;
         theList->size = theList->size + 1;
      }
   }
}

void addFirst(LinkedList * theList, Node * nn)
{
   if(theList->size == 0)
   {
      if(nn != NULL)
      {
         Node * temp = theList->head->next;
         free(temp);
         theList->head->next = nn;
         theList->size = theList->size + 1;
      }
   }
   else
   {
      if(nn != NULL)
      {
         nn->next = theList->head->next;
         theList->head->next = nn;
         theList->size = theList->size + 1;
      }
   }
   
}

void removeFirst(LinkedList * theList, void (*removeData)(void *))
{
   if(theList->size == 0)
      printf("Empty List.\n");
   else
   {
      Node * temp = theList->head->next;
      theList->head->next = theList->head->next->next;
      removeData(temp->data);
      free(temp);
      theList->size = theList->size -1;
   }
}

void removeLast(LinkedList * theList, void (*removeData)(void *))
{
   if(theList->size == 0)
      printf("Empty List.\n");
   else
   {
      Node * cur = theList->head->next;
      Node * prev = theList->head;
      while(cur->next != NULL)
      {
         prev = cur;
         cur = cur->next;
      }
      prev->next = NULL;
      removeData(cur->data);
      free(cur);
      theList->size = theList->size - 1;
   }
}
void removeItem(LinkedList * theList, Node * nn, void (*removeData)(void *), int (*compare)(const void *, const void *))
{

   if(compare(nn->data, theList->head->next->data) == 0)
   {
      Node * temp = theList->head->next;
      theList->head->next = theList->head->next->next;
      removeData(temp->data);
      free(temp);
      removeData(nn->data);
      free(nn);
      theList->size = theList->size -1;
   }
   else
   {
      Node * cur = theList->head->next->next;
      Node * prev = theList->head->next;
      while(cur != NULL && prev != NULL)
      {
         if(compare(nn->data, cur->data) == 0)
         {
            Node * temp = cur;
            prev->next = cur->next;
            removeData(temp->data);
            free(temp);
            removeData(nn->data);
            free(nn);
            cur = NULL;
            theList->size = theList->size -1;
         }
         else
         {
            prev = cur;
            cur = cur->next;
         }
      }
   }
}

void clearList(LinkedList * theList, void (*removeData)(void *))
{
   if(theList->size != 0)
   {
      Node * cur = theList->head->next;
      Node * temp;
      while(cur != NULL)
      {
         temp = cur;
         cur = cur->next;
         removeData(temp->data);
         free(temp);
      }
      free(theList->head);
      theList->head = NULL;
      theList->size = 0;
   }
   else
   {
      free(theList->head);
      theList->head = NULL;
      theList->size = 0;
   }
}

void printList(const LinkedList * theList, void (*convertData)(void *))
{
   if(theList->size == 0)
      printf("Empty List\n");
   
   else
   {
      Node * cur = theList->head->next;
      while(cur != NULL)
      {
         convertData(cur->data);
         if(cur->next == NULL)
            printf("\n");
         cur = cur->next;
      }
   }
}
