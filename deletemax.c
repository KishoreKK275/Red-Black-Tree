/*=============================================================================
 * FILE        : deletemax.c
 * DESCRIPTION : Deletes the maximum node from the Red-Black Tree.
 *               Prints the tree before and after deletion.
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * deleteMaxNode – finds the rightmost (maximum) node, prints the tree
 *                 before and after removing it via rbDelete().
 *-------------------------------------------------------------------------*/
void deleteMaxNode(void)
{
    Node *maxNode;
    if (root == NIL) {
        printf(RED_TEXT"Tree is empty. Nothing to delete.\n" RESET);
        return;
    }
    maxNode = rbMaximum(root);
    printf(CYAN "Tree Before deleting the maximum node:\n" RESET);
    displayTree();
    rbDelete(maxNode);
    printf(GREEN "Tree After deleting the maximum node:\n" RESET);
    displayTree();
}