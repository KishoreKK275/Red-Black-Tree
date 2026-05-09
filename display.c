/*=============================================================================
 * FILE        : display.c
 * DESCRIPTION : In-order traversal to display the Red-Black Tree.
 *               Each node is printed using printNode().
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * inorder – recursive in-order traversal; visits Left → Node → Right.
 *            Skips the sentinel NIL node.
 *-------------------------------------------------------------------------*/
void printTree(Node *node, int space)
{
    if (node == NIL)
        return;
    space += 6;
    // Print right subtree first (so tree looks rotated)
    printTree(node->right, space);
    // Print current node
    printf("\n");
    for (int i = 6; i < space; i++)
        printf(" ");
    printf("%s%d(%s)%s\n",node->color == RED ? RED_TEXT : BLACK_TEXT,node->data,node->color == RED ? "R" : "B",RESET);
    // Print left subtree
    printTree(node->left, space);
}
/*---------------------------------------------------------------------------
 * displayTree – public entry-point for the menu option.
 *-------------------------------------------------------------------------*/
void displayTree(void)
{
    if (root == NIL) {
        printf(RED_TEXT "Tree is empty.\n" RESET);
        return;
    }

    printf(GREEN "\nRed-Black Tree Structure:\n" RESET);
    printTree(root, 0);
    printf("\n");
}