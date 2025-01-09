#include "day1.h"

static list_t *list_one;
static list_t *list_two;

/**
 * @brief
 * This function calculates the distance
 * between the values of both lists
 * 
 * @arg list_one: left column numbers
 * @arg list_two: right column numbers
 * These lists are generated by reading
 * the input file
 * 
 * @returns the sum of these distances
 */
int part_one(char *filename) 
{
    int result = 0;
    int min1 = 0;
    int min2 = 0;
    int dist = 0;

    read_file(filename, get_number_line);

    while (list_one != NULL && list_two != NULL) 
    {
        min1 = pop(&list_one)->value;
        min2 = pop(&list_two)->value;

        dist = abs(min1 - min2);

        result = result + dist;
    }

    free_list(&list_one);
    free_list(&list_two);

    return result;
}

int part_two(char *filename) 
{
    int result = 0;

    read_file(filename, get_number_line);

    while (list_one != NULL) 
    {
        list_t *tmp = pop(&list_one);
        int value = tmp->value;
        int count = 0;

        count = occurences(list_two, value);
        result = result + (count * value);

    }

    free_list(&list_one);
    free_list(&list_two);


    return result;
}

void get_number_line(char *line)
{
    if (line == NULL)
    {
        exit(EXIT_FAILURE);
    }

    char *first_number = strtok(line, " \t");
    char *second_number = strtok(NULL, " \t");

    int i1 = get_number_from_string(first_number);
    int i2 = get_number_from_string(second_number);

    if (list_one == NULL)
    {
        list_one = create_list(i1);
    }
    else
    {
        insert(&list_one, i1, 0);
    }
    if (list_two == NULL)
    {
        list_two = create_list(i2);
    }
    else
    {
        insert(&list_two, i2, 0);
    }

}
