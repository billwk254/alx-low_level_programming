#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the newly created sorted hash table,
 *         or NULL if something went wrong.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *sht = malloc(sizeof(shash_table_t));
    if (sht == NULL)
        return NULL;

    sht->size = size;
    sht->array = calloc(size, sizeof(shash_node_t *));
    if (sht->array == NULL)
    {
        free(sht);
        return NULL;
    }

    sht->shead = NULL;
    sht->stail = NULL;

    return sht;
}

/**
 * shash_table_set - Adds or updates a key/value pair in a sorted hash table.
 * @ht: The sorted hash table to modify.
 * @key: The key.
 * @value: The value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    shash_node_t *new_node, *temp;

    if (ht == NULL || key == NULL || *key == '\0')
        return 0;

    index = key_index((unsigned char *)key, ht->size);
    temp = ht->array[index];

    /* Check if key already exists, update value */
    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            free(temp->value);
            temp->value = strdup(value);
            if (temp->value == NULL)
                return 0;
            return 1;
        }
        temp = temp->next;
    }

    /* Create new node */
    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return 0;

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return 0;
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return 0;
    }

    /* Insert new node into sorted linked list */
    if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
    {
        new_node->sprev = NULL;
        new_node->snext = ht->shead;
        if (ht->shead != NULL)
            ht->shead->sprev = new_node;
        ht->shead = new_node;
        if (ht->stail == NULL)
            ht->stail = new_node;
    }
    else
    {
        temp = ht->shead;
        while (temp->snext != NULL && strcmp(key, temp->snext->key) > 0)
            temp = temp->snext;
        new_node->sprev = temp;
        new_node->snext = temp->snext;
        if (temp->snext != NULL)
            temp->snext->sprev = new_node;
        temp->snext = new_node;
        if (temp == ht->stail)
            ht->stail = new_node;
    }

    /* Insert new node into array */
    new_node->next = ht->array[index];
    ht->array[index] = new_node;

    return 1;
}

/**
 * shash_table_get - Retrieves a value associated with a key in the sorted hash table.
 * @ht: The sorted hash table to search.
 * @key: The key to search for.
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index;
    shash_node_t *temp;

    if (ht == NULL || key == NULL || *key == '\0')
        return NULL;

    index = key_index((unsigned char *)key, ht->size);
    temp = ht->array[index];

    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
            return temp->value;

        temp = temp->next;
    }

    return NULL;
}

/**
 * shash_table_print - Prints a sorted hash table using the sorted linked list.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;
    int flag = 0;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->shead;
    while (node != NULL)
    {
        if (flag)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        flag = 1;
        node = node->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order
 *                         using the sorted linked list.
 * @ht: The sorted hash table to print in reverse order.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;
    int flag = 0;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->stail;
    while (node != NULL)
    {
        if (flag)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        flag = 1;
        node = node->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
    unsigned long int i;
    shash_node_t *node, *temp;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node != NULL)
        {
            temp = node;
            node = node->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }

    free(ht->array);
    free(ht);
}
