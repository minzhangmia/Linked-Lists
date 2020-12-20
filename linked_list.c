#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "matrix.h"
/**
 * @fn	    int append_new_node(List *const inlist, const int N)
 * @brief	insert a new node in list
 * @author	ZM
 * @date	2020/12/07
 * @returns	inserd a new node; return 0
 */
int append_new_node(List *const inlist, const int N)
{
	Node *node=malloc(sizeof(Node));
	node->N=N;
    if(alloc_cont_mem_sq_mat(&node->data,N)==0)
    {
		//when list is empty, add a new node in the list
    	if(inlist->head==NULL)
    	{
    		node->next=NULL;
		    node->prev=NULL;
		    inlist->head=node;
		    inlist->tail=node;
		}
		//when list is not empty, add a new node at the end of the list
		else
		{
			inlist->tail->next=node;
		    node->prev=inlist->tail;
		    inlist->tail=node;
		    node->next=NULL;
		}
	}
	return 0;
}
/**
 * @fn	    read_list_from_file(const char *const filename, List *mylist)
 * @brief	read list from file (data.txt)
 * @author	ZM
 * @date	2020/12/07
 * @returns	fscanf
 */
void read_list_from_file(const char *const filename, List *mylist)
{
	FILE *fp=fopen(filename,"r"); //pointer for opening file
	if(fp==NULL)
	{
		printf("Error opening %s",filename);//didn't read succesful
		return;
	}
	int x;
	double tp;
	int i,j;
	while(fscanf(fp,"%d", &x) ==1) //scan each data one by one
	{
		append_new_node(mylist, x); 
		for(i=0;i<x;i++)
		for(j=0;j<x;j++)
		{
			fscanf(fp,"%lf",&tp); 
			mylist->tail->data[i][j]=tp; //save the points in the list
		}
	}
	fclose(fp);
}
/**
 * @fn	    void remove_node(List *in, Node *node)
 * @brief	delete node
 * @author	ZM
 * @date	2020/12/07
 * @returns	
 */
void remove_node(List *in, Node *node)
{
	if(node->prev==NULL)
	{
		in->head=node->next;
		if(node->next!=NULL)
		{
			in->head->prev=NULL;
		}
		else
		{
			in->tail=NULL;
		}
	}
	else
	{
		node->prev->next=node->next;
		if(node->next!=NULL)
		{
			node->next->prev=node->prev;
		}
		else
		{
			in->tail=node->prev;
		}
	}
	free(node->data); //free memory of node's struct
	free(node);//free memory of node
}
/**
 * @fn	    void print_list_contents(List list)
 * @brief	print an dim*dim square matrix(B) in screen
 * @author	ZM
 * @date	2020/12/07
 * @returns	print matrix
 */
void print_list_contents(List list)
{
	Node *it=list.head; //define a point '*it' to point head node
    while(it!=NULL) //check the list is empty or not
	{
		Node *nextit = it->next;
		print_sq_matrix(it->data,it->N); //print matrix
		it=nextit;
	}
	return;
}
