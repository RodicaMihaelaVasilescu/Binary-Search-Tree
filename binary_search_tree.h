///\file binary_search_tree.h
///\brief C library for basic functions.
///
/// Created by Vasilescu Rodica Mihaela
/// Binary Search Trees Project
/// Implements insertion, searching, deletion of a node in a tree
/// Displays in order, preorder, inorder
#include <stdlib.h>
#ifndef DOXY_BINARY_SEARCH_TREE
#define DOXY_BINARY_SEARCH_TREE

struct nod {
    int info;
    struct nod *left, *right;
};

void insert( int new_value, struct nod **root);
int search ( int value, struct nod *root );
void delete( int del , struct nod *root);
void preorder (struct nod *root);
void inorder (struct nod *root);
void postorder (struct nod *root);

#endif//DOXY_BINARY_SEARCH_TREE_H
