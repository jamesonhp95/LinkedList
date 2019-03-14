#include "movie.h"


void cleanTypeMovie(void * movie)
{
   Movie * temp = (Movie*)(movie);
   free(temp->title);
   int x = 0;
   for(x = 0; x < temp->totalActors; x++)
   {
      free(temp->actors[x].first);
      free(temp->actors[x].last);
   }
   temp->totalActors = 0;
   free(temp->actors);
   free(temp);
   temp = NULL;
}

void * buildTypeMovie(FILE * fin)
{
   char temp[100];
   fgets(temp, 100, fin);
   strip(temp);
   Movie * theMovie = (Movie *)calloc(1, sizeof(Movie));
   theMovie->title = (char *)calloc(strlen(temp)+1, sizeof(char));
   strcpy(theMovie->title, temp);
   
   int numActors;
	fgets(temp, 100, fin);
   strip(temp);
   
	numActors = atoi(temp);
   theMovie->totalActors = numActors;
   theMovie->actors = (Actor *)calloc(numActors, sizeof(Actor));
   int x = 0;
   char first[100];
   char last[100];
   for(x = 0; x < numActors; x++)
   {
      fscanf(fin, "%s %s", first, last);
      fgets(temp, 100, fin);
      theMovie->actors[x].first = (char *)calloc(strlen(first)+1, sizeof(char));
      theMovie->actors[x].last = (char *)calloc(strlen(last)+1, sizeof(char));
      strcpy(theMovie->actors[x].first, first);
      strcpy(theMovie->actors[x].last, last);
   }
   return theMovie; 
}

void printTypeMovie(void * passedIn)
{
   Movie * temp = (Movie*)(passedIn);
   printf("%s\n -Actors- \n", (char*)temp->title);
   int x = 0;
   for(x = 0; x < temp->totalActors; x++)
   {
      printf("- %s %s \n", (char *)temp->actors[x].first, (char *)temp->actors[x].last);
   }
}

void * buildTypeMovie_Prompt(FILE * fin)
{
   char temp[100];
   printf("Enter a Movie title: \n");
   fgets(temp, 100, fin);
   strip(temp);
   Movie * theMovie = (Movie *)calloc(1, sizeof(Movie));
   theMovie->title = (char *)calloc(strlen(temp)+1, sizeof(char));
   strcpy(theMovie->title, temp);
   printf("Enter how many actors are in the movie: \n");
   fgets(temp, 100, fin);
   strip(temp);
   int numActors = atoi(temp);
   theMovie->totalActors = numActors;
   theMovie->actors = (Actor *)calloc(numActors, sizeof(Actor));
   int x = 0;
   char first[100];
   char last[100];
   for(x = 0; x < numActors; x++)
   {
      printf("Enter the first and last name of an actor: \n");
      fscanf(fin, "%s %s", first, last);
      fgets(temp, 100, fin);
      theMovie->actors[x].first = (char *)calloc(strlen(first)+1, sizeof(char));
      theMovie->actors[x].last = (char *)calloc(strlen(last)+1, sizeof(char));
      strcpy(theMovie->actors[x].first, first);
      strcpy(theMovie->actors[x].last, last);
   }
   return theMovie;
}

int compareMovie(const void * p1, const void * p2)
{
   Movie * left = (Movie*)(p1);
   Movie * right = (Movie*)(p2);
   return (int)(strcmp(left->title, right->title));
}
