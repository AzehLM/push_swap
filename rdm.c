#include "push_swap.h"
#include <limits.h>

void sort_tmp(t_stacks *stacks)
{
    int i = 0;
    int j;
    int min;
    int tmp;

    while (i < stacks->tmp.size - 1)
    {
        min = i;
        j = i + 1;
        while (j < stacks->tmp.size)
        {
            if (stacks->tmp.addr[j] < stacks->tmp.addr[min])
                min = j;
            j++;
        }
        if (min != i)
        {
            tmp = stacks->tmp.addr[i];
            stacks->tmp.addr[i] = stacks->tmp.addr[min];
            stacks->tmp.addr[min] = tmp;
        }
        i++;
    }
}

void free_stacks(t_stacks *stacks)
{
    if (stacks->a.addr)
        free(stacks->a.addr);
    stacks->a.addr = NULL;
    if (stacks->b.addr)
        free(stacks->b.addr);
    stacks->b.addr = NULL;
    if (stacks->tmp.addr)
        free(stacks->tmp.addr);
    stacks->tmp.addr = NULL;
}

void init_stacks(t_stacks *stacks, int size)
{
    // Initialize stack A
    stacks->a.size = 0;
    stacks->a.addr = malloc(sizeof(int) * size);
    if (!stacks->a.addr)
        exit_with_error(ERR_MALLOC);

    // Initialize stack B
    stacks->b.size = 0;
    stacks->b.addr = malloc(sizeof(int) * size);
    if (!stacks->b.addr)
    {
        free(stacks->a.addr);
        exit_with_error(ERR_MALLOC);
    }

    // Initialize temporary stack
    stacks->tmp.size = 0;
    stacks->tmp.addr = malloc(sizeof(int) * size);
    if (!stacks->tmp.addr)
    {
        free(stacks->a.addr);
        free(stacks->b.addr);
        exit_with_error(ERR_MALLOC);
    }
}

int parse_params(int ac, char **av, t_stacks *stacks)
{
    int i = 1;

    stacks->tmp.addr = malloc(sizeof(int) * (ac - 1));
    if (!stacks->tmp.addr)
        exit_with_error(ERR_MALLOC);

    while (av[i])
    {
        if (!is_strdigit(av[i]))
        {
            free_stacks(stacks);
            exit_with_error(ERR_NO_NUMERIC);
        }
        if (!check_out_of_range(av[i]))
        {
            free_stacks(stacks);
            exit_with_error(ERR_OUT_OF_RANGE);
        }
        stacks->tmp.addr[i - 1] = ft_atoi(av[i]);
        i++;
    }
    stacks->tmp.size = ac - 1;

    if (!check_duplicates(stacks->tmp.addr, stacks->tmp.size))
    {
        free_stacks(stacks);
        exit_with_error(ERR_DUPLICATE);
    }
    return (0);
}

void free_av1(char **split, int *stack, size_t size)
{
    size_t i;

    if (split)
    {
        i = 0;
        while (i < size && split[i])
            free(split[i++]);
        free(split);
    }
    if (stack)
        free(stack);
}

int parse_string(const char *str, t_stacks *stacks)
{
    char    **split;
    int     size;

    split = ft_split(str, ' ');
    if (!split)
        exit_with_error(ERR_MALLOC);

    size = 0;
    while (split[size])
        size++;

    if (size == 0)
    {
        free(split);
        exit_with_error(ERR_EMPTY_STRING);
    }

    stacks->tmp.addr = malloc(sizeof(int) * size);
    if (!stacks->tmp.addr)
    {
        free_av1(split, NULL, size);
        exit_with_error(ERR_MALLOC);
    }

    // Parsing des nombres
    int i = 0;
    while (i < size)
    {
        if (!is_strdigit(split[i]))
        {
            free_av1(split, stacks->tmp.addr, size);
            exit_with_error(ERR_NO_NUMERIC);
        }
        if (!check_out_of_range(split[i]))
        {
            free_av1(split, stacks->tmp.addr, size);
            exit_with_error(ERR_OUT_OF_RANGE);
        }
        stacks->tmp.addr[i] = ft_atoi(split[i]);
        i++;
    }
    stacks->tmp.size = size;

    if (!check_duplicates(stacks->tmp.addr, size))
    {
        free_av1(split, stacks->tmp.addr, size);
        exit_with_error(ERR_DUPLICATE);
    }

    free_av1(split, NULL, size);
    return (0);
}

