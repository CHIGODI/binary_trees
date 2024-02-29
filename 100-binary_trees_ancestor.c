#include "binary_trees.h"
/**
 * find_depth - finds depth of a node
 * @node: node to find depth
 *
 * Return: depth
 *
 */
int find_depth(const binary_tree_t *node)
{
	int depth = 0;

	if (node == NULL)
		return (0);

	while (node)
	{
		depth++;
		node = node->parent;
	}
	return (depth);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor, or NULL if none found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	int depth_first, depth_second;

	if (!first || !second)
		return (NULL);

	depth_first = find_depth(first);
	depth_second = find_depth(second);

	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}
	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);

		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}
