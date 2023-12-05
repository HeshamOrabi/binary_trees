#include "binary_trees.h"

/**
 * 
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	tmp = tree->left;
	tree->left->parent = tree->parent;
	tree->parent = tree->left;
	tree->left = tree->left->right;
	tmp->right = tree;
	return (tree->parent);
}
