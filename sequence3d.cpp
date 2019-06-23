/*

Program Name: Programming Assignment 2

Programmer Name: Emily Zastenchik

Date Submitted: 3/21/2017

Revision

*/

#include <cstdlib>
#include <cassert>
#include<iostream>
#include "sequence3d.h"

using namespace std;
namespace DSProject02
{
sequence::sequence()	//initialize pointers and data
{
	head_ptr = NULL;
	tail_ptr = NULL;
	cursor = NULL;
	many_nodes = 0;
}

sequence::sequence(const sequence& source)
{
	list_copy(source.head_ptr, head_ptr, tail_ptr);	//calls copy from toolkit
	
		
		if(source.cursor)
		{
			cursor = list_search(head_ptr, source.cursor->data());
		}
		else
		{
		cursor = NULL;
		}
		
	many_nodes = source.many_nodes;
}

sequence::~sequence()
{//calls list_clear from toolkit functions
	list_clear(head_ptr);
	many_nodes = 0;	//sets node count to zero

}

void sequence::start()
{
	//cursor points to head_ptr (beginning of sequence)
	cursor = head_ptr;
}
void sequence::advance()
{
	if (is_item())	//cursor != NULL
	cursor = cursor->nlink();//move cursor to next node
}

void sequence::retreat()
{
	if (is_item())	//cursor != NULL
		cursor = cursor->plink(); //move cursor to previous node
}
void sequence::insert(const value_type& entry)
{
	if (many_nodes)	//sequence has at least one node
   {
		if (!is_item()) //cursor is NULL, set to head pointer
      cursor = head_ptr;
	
		if (cursor == head_ptr)//cursor points to head pointer, insert node at head
      {
			list_head_insert(head_ptr, entry);
			cursor = head_ptr;//cursor points to new head_ptr
		}
		else
		{
			list_insert(cursor, entry);	//inserts entry before cursor
			cursor = cursor->plink();  //resets cursor to inserted node
		}
	}
	else //empty list, no nodes
	{
		list_head_insert(head_ptr, entry);	//inserts entry node at head
		cursor = head_ptr;//head and tail point to new node
		tail_ptr = cursor;
	}
	


	++many_nodes; //increase node count

}

void sequence::append(const value_type& entry)
{
	if (is_item()) //cursor!=NULL
	{
		list_append(cursor, entry);   //adds entry after cursor
		if (cursor == tail_ptr)//if cursor points to tail, reset tail pointer
		{
			tail_ptr = tail_ptr->nlink();
		}
		cursor = cursor->nlink();//reset cursor to new node
	}
	else
	{
		if (many_nodes)//at least one node in sequence
		{
			list_append(tail_ptr, entry);//add node to tail
			tail_ptr = tail_ptr->nlink();//reset tail pointer
			cursor = tail_ptr;//reset cursor
		}
		else//no nodes, empty list
		{
			list_head_insert(head_ptr, entry);	//inserts at head in empty list
			tail_ptr = cursor = head_ptr;//set head and tail pointers to new node
		}
	}


	++many_nodes;//update node count

}
void sequence::operator =(const sequence& source)
{

	if (this == &source)  //checks for self assignment
		return;

	else

	{
		list_clear(head_ptr);	//clear list
		list_copy(source.head_ptr, head_ptr, tail_ptr);	//copy source data
		if (source.cursor)//sets cursor
		{
			cursor = list_search(head_ptr, source.cursor->data());
		}
		else
		{
		cursor = NULL;
		}
		
		many_nodes = source.many_nodes;	//copy node count
	}
}

void sequence::remove_current()//remove current item
{
	if (is_item())
	{
		     
		    node* temp = cursor->nlink();//temp pointer will become new cursor
			// [cursor, head_ptr] ---> [tail_ptr]   // size >= 2
		    // [cursor,head_ptr,tail_ptr] ---> NULL  //size of one | at tail_ptr
			if (head_ptr == tail_ptr)// many_nodes == 1
			{
				list_head_remove(head_ptr);
				head_ptr = NULL;
				tail_ptr = NULL;
			}
			// many_nodes > 1
			else if (cursor == head_ptr)	//removes head_ptr
			{
				
				list_head_remove(head_ptr);
			}
			else if (cursor == tail_ptr)	//removes tail_ptr
			{
				tail_ptr = tail_ptr->plink();
				list_remove(cursor);
			}
			else list_remove(cursor);	//else remove cursor
			--many_nodes;
			cursor = temp;
	}

	
}


sequence::value_type sequence::current() const
{
	assert(is_item());
	return  cursor->data();

}

}
