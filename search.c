/*=============================================================================
 * FILE        : search.c
 * DESCRIPTION : Iterative key search in the Red-Black Tree.
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * rbSearch – iteratively walks left or right depending on key comparison.
 *             Returns the matching node, or NIL if not found.
 *-------------------------------------------------------------------------*/
Node *rbSearch(Node *node, int key)
{
    while (node != NIL && node->data != key) {
        if (key < node->data)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}