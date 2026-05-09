/*=============================================================================
 * FILE        : main.c
 * DESCRIPTION : Menu-driven driver for the Red-Black Tree application.
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * printMenu – displays the main option menu.
 *-------------------------------------------------------------------------*/
static void printMenu(void)
{
    printf("\n1. Create a tree\n");
    printf("2. Display\n");
    printf("3. Search a node\n");
    printf("4. Find Maximum node in Tree\n");
    printf("5. Find Minimum node in Tree\n");
    printf("6. Deletion\n");
    printf("7. Delete Minimum node\n");
    printf("8. Delete Maximum Node\n");
    printf("9. Exit\n");
}
/*---------------------------------------------------------------------------
 * main – initialises the RB tree and drives the menu loop.
 *-------------------------------------------------------------------------*/
int main(void)
{
    int   choice;
    int   element;
    char  cont;
    Node *result;
    /* Allocate sentinel NIL and set root = NIL */
    initRBT();
    while (1) {
        printMenu();
        printf("Enter the choice: ");
        if (scanf("%d", &choice) != 1) {
            /* Flush bad input */
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
        /* ---- Option 1: Create / build the tree ----------------------- */
        case 1:
            do {
                printf("Enter the element: ");
                scanf("%d", &element);
                rbInsert(element);
                printf("Do u want to contiune (y/n): ");
                scanf(" %c", &cont);
            } while (cont == 'y' || cont == 'Y');
            break;
        /* ---- Option 2: Display (in-order) ----------------------------- */
        case 2:
            displayTree();
            break;
        /* ---- Option 3: Search ----------------------------------------- */
        case 3:
            printf("Enter the element which u want to search"
                   " from the red black tree: ");
            scanf("%d", &element);
            result = rbSearch(root, element);
            if (result == NIL)
                printf("Node (%d) not found in the tree.\n", element);
            else {
                printf("Node is found ");
                printNode(result);
            }
            break;
        /* ---- Option 4: Find Maximum ------------------------------------ */
        case 4:
            if (root == NIL) {
                printf("Tree is empty.\n");
            } else {
                result = rbMaximum(root);
                printf("Maximum node in the given Red Black Tree is ");
                printNode(result);
            }
            break;
        /* ---- Option 5: Find Minimum ------------------------------------ */
        case 5:
            if (root == NIL) {
                printf("Tree is empty.\n");
            } else {
                result = rbMinimum(root);
                printf("Minimum node in the given Red Black Tree is ");
                printNode(result);
            }
            break;
        /* ---- Option 6: General deletion by key ------------------------ */
        case 6:
            printf("Enter the node which u want to delete: ");
            scanf("%d", &element);
            deleteKey(element);
            break;
        /* ---- Option 7: Delete minimum node ---------------------------- */
        case 7:
            deleteMinNode();
            break;
        /* ---- Option 8: Delete maximum node ---------------------------- */
        case 8:
            deleteMaxNode();
            break;
        /* ---- Option 9: Exit ------------------------------------------- */
        case 9:
            printf("Exiting...\n");
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice. Please enter 1-9.\n");
            break;
        }
    }
    return 0;
}