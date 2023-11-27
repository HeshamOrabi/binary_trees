#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: the parent of the Node
 * @value: the value of the Node
 *
 * Return: Newly created Node
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);

	if (!parent->left)
	{
		parent->left = binary_tree_node(parent, value);
	}
	else
	{
		node = parent->left;

		parent->left = binary_tree_node(parent, value);
		parent->left->left = node;
		node->parent = parent->left;
	}
	return (parent->left);
}
