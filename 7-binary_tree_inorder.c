#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_stack - function that creates a stack
 * @node: a tree node that is data to be stored in the stack
 *
 * Return: pointer to the top of stack
 */
stack_t *create_stack(const binary_tree_t *node)
{
	stack_t *stack = NULL;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
		return (NULL);

	stack->node = (binary_tree_t *)node;
	stack->prev = NULL;
	stack->next = NULL;

	return (stack);
}

/**
 * push - function that inserts items in a stack
 * @stack: stack to be used
 * @node: node of tree to be pushed to stack
 *
 *Return: Nothing!
 *
 */
void push(stack_t **stack, const binary_tree_t *node)
{
	stack_t *stack_node = create_stack(node);

	if (stack_node == NULL)
		return;

	stack_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = stack_node;

	*stack = stack_node;
}

/**
 * pop - function that inserts items in a stack
 * @stack: stack to be used
 *
 * Return: node of binary tree which is data or stack
 */
binary_tree_t *pop(stack_t **stack)
{
	stack_t *temp;
	binary_tree_t *popped;

	if (*stack == NULL)
		return (NULL);

	temp = *stack;
	popped = temp->node;

	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
	return (popped);
}

/**
 * binary_tree_inorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of tree to traverse
 * @func: pointer function call for each node, value of
 *        node must be passed as param to func
 *
 * Return: Nothing!
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	stack_t *stack = NULL;
	const binary_tree_t *current = tree;

	if (tree == NULL || func == NULL)
		return;

	while (stack != NULL || current != NULL)
	{
		while (current != NULL)
		{
			push(&stack, current);
			current = current->left;
		}
		current  = pop(&stack);

		if (current != NULL)
		{
			func(current->n);

			current = current->right;
		}
	}
}