int is_strdigit(const char *str)
{
    size_t i;

    i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int check_out_of_range(const char *str)
{
    long long   res;
    int         sign;
    int         i;

    i = 0;
    res = 0;
    sign = 1;
    if (str[i] == '-' || str[i] == '+')
        if (str[i++] == '-')
            sign = -1;
    while (str[i] && ft_isdigit(str[i]))
    {
        res = res * 10 + (str[i] - '0');
        if (sign == 1 && res > INT_MAX)
            return (0);
        if (sign == -1 && (res * -1) < INT_MIN)
            return (0);
        i++;
    }
    return (1);
}

int check_duplicates(int *stack, int size)
{
    int i = 0;

    while (i < size - 1)
    {
        if (stack[i] == stack[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void indexing(t_stacks *stacks)
{
    int i = -1;
    int j;
    int *indexing_stack;
    int rank;

    indexing_stack = malloc(sizeof(int) * stacks->tmp.size);
    if (!indexing_stack)
        exit_with_error(ERR_MALLOC);

    while (++i < stacks->tmp.size)
        indexing_stack[i] = stacks->tmp.addr[i];

    i = 0;
    while (i < stacks->tmp.size)
    {
        rank = 1;
        j = 0;
        while (j < stacks->tmp.size)
        {
            if (indexing_stack[j] < indexing_stack[i])
                rank++;
            j++;
        }
        stacks->a.addr[i] = rank;
        i++;
    }
    stacks->a.size = stacks->tmp.size;
    free(indexing_stack);
}

void exit_with_error(t_exit_code error_code)
{
    if (error_code == ERR_NO_PARAMETERS)
        exit(ERR_NO_PARAMETERS);
    else
        write(STDERR_FILENO, "Error\n", 6);
    exit(error_code);
}

int check_arg(int ac, char **av, t_stacks *stacks)
{
    if (ac < 2)
        exit_with_error(ERR_NO_PARAMETERS);
    else if (ac == 2 && parse_string(av[1], stacks) == 0)
        ft_printf("success\n");
    else if (ac > 2 && parse_params(ac, av, stacks) == 0)
        ft_printf("success parse_params!\n");
    return (0);
}

int count_numbers(const char *str)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        // Skip les espaces
        while (str[i] && str[i] == ' ')
            i++;
        // Si on trouve un chiffre ou un signe, on compte un nombre
        if (str[i] && (ft_isdigit(str[i]) || str[i] == '-' || str[i] == '+'))
        {
            count++;
            // Skip le signe si présent
            if (str[i] == '-' || str[i] == '+')
                i++;
            // Skip le nombre entier
            while (str[i] && ft_isdigit(str[i]))
                i++;
        }
        // Skip les espaces suivants
        while (str[i] && str[i] == ' ')
            i++;
    }
    return (count);
}

int main(int ac, char **av)
{
    t_stacks    stacks;
    int         size;

    if (ac < 2)
        exit_with_error(ERR_NO_PARAMETERS);

    // Détermine la taille en fonction des arguments
    if (ac == 2)
        size = count_numbers(av[1]);
    else
        size = ac - 1;

    // Initialise les piles avec la bonne taille
    init_stacks(&stacks, size);

    // Parse les arguments
    check_arg(ac, av, &stacks);

    // Trie la pile temporaire et indexe la pile A
    sort_tmp(&stacks);
    indexing(&stacks);

    // Affichage pour debug
    ft_printf("-------- Trié --------\n");
    for (int i = 0; i < stacks.tmp.size; i++)
        ft_printf("tmp[%d] : %d\n", i, stacks.tmp.addr[i]);

    ft_printf("\n\n");
    for (int i = 0; i < stacks.a.size; i++)
        ft_printf("a[%d] : %d\n", i, stacks.a.addr[i]);
    ft_printf("----------------------\n");

    // Libère la mémoire
    free_stacks(&stacks);
    return (SUCCESS);
}
