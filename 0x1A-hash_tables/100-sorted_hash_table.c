#include "hash_tables.h"


/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 * Return: pointer to the newly created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	if (size == 0)
		return (NULL);
	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	return (ht);
}

/**
 * shash_table_set - adds an element to the sorted hash table
 * @ht: hash table to add or update the key/value to
 * @key: key
 * @value: value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node, *tmp;
	char *value_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);
	index = key_index((unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->snext;
	}
	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
	{
		free(value_copy);
		return (0);
	}
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		free(value_copy);
		return (0);
	}
	node->value = value_copy;
	node->next = ht->array[index];
	ht->array[index] = node;

	insertNode(ht, node, key);
	return (1);
}

/**
 * insertNode - inserts a node into a sorted hash table
 * @ht: hash table to insert node into
 * @node: node to insert
 * @key: key of the node
 * Return: void
 */
void insertNode(shash_table_t *ht, shash_node_t *node, const char *key)
{
	shash_node_t *tmp;

	if (ht->shead == NULL)
	{
		node->sprev = NULL;
		node->snext = NULL;
		ht->shead = node;
		ht->stail = node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		node->sprev = NULL;
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		node->sprev = tmp;
		node->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = node;
		else
			tmp->snext->sprev = node;
		tmp->snext = node;
	}
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: hash table to look into
 * @key: key to look for
 * Return: value associated with the element, or NULL if key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (ht == NULL || key == NULL)
		return (NULL);
	index = key_index((unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table to print
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;

	if (ht == NULL)
		return;
	printf("{");
	tmp = ht->shead;
	while (tmp != NULL)
	{
		printf("'%s': '%s'", tmp->key, tmp->value);
		tmp = tmp->snext;
		if (tmp != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;

	if (ht == NULL)
		return;
	printf("{");
	tmp = ht->stail;
	while (tmp != NULL)
	{
		printf("'%s': '%s'", tmp->key, tmp->value);
		tmp = tmp->sprev;
		if (tmp != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *tmp, *tmp2;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp != NULL)
		{
			tmp2 = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			tmp = tmp2;
		}
	}
	free(ht->array);
	free(ht);
}
