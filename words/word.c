#include "word.h"


void cleanTypeWord(void * word)
{
   Word * temp = (Word*)(word);
   free(temp->ltrs);
   temp->len = 0;
   free(temp);
   temp = NULL;
}

void * buildTypeWord(FILE * fin)
{
   char temp[100];
   fgets(temp, 100, fin);
   strip(temp);
   Word * theWord = (Word *)calloc(1, sizeof(Word));
   theWord->ltrs = (char *)calloc(strlen(temp)+1, sizeof(char));
   strcpy(theWord->ltrs, temp);
   theWord->len = strlen(theWord->ltrs);
   return theWord; 
}

void printTypeWord(void * passedIn)
{
   Word * temp = (Word*)(passedIn);
   printf("%s-%d, ", (char*)temp->ltrs, (int)temp->len);
}

void * buildTypeWord_Prompt(FILE * fin)
{
   char temp[100];
   printf("Enter a word: \n");
   fgets(temp, 100, fin);
   strip(temp);
   Word * theWord = (Word *)calloc(1, sizeof(Word));
   theWord->ltrs = (char *)calloc(strlen(temp)+1, sizeof(char));
   strcpy(theWord->ltrs, temp);
   theWord->len = strlen(theWord->ltrs);
   return theWord;
}

int compareWord(const void * p1, const void * p2)
{
   Word * left = (Word*)(p1);
   Word * right = (Word*)(p2);
   return (int)(strcmp(left->ltrs, right->ltrs));
}
