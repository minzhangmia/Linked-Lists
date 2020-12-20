/**
 * \file linked_list.h
 * \brief Header file containing structures and function prototypes for
 * 	dealing with linked lists. Needed for Assignment 5 for 5613
 * \author R. Morrin
 * \version 2.0
 * \date 2020-11-24
 */
#ifndef LINKED_LIST_H_KYDIEQVO
#define LINKED_LIST_H_KYDIEQVO

/*! \struct _Node 
 *  \brief Brief struct description
 *
 *  Declare a _Node structure which will be used to form a linked list.
 *  Typedef this structure to "Node"
 *
 */
typedef struct _Node {
    struct _Node *next; /*!< pointer to next node in list 	*/
    struct _Node *prev; /*!< pointer to previous node in list 	*/
    int N; 		/*!< dimension of the square matrix 	*/
    double **data; 	/*!< matrix data 			*/
} Node;


/*! \struct _List 
 *  \brief Structure to hold pointers to the first and last Nodes of a linked list
 */
typedef struct _List {
    Node *head; 	/*!< pointer to first node in list 	*/
    Node *tail; 	/*!< pointer to last node in list  	*/
} List;


/* Function prototypes */
int append_new_node(List *const inlist, const int N);
void print_list_contents( List list);
void remove_node(List *in, Node *node);
void read_list_from_file(const char *const filename, List *mylist);

#endif /* end of include guard: LINKED_LIST_H_KYDIEQVO */

