/*=============================================================================
 * FILE        : delete.c
 * DESCRIPTION : Red-Black Tree deletion.
 *               Implements CLRS RB-DELETE and RB-DELETE-FIXUP.
 *               rbTransplant    – replaces one subtree with another.
 *               rbDeleteFixup   – restores RB properties after deletion.
 *               rbDelete        – removes a node, printing successor when
 *                                 the node has two children.
 *               deleteKey       – user-facing function (search then delete).
 *===========================================================================*/
#include "rbt.h"
/*---------------------------------------------------------------------------
 * rbTransplant – replaces the subtree rooted at u with the subtree at v.
 *-------------------------------------------------------------------------*/
void rbTransplant(Node *u, Node *v)
{
    if (u->parent == NIL)
        root = v;
    else if (u == u->parent->left)
        u->parent->left  = v;
    else
        u->parent->right = v;
    v->parent = u->parent;   /* always safe; NIL->parent is updated too */
}
/*---------------------------------------------------------------------------
 * rbDeleteFixup – eliminates the "extra black" on node x after a BLACK
 *                 node has been removed.  Four cases (CLRS §13.4):
 *
 *   Case 1 – Sibling w is RED              → rotate, recolour, fall through
 *   Case 2 – Sibling's children both BLACK  → recolour w RED, move x up
 *   Case 3 – Sibling's far child BLACK      → rotate, recolour, → Case 4
 *   Case 4 – Sibling's far child RED        → rotate, recolour, done
 *-------------------------------------------------------------------------*/
void rbDeleteFixup(Node *x)
{
    Node *w;   /* sibling of x */
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            /* ---- x is a LEFT child ------------------------------------ */
            w = x->parent->right;
            /* Case 1: sibling is RED */
            if (w->color == RED) {
                w->color          = BLACK;
                x->parent->color  = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            /* Case 2: sibling's both children are BLACK */
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                /* Case 3: sibling's right child is BLACK */
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color       = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                /* Case 4: sibling's right child is RED */
                w->color          = x->parent->color;
                x->parent->color  = BLACK;
                w->right->color   = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            /* ---- x is a RIGHT child (mirror) -------------------------- */
            w = x->parent->left;
            /* Case 1 (mirror) */
            if (w->color == RED) {
                w->color          = BLACK;
                x->parent->color  = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            /* Case 2 (mirror) */
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                /* Case 3 (mirror) */
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color        = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                /* Case 4 (mirror) */
                w->color          = x->parent->color;
                x->parent->color  = BLACK;
                w->left->color    = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;   /* clear extra black (or root stays black) */
}
/*---------------------------------------------------------------------------
 * rbDelete – removes node z from the tree.
 *
 *   If z has two children, its in-order successor y replaces it.
 *   The successor's data is printed ("successor data: <val>").
 *   If the displaced node y was BLACK, fixup is called on the node x
 *   that moved into y's old position.
 *-------------------------------------------------------------------------*/
void rbDelete(Node *z)
{
    Node *y = z;               /* node to be spliced out        */
    Node *x;                   /* node to move into y's place   */
    int   yOrigColor = y->color;
    if (z->left == NIL) {
        /* --- Case A: no left child ------------------------------------ */
        x = z->right;
        rbTransplant(z, z->right);
    } else if (z->right == NIL) {
        /* --- Case B: no right child ----------------------------------- */
        x = z->left;
        rbTransplant(z, z->left);
    } else {
        /* --- Case C: two children — use in-order successor ----------- */
        y = rbMinimum(z->right);
        printf(BLUE "Successor data: %d\n" RESET, y->data);
        yOrigColor = y->color;
        x          = y->right;
        if (y->parent == z) {
            /* Successor is z's direct right child */
            x->parent = y;
        } else {
            /* Successor is deeper – splice it out first */
            rbTransplant(y, y->right);
            y->right         = z->right;
            y->right->parent = y;
        }
        /* Replace z with y */
        rbTransplant(z, y);
        y->left         = z->left;
        y->left->parent = y;
        y->color        = z->color;   /* inherit z's colour */
    }
    free(z);
    /* Restore RB properties if a BLACK node was removed */
    if (yOrigColor == BLACK)
        rbDeleteFixup(x);
    printf(CYAN "Tree After deleting the node:\n" RESET);
    displayTree();
}
/*---------------------------------------------------------------------------
 * deleteKey – menu-facing function: searches for the key, then deletes.
 *-------------------------------------------------------------------------*/
void deleteKey(int key)
{
    Node *z;
    if (root == NIL) {
        printf(RED_TEXT "Tree is empty. Nothing to delete.\n" RESET);
        return;
    }
    z = rbSearch(root, key);
    if (z == NIL) {
        printf(RED_TEXT"Node (%d) not found in the tree.\n" RESET, key);
        return;
    }
    rbDelete(z);
}