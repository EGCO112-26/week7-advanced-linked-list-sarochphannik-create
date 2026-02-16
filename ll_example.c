#include <stdio.h>
#include "ll.h"

int main(void) {
    LLPtr startPtr = NULL; // Initially there are no nodes
    unsigned int choice; // User's choice
    int id; // ID entered by user
    char name[50]; // Name entered by user

    instructions(); // Display the menu
    printf("%s", "? ");
    scanf("%u", &choice);

    // Loop while user does not choose 3
    while (choice != 3) {
        switch (choice) {
            case 1: // Insert
                printf("%s", "Enter id and name: ");
                scanf("%d %s", &id, name);
                insert(&startPtr, id, name);
                printList(startPtr);
                printListR(startPtr);
                break;

            case 2: // Delete
                if (!isEmpty(startPtr)) {
                    printf("%s", "Enter number to be deleted: ");
                    scanf("%d", &id);

                    if (deletes(&startPtr, id)) {
                        printf("%d deleted.\n", id);
                        printList(startPtr);
                        printListR(startPtr);
                    } else {
                        printf("%d not found.\n\n", id);
                    }
                } else {
                    puts("List is empty.\n");
                }
                break;
            
            default:
                puts("Invalid choice.\n");
                break;
        } // end switch

        printf("%s", "? ");
        scanf("%u", &choice);
    } // end while

    // Clear logic at the end
    clearList(&startPtr);
    
    puts("End of run.");
    return 0;
}