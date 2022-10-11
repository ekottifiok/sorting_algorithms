#include "deck.h"

/**
 * present_position - computes the present position for deck_node_t
 *
 * @start: where the pointer starts
 * Return: int
 */
int present_position(deck_node_t *start)
{
	int len_list;

	for (len_list = 0; start; len_list++)
		start = start->next;
	return (len_list);
}

/**
 * move_forward - moves the specified card forward
 *
 * @main: list to be worked on
 * @keys: the keys of the card
 * @position_end: data as to position and end of variables
 */
void move_forward(deck_node_t **main, char *keys, int position_end)
{
	deck_node_t *buffer = *main, *node, *prev_node, *next_node;
	int key_position, kind_value;

	kind_value = position_end % 10;
	position_end /= 10;
	key_position = position_end % 10;
	position_end /= 10;
	key_position += (position_end % 10) * 10;
	for (position_end /= 10; buffer->next && position_end > 0; position_end--)
	{
		prev_node = buffer->prev;
		next_node = buffer->next;
		node = buffer;
		if ((int)(node->card->kind) == kind_value &&
			*(node->card->value) == keys[key_position])
		{

			if (prev_node)
				prev_node->next = next_node;
			next_node->prev = prev_node;
			if (next_node->next != NULL)
				(next_node->next)->prev = node;
			node->next = next_node->next;
			next_node->next = node;
			node->prev = next_node;

			continue;
		}

		buffer = buffer->next;
	}
	*main = buffer;
}

/**
 * sort_deck - entrypoint main function that handles the sorting of the deck
 *
 * @deck: deck to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	int kind_value, key_value, info;
	char keys[] = "KQJ198765432A";
	deck_node_t *working_deck = *deck;
	size_t len_list, len_list_buf;

	if (!deck || !(*deck))
		return;

	for (working_deck = *deck; working_deck->prev;
		 working_deck = working_deck->prev)
		;
	len_list = present_position(working_deck);

	for (kind_value = 3, key_value = 0, len_list_buf = --len_list;
		 kind_value >= 0; working_deck = *deck, key_value++, len_list_buf--)
	{
		if (key_value == 13)
		{
			key_value = 0;
			kind_value--;
		}
		while (working_deck->prev)
			working_deck = working_deck->prev;
		info = len_list_buf * 1000 + key_value * 10 + kind_value;
		move_forward(&working_deck, keys, info);
		working_deck = working_deck->prev;

		if (kind_value == 0 && key_value + 1 == 12)
			break;
	}

	while (working_deck->prev)
		working_deck = working_deck->prev;
	*deck = working_deck;
}
