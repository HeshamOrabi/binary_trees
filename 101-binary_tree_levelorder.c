#include "binary_trees.h"

queue *create_queue()
{
	queue *q = malloc(sizeof(queue));

	if (!q)
		return (NULL);

	q->front = q->rear = NULL;
	return (q);
}

void enqueue(queue *q, binary_tree_t *node)
{
	queue_node *tmp;

	tmp = malloc(sizeof(queue_node));
	if (!tmp)
		return;

	tmp->data = node;
	tmp->next = NULL;

	if (!q->rear)
		q->front = q->rear = tmp;
	else
	{
		(q->rear)->next = tmp;
		q->rear = tmp;
	}
}

binary_tree_t *dequeue(queue *q)
{
	binary_tree_t *tmp;
	queue_node *temp;

	if (!q->front)
		return (NULL);

	tmp = q->front->data;
	temp = q->front;
	q->front = q->front->next;

	if (!q->front)
		q->rear = NULL;


	free(temp);
	return (tmp);
}

/**
 * binary_tree_levelorder - goes through binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue *q;
	binary_tree_t *cur;

	if (!tree || !func)
		return;

	q = create_queue();
	enqueue(q, (binary_tree_t *)tree);

	while (q->front)
	{
		cur = dequeue(q);
		(*func)(cur->n);
		if (cur->left)
			enqueue(q, cur->left);
		if (cur->right)
			enqueue(q, cur->right);
	}
	free(q);
	
}
