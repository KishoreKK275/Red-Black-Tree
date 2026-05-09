/*=============================================================================
 * FILE        : rbt_utils.c
 * DESCRIPTION : Global sentinel NIL node, tree root, helper utilities.
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * Globals
 *-------------------------------------------------------------------------*/
Node *NIL  = NULL;
Node *root = NULL;
/*---------------------------------------------------------------------------
 * initRBT – allocates the sentinel NIL node and sets the root to NIL.
 *   NIL is always BLACK; all its pointer fields are NULL (it is a leaf).
 *-------------------------------------------------------------------------*/
void initRBT(void)
{
    NIL = (Node *)malloc(sizeof(Node));
    if (!NIL) {
        fprintf(stderr, "Fatal: cannot allocate NIL sentinel.\n");
        exit(EXIT_FAILURE);
    }
    NIL->color  = BLACK;
    NIL->data   = 0;
    NIL->left   = NULL;
    NIL->right  = NULL;
    NIL->parent = NULL;
    root = NIL;           /* empty tree */
}

/*---------------------------------------------------------------------------
 * newNode – creates a RED interior node; both children point to NIL.
 *-------------------------------------------------------------------------*/
Node *newNode(int data)
{
    Node *z = (Node *)malloc(sizeof(Node));
    if (!z) {
        fprintf(stderr, "Fatal: cannot allocate new node.\n");
        exit(EXIT_FAILURE);
    }
    z->data   = data;
    z->color  = RED;
    z->left   = NIL;
    z->right  = NIL;
    z->parent = NIL;
    return z;
}
/*---------------------------------------------------------------------------
 * printNode – prints one node in format:
 *               (data)--(RED->0)  or  (data)--(BLACK->1)
 *-------------------------------------------------------------------------*/
void printNode(Node *node)
{
    if (node == NIL || node == NULL)
        return;
    printf("%d(%s)\n", node->data,
       node->color == RED ? "R" : "B");
}