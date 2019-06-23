// FILE: node1.h
// PROVIDES: A class for a node in a linked list, and list manipulation
// functions, all within the namespace main_savitch_5
//
// TYPEDEF for the node class:
//     Each node of the list contains a piece of data and a pointer to the
//     next node. The type of the data is defined as node::value_type in a
//     typedef statement. The value_type may be any
//     of the built-in C++ classes (int, char, ...) or a class with a copy
//     constructor, an assignment operator, and a test for equality (x == y).
//
// CONSTRUCTOR for the node class:
//   node(
//     const value_type& init_data = value_type(),
//     node* init_link = NULL
//   )
//     Postcondition: The node contains the specified data and link.
//     NOTE: The default value for the init_data is obtained from the default
//     constructor of the value_type. In the ANSI/ISO standard, this notation
//     is also allowed for the built-in types, providing a default value of
//     zero. The init_link has a default value of NULL.
//
// NOTE:
//   Some of the functions have a return value which is a pointer to a node.
//   Each of these  functions comes in two versions: a non-const version (where
//   the return value is node*) and a const version (where the return value
//   is const node*).
// EXAMPLES:
//    const node *c;
//    c->nlink( ) activates the const version of next link
//    c->plink( ) activates the const version of previous link
//    list_search(c,... calls the const version of list_search
//    node *p;
//    p->plink( ) activates the non-const version of previous link
//    p->nlink( ) activates the non-const version of next link
//    list_search(p,... calls the non-const version of list_search
//
// MEMBER FUNCTIONS for the node class:
//   void set_data(const value_type& new_data)
//     Postcondition: The node now contains the specified new data.
//
//   void set_plink(node* new_link)
//     Postcondition: The node now contains the specified new previous link.
//
//   void set_nlink(node* new_link)
//     Postcondition: The node now contains the specified new next link.
//
//   value_type data( ) const
//     Postcondition: The return value is the data from this node.
//
//   const node* plink( ) const <----- const version
//   node* plink( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the prevoius link from this node.
//
//   const node* nlink( ) const <----- const version
//   node* nlink( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is the next link from this node.
//
// FUNCTIONS in the double linked list toolkit:
//   size_t list_length(const node* head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The value returned is the number of nodes in the linked
//     list.
//
//   void list_head_insert(node*& head_ptr, const node::value_type& entry)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at
//     the head of the linked list; head_ptr now points to the head of the new,
//     longer linked list.
//
//   void list_insert(node* cursor_ptr, const node::value_type& entry)
//     Precondition: cursor_ptr points to a node in a linked list.
//     Postcondition: A new node containing the given entry has been added BEFORE cursor_ptr.
//
//   void list_append(node* cursor_ptr, const node::value_type& entry)
//     Precondition: cursor_ptr points to a node in a linked list.
//     Postcondition: A new node containing the given entry has been added AFTER cursor_ptr.
//
//   const node* list_search(const node* head_ptr, const node::value_type& target)
//   node* list_search(node* head_ptr, const node::value_type& target)
//   See the note (above) about the const version and non-const versions:
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The pointer returned points to the first node containing
//     the specified target in its data member. If there is no such node, the
//     null pointer is returned.
//
//   const node* list_locate(const node* head_ptr, size_t position)
//   node* list_locate(node* head_ptr, size_t position)
//   See the note (above) about the const version and non-const versions:
//     Precondition: head_ptr is the head pointer of a linked list, and
//     position > 0.
//     Postcondition: The pointer returned points to the node at the specified
//     position in the list. (The head node is position 1, the next node is
//     position 2, and so on). If there is no such position, then the null
//     pointer is returned.
//
//   void list_head_remove(node*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one node.
//     Postcondition: The head node has been removed and returned to the heap;
//     head_ptr is now the head pointer of the new, shorter linked list.
//
//   void list_remove(node*node_ptr)
//     Precondition: node_ptr points to a node in a linked list, and this
//     is not the tail node of the list.
//     Postcondition: The node after previous_ptr has been removed from the
//     linked list.
//
//   void list_clear(node*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All nodes of the list have been returned to the heap,
//     and the head_ptr is now NULL.
//
//   void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr and tail_ptr are the head and tail pointers for
//     a new list that contains the same items as the list pointed to by
//     source_ptr. The original list is unaltered.
//
//   void list_copy(const node* source_ptr, node*& head_ptr)
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr is the head pointer for
//     a new list that contains the same items as the list pointed to by
//     source_ptr. The original list is unaltered.
//
//  void list_piece(const node* start_ptr, const node* end_ptr, node*& head_ptr, node*& tail_ptr )
//    Precondition: start_ptr and end_ptr are pointers to nodes on the same
//    linked list, with the start_ptr node at or before the end_ptr node
//    Postcondition: head_ptr is the head for a new list that contains the items from start_ptr up to but not including
//    end_ptr.  The end_ptr may also be NULL, in which case the new list contains elements from start_ptr to the end of the list.
//
//  void list_piece(const node* start_ptr, const node* end_ptr, node*& head_ptr )
//    Precondition: start_ptr and end_ptr are pointers to nodes on the same
//    linked list, with the start_ptr node at or before the end_ptr node
//    Postcondition: head_ptr and tail_ptr are the head and tail pointers for for a new list that contains the items from start_ptr
//	  up to but not including end_ptr.
//    The end_ptr may also be NULL, in which case the new list contains elements from start_ptr to the end of the list.
//
// DYNAMIC MEMORY usage by the toolkit:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: the constructor, list_head_insert, list_insert, list_copy,
//   list_piece.

#ifndef NODE1D_H
#define NODE1D_H
#include <cstdlib> // Provides size_t and NULL

namespace DSProject02
{
    class node
    {
    public:
		// TYPEDEF
		typedef double value_type;

		// CONSTRUCTOR
		node(
			const value_type& init_data = value_type( ),
			node* init_next = NULL,node* init_prev = NULL
		)
		{ link_next = init_next; link_prev = init_prev; data_field = init_data; }

		// Member functions to set the data and link fields:
    	void set_data(const value_type& new_data) { data_field = new_data; }
    	void set_plink(node* new_link)             { link_prev = new_link; }
    	void set_nlink(node* new_link)             { link_next = new_link; }

		// Constant member function to retrieve the current data:
		value_type data( ) const { return data_field; }

		// Two slightly different member functions to retrieve
		// the current link:
		const node* plink( ) const { return link_prev; }
		node* plink( ) { return link_prev; }
		const node* nlink( ) const { return link_next; }
		node* nlink( ) { return link_next; }

    private:
		value_type data_field;
		node* link_next;
		node* link_prev;
    };

    // FUNCTIONS for the linked list toolkit
    std::size_t list_length(const node*);
    void list_head_insert(node*&, const node::value_type&);
    void list_insert(node*, const node::value_type&);
    void list_append(node*, const node::value_type&);
    node* list_search(node*, const node::value_type&);
    const node* list_search(const node*, const node::value_type&);
    node* list_locate(node*, std::size_t);
    const node* list_locate(const node*, std::size_t);
    void list_head_remove(node*& head_ptr);
    void list_remove(node*);
    void list_clear(node*&);
    void list_copy(const node*, node*&);
    void list_copy(const node*, node*&, node*&);
    void list_piece(const node*, const node*, node*&);
    void list_piece(const node*, const node*, node*&, node*&);
}

#endif
