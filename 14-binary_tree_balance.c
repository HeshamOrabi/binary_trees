#include "binary_trees.h"

/**
 * 
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (!tree)
		return (-1);

	left_height = binary_tree_balance(tree->left);
	right_height = binary_tree_balance(tree->right);

	return (left_height - right_height);
}
