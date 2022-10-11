#include "deck.h"

/**
 * @brief meant for trouble shooting
 * 
 * @param deck 
 */
void print_dec(const deck_node_t *deck)
{
    size_t i;
    char kinds[4] = {'S', 'H', 'C', 'D'};

	while (deck->prev)
		deck = deck->prev;
    i = 0;
    while (deck)
    {
        if (i)
            printf(", ");
        printf("{%s, %c}", deck->card->value, kinds[deck->card->kind]);
        if (i == 12)
            printf("\n");
        i = (i + 1) % 13;
        deck = deck->next;
    }
}

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
 * move_backward - moves the specified card backward
 *
 * @main: list to be worked on
 * @keys: the keys of the card
 * @position_end: data as to position and end of variables
 */
void move_backward(deck_node_t **main, char *keys, int position_end)
{
	deck_node_t *buffer = *main, *node, *prev_node, *next_node;
	int key_position, kind_value, position_sub_flag = 1;
	char *inverted_key = "3210";

	kind_value = inverted_key[position_end % 10] - 48;
	position_end /= 10;
	key_position = position_end % 10;
	key_position += ((position_end / 10) % 10) * 10;
	position_end /= 100;
	for (; buffer->prev;)
	{
		prev_node = buffer->prev;
		next_node = buffer->next;
		node = buffer;
		if ((int)(node->card->kind) == kind_value &&
			*(node->card->value) == keys[key_position] && position_end >= 0)
		{
			if (position_sub_flag)
			{
				position_end -= present_position(buffer);
				position_sub_flag = 0;
			}
			if (prev_node)
				prev_node->next = next_node;
			next_node->prev = prev_node;
			node->next = prev_node;
			node->prev = prev_node->prev;
			if (prev_node)
			{
				if (prev_node->prev != NULL)
					prev_node->prev->next = node;
				prev_node->prev = node;
			}
			position_end--;
			continue;
		}
		buffer = buffer->prev;
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
	char keys[] = "A234567891JQK", keys_rev[] = "KQJ198765432A";
	deck_node_t *working_deck = *deck;
	size_t len_list, len_list_buf;

	if (!deck || !(*deck))
		return;

	for (working_deck = *deck; working_deck->prev;
		 working_deck = working_deck->prev)
		;
	len_list = present_position(working_deck);

	for (kind_value = 3, key_value = 0, len_list_buf = --len_list;
		 kind_value > 1; working_deck = *deck, key_value++, len_list_buf--)
	{
		if (key_value == 13)
		{
			key_value = 0;
			kind_value--;
		}
		while (working_deck->prev)
			working_deck = working_deck->prev;
		info = len_list_buf * 1000 + key_value * 10 + kind_value;
		move_forward(&working_deck, keys_rev, info);
		working_deck = working_deck->prev;
		print_dec(working_deck);
		move_backward(&working_deck, keys, info);
		print_dec(working_deck);
		
	}
	while (working_deck->prev)
		working_deck = working_deck->prev;
	*deck = working_deck;
}
