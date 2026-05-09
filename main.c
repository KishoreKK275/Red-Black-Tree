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
    printf(CYAN BOLD
           "\n=========================================\n"
           "        RED BLACK TREE MENU\n"
           "=========================================\n"RESET);
    printf(GREEN   " 1. Create a tree\n"             RESET);
    printf(YELLOW  " 2. Display\n"                   RESET);
    printf(BLUE    " 3. Search a node\n"             RESET);
    printf(MAGENTA " 4. Find Maximum node in Tree\n" RESET);
    printf(CYAN    " 5. Find Minimum node in Tree\n" RESET);
    printf(RED_TEXT" 6. Deletion\n"                  RESET);
    printf(YELLOW  " 7. Delete Minimum node\n"       RESET);
    printf(MAGENTA " 8. Delete Maximum Node\n"       RESET);
    printf(WHITE   " 9. Exit\n"                      RESET);
    printf(CYAN"-----------------------------------------\n"RESET);
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
        printf(BOLD CYAN "Enter the choice: " RESET);
        if (scanf("%d", &choice) != 1) {
            /* Flush bad input */
            printf(RED_TEXT "Invalid choice. Please enter 1-9.\n" RESET);
            while (getchar() != '\n');
            continue;
        }
        switch (choice) {
        /* ---- Option 1: Create / build the tree ----------------------- */
        case 1:
            do {
                printf(GREEN "Enter the element: " RESET);
                if (scanf("%d", &element) != 1) {
                    printf(RED_TEXT "Invalid input! Please enter an integer.\n" RESET);
                    while (getchar() != '\n');
                    continue;
                }
                rbInsert(element);
                printf(CYAN "Do u want to continue (y/n): " RESET);
                if (scanf(" %c", &cont) != 1 || (cont != 'y' && cont != 'Y' && cont != 'n' && cont != 'N')) {
                        printf(RED_TEXT "Invalid choice! Assuming NO.\n" RESET);
                        while (getchar() != '\n');
                        cont = 'n';
                    }
            } while (cont == 'y' || cont == 'Y');
            break;
        /* ---- Option 2: Display (in-order) ----------------------------- */
        case 2:
            displayTree();
            break;
        /* ---- Option 3: Search ----------------------------------------- */
        case 3:
        printf(BLUE"Enter the element which u want to search from the red black tree: "RESET);
            if (scanf("%d", &element) != 1) {
                printf(RED_TEXT "Invalid input! Please enter an integer.\n" RESET);
                while (getchar() != '\n');
                break;
            }
            result = rbSearch(root, element);
            if (result == NIL)
                printf(RED_TEXT "Node (%d) not found in the tree.\n" RESET, element);
            else {
                printf(GREEN "Node is found -> " RESET);
                printNode(result);
            }
            break;
        /* ---- Option 4: Find Maximum ------------------------------------ */
        case 4:
            if (root == NIL) {
                printf(RED_TEXT "Tree is empty.\n" RESET);
            } else {
                result = rbMaximum(root);
                printf(MAGENTA "Maximum node in the given Red Black Tree is " RESET);
                printNode(result);
            }
            break;
        /* ---- Option 5: Find Minimum ------------------------------------ */
        case 5:
            if (root == NIL) {
                printf(RED_TEXT "Tree is empty.\n" RESET);
            } else {
                result = rbMinimum(root);
                printf(CYAN "Minimum node in the given Red Black Tree is " RESET);
                printNode(result);
            }
            break;
        /* ---- Option 6: General deletion by key ------------------------ */
        case 6:
            printf(RED_TEXT "Enter the node which u want to delete: " RESET);
            if (scanf("%d", &element) != 1) {
                printf(RED_TEXT "Invalid input! Please enter an integer.\n" RESET);
                while (getchar() != '\n');
                break;
            }
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
            printf(GREEN BOLD "\nExiting Red Black Tree Program...\n" RESET);
            exit(EXIT_SUCCESS);
        default:
            printf(RED_TEXT "Invalid choice. Please enter 1-9.\n" RESET);
            break;
        }
    }
    return 0;
}