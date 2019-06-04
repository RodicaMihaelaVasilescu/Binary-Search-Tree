///\file Binary_Search_Tree.c
///\brief The basic functions of binary search trees.
///
/// Created by Vasilescu Rodica - Mihaela
/// Binary Search Trees
#include "binary_search_tree.h"

void insert( int new_value, struct nod **root) {
    ///\fn void insert( int new_value, struct nod **root)
    ///\brief Insert a node into a tree
    ///\param new_value The value of the node
    ///\param root The root of the binary search tree
    ///
    ///If the Binary Search Tree is empty, the first value will be the root
    if( *root == NULL){
        *root = (struct nod *) malloc( sizeof ( struct nod));
        (*root) -> info = new_value;
        (*root) -> right = NULL;
        (*root) -> left = NULL;
    }
    ///else
    else
    {
        if( new_value < (*root) -> info )
        ///if the key is not equal to that of the root,
           insert ( new_value, &((*root) -> left));///we search the left subtree
        else
        ///else we search the right subtree.
           insert ( new_value, &((*root) -> right));
    }
}

int search ( int value, struct nod *root ){
    ///\fn int search ( int value, struct nod *root )
    ///\brief Searching a value into a tree
    ///\param value The value of the node we are searching for
    ///\param root The root of the binary search tree
    ///
    if( root != NULL ){
        ///if the key equals that of the root, the search is successful and we return the node.
        if(  value == root -> info)
            return root->info;

        ///If the key is less than that of the root, we search the left subtree.
        if( value < root -> info)
                return search (value , root -> left );
        ///Similarly, if the key is greater than that of the root, we search the right subtree.
        if( value > root -> info)
            return search (value , root -> right );
    }
        ///This process is repeated until the key is found or the remaining subtree is null.
        ///If the searched key is not found after a null subtree is reached,
        ///then the key we are searching for does not exist in the tree.
        else return -1;
}

void delete(int del , struct nod *root){
    ///\fn void delete(int del , struct nod *root)
    ///\brief Delete a node from the tree
    ///\param del The value of the node we are going to delete
    ///\param root The root of the binary search tree
    ///\param current The parameter we use in order to find the node we are going to delete
    ///\param parent The parent of the of the current node
    ///
    struct nod *current = root;
    struct nod *parent;
    struct nod *temp;
    int aux;

    ///Searching the value:
    while( del != current -> info ){
        parent = current; ///p va retine nodul parinte al nodului ce urmeaza a fi sters
        if( del < current -> info){
            current = current -> left;
        }
        else current = current-> right;
    }
    ///When removing a node from a binary search tree
    ///it is mandatory to maintain the in-order sequence of the nodes.

    ///Deleting a node with no children: simply remove the node from the tree.
    if ( current -> left == NULL && current -> right == NULL){
        if( current -> info < parent -> info){
            parent -> left = NULL;
        }
        else { parent -> right = NULL; }
    }
    ///Deleting a node with one child: remove the node and replace it with its child.
    else if ( current -> right == NULL ){///If the node does not have child in the right subtree
        if( current -> info < parent -> info){///remove the node and replace it with its left child.
            parent -> left = current -> left;
        }
        else{
            parent -> right = current -> left;
        }
        free(current);
    }
    else if( current -> left == NULL ){///If the node does not have child in the left subtree
        if(current -> info < parent -> info){///remove the node and replace it with its right child.
            parent -> left = current -> right;
        }
        else{
            parent -> right = current -> right;
        }
        free(current);
    }

    ///Deleting a node with two children: call the node to be deleted "Current".
    ///Do not delete "Current".
    ///Instead, choose its in-order successor node as replacement: node Temp.
    ///\param temp The node with the most appropriate value to the value of the node we are going to delete
     else{
            temp = current -> right;
            while( temp -> left != NULL){
                temp = temp -> left;
            }
            aux = temp -> info;
            delete(aux, root);
            current -> info = aux;
        }
}

void preorder (struct nod *root){
    ///\fn void preorder (struct nod *root)
    ///\brief Preorder Traversal - Algorithm:
    ///\param root The root of the binary search tree
    ///
    if( root != NULL){///Check if the current node is empty .
           printf ( "%d ", root -> info );///Display the data part of the root (or current node).

           if ( root -> left != NULL )///Traverse the left subtree
                preorder ( root -> left);/// by recursively calling the preorder function.

           if ( root -> right != NULL )///Traverse the right subtree
                preorder ( root -> right );/// by recursively calling the preorder function.
    }
}

void inorder (struct nod *root){
    ///\fn void inorder (struct nod *root)
    ///\brief Inorder Traversal - Algorithm:
    ///\param root The root of the binary search tree
    ///
    if( root != NULL)///Check if the current node is empty.
    {
           if ( root -> left != NULL )///Traverse the left subtree
                inorder ( root -> left);/// by recursively calling the inorder function.

           printf ( "%d ", root -> info );///Display the data part of the root (or current node).

           if ( root -> right != NULL )///Traverse the right subtree
                inorder ( root -> right );/// by recursively calling the inorder function.
    }
}

void postorder (struct nod *root){
    ///\fn void postorder (struct nod *root)
    ///\brief Postorder Traversal - Algorithm:
    ///\param root The root of the binary search tree
    ///
    if( root != NULL)///Check if the current node is empty.
    {
           if ( root -> left != NULL )///Traverse the left subtree
                postorder ( root -> left);/// by recursively calling the postorder function.

           if ( root -> right != NULL )///Traverse the right subtree
                postorder ( root -> right );/// by recursively calling the postorder function.

           printf ( "%d ", root -> info );///Display the data part of the root (or current node).

    }
}
