#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that performs a left-rotation
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: NULL, or the new root node
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp;

	if (!tree)
		return (NULL);
	tmp = tree->right;
	tree->right->parent = tree->parent;
	tree->parent = tree->right;
	tree->right = tree->right->left;
	tmp->left = tree;
	return (tree->parent);
}
