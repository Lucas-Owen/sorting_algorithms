#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * swap3 - swap two nodes of a doubly linked list
 * @first: The first node
 * @second: The second node
 * @head: Holds the address of the head
 * Return: void
 */
void swap3(deck_node_t *first, deck_node_t *second, deck_node_t **head)
{
	deck_node_t *prevFirst = first->prev;
	deck_node_t *nextSecond = second->next;
	deck_node_t *nextFirst;
	deck_node_t *prevSecond;

	if (first == second)
		return;
	if ((prevFirst && prevFirst == nextSecond) || prevFirst == second)
	{
		prevFirst = first;
		first = second;
		second = prevFirst;

		prevFirst = first->prev;
		nextSecond = second->next;
	}
	nextFirst = first->next;
	prevSecond = second->prev;
	if (nextFirst == second)
	{
		second->next = first;
		first->prev = second;
	}
	else
	{
		second->next = nextFirst;
		if (nextFirst)
			nextFirst->prev = second;
		first->prev = prevSecond;
		if (prevSecond)
			prevSecond->next = first;
	}
	first->next = nextSecond;
	if (nextSecond)
		nextSecond->prev = first;
	second->prev = prevFirst;
	if (prevFirst)
		prevFirst->next = second;
	*head = first->prev ? *head : first;
	*head = second->prev ? *head : second;
}

/**
 * cardValue - Returns the value of a card
 * ACE has 0 while KING has 13
 */
int cardValue(const card_t *card)
{
	if (strcmp(card->value, "King") == 0)
		return 13;
	if (strcmp(card->value, "Queen") == 0)
		return 12;
	if (strcmp(card->value, "Jack") == 0)
		return 11;
	if (strcmp(card->value, "Ace") == 0)
		return 0;
	return atoi(card->value);
}

/**
 * compareCardNodes - Compares two cards with the following priority
 * SPADE, HEART, CLUB, DIAMOND then ACE - KING
 *
 * @node1: The first node with first card
 * @node2: The second node with second card
 * Return: 0 if cards are equal, >0 if card 1 has higher priority <0 otherwise
 */
int compareCardNodes(const void *node1, const void *node2)
{
	const card_t *card1 = (*(deck_node_t **) node1)->card;
	const card_t *card2 = (*(deck_node_t **) node2)->card;

	if (card1->kind != card2->kind)
		return (card1->kind - card2->kind);
	return (cardValue(card1) - cardValue(card2));
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: The deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	int deck_size = 52;
	deck_node_t **array = malloc(sizeof(deck_node_t *) * deck_size);
	deck_node_t *deck_node = *deck, *next;
	int i = 0;

	if (!array)
		return;

	while (i < deck_size)
	{
		array[i] = deck_node;
		deck_node = deck_node->next;
		i++;
	}
	qsort(&array[0], deck_size, sizeof(deck_node_t *), compareCardNodes);
	*deck = array[0];
	deck_node = array[0];
	deck_node->prev = NULL;
	i = 0;
	while (i < deck_size)
	{
		next = array[i];
		deck_node->next = next;
		next->prev = deck_node;
		deck_node = next;
		i++;
	}
	deck_node->next = NULL;
}
