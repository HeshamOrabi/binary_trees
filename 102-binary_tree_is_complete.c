#include "binary_trees.h"

queue *create_queue()
{
	queue *new;

	new = malloc(sizeof(queue));
	if (!new)
		return (NULL);

	new->front = new->rear = NULL;

	return (new);
}

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
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue *q = create_queue();
	binary_tree_t *cur;
	int flag = 0;

	if (!tree)
		return (0);

	enqueue(q,(binary_tree_t *)tree);

	while (q->front)
	{
		cur = dequeue(q);
		if (!cur)
			flag = 1;
		else
		{
			if (flag)
				return (0);
			enqueue(q, cur->left);
			enqueue(q,cur->right);
		}
	}
	free(q);
	return (1);
}
