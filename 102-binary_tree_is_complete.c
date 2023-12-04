#include "binary_trees.h"

/**
 * create_queue - Creates a new queue.
 *
 * Return: A pointer to the newly created queue, or NULL on failure.
 */
queue *create_queue()
{
	queue *new;

	new = malloc(sizeof(queue));
	if (!new)
		return (NULL);

	new->front = new->rear = NULL;

	return (new);
}

/**
 * enqueue - Adds a binary tree node to the queue.
 * @q: The queue to add the node to.
 * @node: The binary tree node to be added to the queue.
 */
void enqueue(queue *q, binary_tree_t *node)
{
	queue_node *qn;

	qn = malloc(sizeof(queue_node));
	if (!qn)
		return;

	qn->data = node;
	qn->next = NULL;

	if (!q->rear)
		q->rear = q->front = qn;
	else
	{
		q->rear->next = qn;
		q->rear = qn;
	}
}

/**
 * dequeue - Removes and returns the front node from the queue.
 * @q: The queue to dequeue from.
 *
 * Return: The front binary tree node, or NULL if the queue is empty.
 */
binary_tree_t *dequeue(queue *q)
{
	binary_tree_t *bt;
	queue_node *qn;

	if (!q->front)
		return (NULL);
	qn = q->front;
	bt = qn->data;
	q->front = q->front->next;

	if (!q->front)
		q->rear = NULL;

	free(qn);
	return (bt);
}

/**
 * free_queue - free queue
 * @q: queue to be freed
 */
void free_queue(queue *q)
{
	queue_node *cur;

	while (q->front)
	{
		cur = q->front;
		q->front = q->front->next;
		free(cur);
	}
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to root
 *
 * Return: 0 if Null or not complite, 1 if complite
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue *q;
	binary_tree_t *cur;
	int flag = 0;

	if (!tree)
		return (0);
	q = create_queue();
	enqueue(q, (binary_tree_t *)tree);

	while (q->front)
	{
		cur = dequeue(q);
		if (cur->left)
		{
			if (flag)
			{
				free_queue(q);
				free(q);
				return (0);
			}
			enqueue(q, cur->left);
		}
		else
			flag = 1;
		if (cur->right)
		{
			if (flag)
			{
				free_queue(q);
				free(q);
				return (0);
			}
			enqueue(q, cur->right);
		}
		else
			flag = 1;
	}
	free_queue(q);
	free(q);
	return (1);
}
