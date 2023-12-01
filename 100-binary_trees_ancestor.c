#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor, or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *temp_second;

	while (first)
	{
		temp_second = second;
		while (temp_second)
		{
			if (first == temp_second)
				return ((binary_tree_t *)first);
			temp_second = temp_second->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
