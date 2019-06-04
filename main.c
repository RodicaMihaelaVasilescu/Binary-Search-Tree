///\file main.c
///\brief Binary Search Trees
///
/// Created by Vasilescu Rodica Mihaela
/// Binary Search Trees
#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

int main()
{
    ///\fn int main()
    ///\brief Main function.
    ///\param root The root of the binary search tree
    struct nod *root = NULL;

    ///Random Generator
    time_t t;
    srand((unsigned) time(&t));

    int i, n= rand ()%100,x;
    printf("n = %d",n);
    for( i = 1; i <= n; i++){
        x=rand();
        printf("\nInsert: %d\n",x);
        insert(x, &root);
    }

    for( i = 1; i<= n ; i++)
    {
        x= rand ();
        printf( "\nSearch element %d  : %d\n",x,search ( x,  root ) );
        if( search(x,root)!= -1)
            delete( x, root);
    }

    ///Inserting the nodes 15 11 16 1 0 5 3 50 37 60 25 into the tree
    printf( "\nInserting the nodes 15 11 16 1 0 5 3 50 37 60 25 into the tree ");
    insert ( 15, &root);
    insert ( 11, &root);
    insert ( 16, &root);
    insert ( 1, &root);
    insert ( 0, &root);
    insert ( 5, &root);
    insert ( 3, &root);
    insert ( 50, &root);
    insert ( 37, &root);
    insert ( 60, &root);
    insert ( 1125, &root);

    ///Searching the node 50 into the tree
    printf( "\n\nSearch element 50  : %d\n",search ( 50,  root ) );

    ///Deleting the node 50
    printf( "\nDelete element 50\n");
    delete ( 50 , root);

    ///Searching the nodes 15, 50, 60 and 25 into the tree
    printf( "\nSearch element 50  : %d",search ( 50,  root ) );
    printf( "\nSearch element 15  : %d",search ( 15,  root ) );
    printf( "\nSearch element 60  : %d",search ( 60,  root ) );
    printf( "\nSearch element 25  : %d",search ( 25,  root ) );
    printf("\n");

    ///Printing the nodes in Preorder
    printf( "\n\nPreorder  : " );
    preorder( root );

    ///Printing the nodes in Inorder
    printf( "\n\nInorder   : " );
    inorder ( root);

    ///Printing the nodes in Preorder
    printf( "\n\nPostorder : " );
    postorder(root);
    printf("\n");

    return 0;
}
