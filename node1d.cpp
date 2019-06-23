// FILE: node1.cxx
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t

#include "node1d.h"
using namespace std;

namespace DSProject02
{
size_t list_length(const node* head_ptr)
// Library facilities used: cstdlib
{
	const node *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->nlink( ))
		++answer;

	return answer;
}

void list_head_insert(node*& head_ptr, const node::value_type& entry)
{
	if ( head_ptr == NULL )
		head_ptr = new node(entry, head_ptr, NULL);
	else {
		head_ptr = new node(entry, head_ptr, NULL);
		head_ptr->nlink()->set_plink(head_ptr);
	}
}

void list_insert(node* node_ptr, const node::value_type& entry)
{
	node *insert_ptr;
	assert(node_ptr != NULL);

	insert_ptr = new node(entry, node_ptr,node_ptr->plink());

	if ( node_ptr->plink() != NULL ) {
		//NOT HEAD NODE
		node_ptr->plink()->set_nlink(insert_ptr);
	}
	node_ptr->set_plink(insert_ptr);

}

void list_append(node* node_ptr, const node::value_type& entry)
{
	node *insert_ptr;
	assert(node_ptr != NULL);

	insert_ptr = new node(entry, node_ptr->nlink(),node_ptr);

	if ( node_ptr->nlink() != NULL ) {
		//NOT HEAD NODE
		node_ptr->nlink()->set_plink(insert_ptr);
	}
	node_ptr->set_nlink(insert_ptr);

}

node* list_search(node* head_ptr, const node::value_type& target)
// Library facilities used: cstdlib
{
	node *cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->nlink( ))
		if (target == cursor->data( ))
			return cursor;
	return NULL;
}

const node* list_search(const node* head_ptr, const node::value_type& target)
// Library facilities used: cstdlib
{
	const node *cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->nlink( ))
		if (target == cursor->data( ))
			return cursor;
	return NULL;
}

node* list_locate(node* head_ptr, size_t position)
// Library facilities used: cassert, cstdlib
{
	node *cursor;
	size_t i;

	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
		cursor = cursor->nlink( );
	return cursor;
}

const node* list_locate(const node* head_ptr, size_t position)
// Library facilities used: cassert, cstdlib
{
	const node *cursor;
	size_t i;

	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
		cursor = cursor->nlink( );
	return cursor;
}

void list_head_remove(node*& head_ptr)
{
	node *remove_ptr;

	remove_ptr = head_ptr;

	//If list has more then one item
	if ( head_ptr->nlink() != NULL )
		head_ptr->nlink()->set_plink( NULL );

	head_ptr = head_ptr->nlink( );

	delete remove_ptr;
}

void list_remove(node* cursor_ptr)
{
	assert(cursor_ptr != NULL);

	if ( cursor_ptr->plink() != NULL ) {
		cursor_ptr->plink()->set_nlink( cursor_ptr->nlink() );
	}

	if ( cursor_ptr->nlink() != NULL )
		cursor_ptr->nlink()->set_plink( cursor_ptr->plink() );

	delete cursor_ptr;
}

void list_clear(node*& head_ptr)
// Library facilities used: cstdlib
{
	while (head_ptr != NULL)
		list_head_remove(head_ptr);
}

void list_copy(const node* source_ptr, node*& head_ptr)
// Library facilities used: cstdlib
{
	node* tail_ptr = NULL;

	head_ptr = NULL;

	// Handle the case of the empty list.
	if (source_ptr == NULL)
		return;

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	source_ptr = source_ptr->nlink( );
	while (source_ptr != NULL)
	{
		list_append(tail_ptr, source_ptr->data( ));
		tail_ptr = tail_ptr->nlink( );
		source_ptr = source_ptr->nlink( );
	}
}

void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
// Library facilities used: cstdlib
{
	head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list.
	if (source_ptr == NULL)
		return;

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	source_ptr = source_ptr->nlink( );
	while (source_ptr != NULL)
	{
		list_append(tail_ptr, source_ptr->data( ));
		tail_ptr = tail_ptr->nlink( );
		source_ptr = source_ptr->nlink( );
	}
}

void list_piece(const node* start_ptr, const node* end_ptr,	node*& head_ptr, node*& tail_ptr )
{

	tail_ptr = NULL;
	head_ptr = NULL;

	// Handle the case of the empty list.
	if (start_ptr == end_ptr) {
		return;
	}

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, start_ptr->data( ));
	tail_ptr = head_ptr;

	start_ptr = start_ptr->nlink( );
	while ( start_ptr != end_ptr && start_ptr != NULL ) {
		list_append(tail_ptr, start_ptr->data( ) );
		tail_ptr = tail_ptr->nlink( );
		start_ptr = start_ptr->nlink( );
	}

}

void list_piece(const node* start_ptr, const node* end_ptr,	node*& head_ptr )
{

	node* tail_ptr = NULL;
	head_ptr = NULL;

	// Handle the case of the empty list.
	if (start_ptr == end_ptr) {
		return;
	}

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, start_ptr->data( ));
	tail_ptr = head_ptr;

	start_ptr = start_ptr->nlink( );
	while ( start_ptr != end_ptr && start_ptr != NULL ) {
		list_append(tail_ptr, start_ptr->data( ) );
		tail_ptr = tail_ptr->nlink( );
		start_ptr = start_ptr->nlink( );
	}

}
}
