#include "deck.h"



void move_forward(deck_node_t **main, int *flag, char *keys, char *type)
{
    deck_node_t *buffer = *main, *node, *prev_node, *next_node;

    for (; buffer->next;)
    {
        prev_node = buffer->prev;
        next_node = buffer->next;
        node = buffer;
        for (;type;type++)
        {

        }
    }
}

void move_backward(deck_node_t **main, int *flag, char *keys, char *type)
{

}

void sort_deck(deck_node_t **deck)
{
    int sort_flag;
    char keys[] = "A23456789JQK", kind[] = "SHCD", keys_rev[] = "KQJ98765432A", kind_rev[] = "DCHS";
    deck_node_t *working_deck = *deck;

    if (!deck || !(*deck))
        return;

    for (sort_flag = 1; sort_flag; working_deck = *deck)
    {
        sort_flag = 0;
        move_forward(&working_deck, &sort_flag, keys, kind);
        working_deck = working_deck->prev;
        move_backward(&working_deck, &sort_flag, keys_rev, kind_rev);
    }
    while (working_deck->prev)
        working_deck = working_deck->prev;
    *deck = working_deck;
}