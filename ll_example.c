// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice
   int id; // id entered by user
   char name[50];

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%u", &choice );

   // loop while user does not choose 4
   while ( choice != 3) { 

      switch ( choice ) { 
         case 1:
            printf( "%s", "Enter id: " );
            scanf( "%d", &id );
            printf( "%s", "Enter name: " );
            scanf( "%s", name );
            insert( &startPtr, id, name ); // insert item in list
            printList( startPtr );
            break;
         case 2: // delete an element
            // if list is not empty
            if ( !isEmpty( startPtr ) ) { 
               printf( "%s", "Enter id to be deleted: " );
               scanf( "%d", &id );

               // if id is found, remove it
               if ( deletes( &startPtr, id ) ) { // remove item
                  printf( "%d deleted.\n", id );
                  printList( startPtr );
               } // end if
               else {
                  printf( "%d not found.\n\n", id );
               } // end else
            } // end if
            else {
               puts( "List is empty.\n" );
            } // end else

            break;
      } // end switch

      printf( "%s", "? " );
      scanf( "%u", &choice );
   } // end while
  /* Clear all nodes at the end of nodes*/
   if (!isEmpty(startPtr)) {
      freeList(&startPtr);
   }
   puts( "End of run." );
} // end main
