#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


class Node{
	public:
		int value;
		int type;
		Node** node_array;;
		
		
		Node (Token v, Token t);
		Node (Token v, Token t, Node* condition, Node* what_to_do);
		~Node ()
}