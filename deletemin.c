/*=============================================================================
 * FILE        : deletemin.c
 * DESCRIPTION : Deletes the minimum node from the Red-Black Tree.
 *               Prints the tree before and after deletion.
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * deleteMinNode – finds the leftmost (minimum) node, prints the tree
 *                 before and after removing it via rbDelete().
 *-------------------------------------------------------------------------*/
void deleteMinNode(void)
{
    Node *minNode;
    if (root == NIL) {
        printf(RED_TEXT "Tree is empty. Nothing to delete.\n" RESET);
        return;
    }
    minNode = rbMinimum(root);
    printf( CYAN "Tree Before deleting the minimum node:\n" RESET);
    displayTree();
    rbDelete(minNode);
    printf(GREEN "Tree After deleting the minimum node:\n" RESET);
    displayTree();
}