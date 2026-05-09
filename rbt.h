/*=============================================================================
 * FILE        : rbt.h
 * DESCRIPTION : Header for Red-Black Tree – type definitions, constants,
 *               extern globals, and all function prototypes.
 *===========================================================================*/

#ifndef RBT_H
#define RBT_H

#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------------------------------------
 * Color encoding  ( RED->0, BLACK->1)
 *-------------------------------------------------------------------------*/
#define RED   0
#define BLACK 1

#define BLACK_TEXT  "\033[1;37m"
#define RED_TEXT    "\033[1;31m"
#define GREEN       "\033[1;32m"
#define YELLOW      "\033[1;33m"
#define BLUE        "\033[1;34m"
#define MAGENTA     "\033[1;35m"
#define CYAN        "\033[1;36m"
#define WHITE       "\033[1;37m"

#define BOLD        "\033[1m"
#define RESET       "\033[0m"

/*---------------------------------------------------------------------------
 * Node structure
 *-------------------------------------------------------------------------*/
typedef struct Node {
    int          data;
    char         color;   
    struct Node *left, *right, *parent;
} Node;

/*---------------------------------------------------------------------------
 * Global sentinel NIL node and tree root  (defined in rbt_utils.c)
 *-------------------------------------------------------------------------*/
extern Node *NIL;
extern Node *root;

/*---------------------------------------------------------------------------
 * rbt_utils.c  – initialisation, node creation, single-node printer
 *-------------------------------------------------------------------------*/
void  initRBT   (void);
Node *newNode   (int data);
void  printNode (Node *node);

/*---------------------------------------------------------------------------
 * rotate.c  – left / right rotations
 *-------------------------------------------------------------------------*/
void leftRotate  (Node *x);
void rightRotate (Node *x);

/*---------------------------------------------------------------------------
 * insert.c  – BST insert + RB fixup
 *-------------------------------------------------------------------------*/
void rbInsertFixup (Node *z);
void rbInsert      (int data);

/*---------------------------------------------------------------------------
 * display.c  – in-order traversal display
 *-------------------------------------------------------------------------*/
// void inorder     (Node *node);
void printTree(Node *node, int space);
void displayTree (void);

/*---------------------------------------------------------------------------
 * search.c  – iterative key search
 *-------------------------------------------------------------------------*/
Node *rbSearch (Node *node, int key);

/*---------------------------------------------------------------------------
 * findmin.c  – minimum node
 *-------------------------------------------------------------------------*/
Node *rbMinimum (Node *node);

/*---------------------------------------------------------------------------
 * findmax.c  – maximum node
 *-------------------------------------------------------------------------*/
Node *rbMaximum (Node *node);

/*---------------------------------------------------------------------------
 * delete.c  – general deletion (transplant, fixup, delete by key)
 *-------------------------------------------------------------------------*/
void rbTransplant  (Node *u, Node *v);
void rbDeleteFixup (Node *x);
void rbDelete      (Node *z);
void deleteKey     (int key);
/*---------------------------------------------------------------------------
 * deletemin.c  – delete the minimum node
 *-------------------------------------------------------------------------*/
void deleteMinNode (void);
/*---------------------------------------------------------------------------
 * deletemax.c  – delete the maximum node
 *-------------------------------------------------------------------------*/
void deleteMaxNode (void);

#endif /* RBT_H */