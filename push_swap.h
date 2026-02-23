#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_stack_node
{
    int value;
    int current_position;
    int final_index;
  
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *previous;
}               t_stack_node;

int	check_duplicates(int *values, int count);
int is_valid_number(char *str);
char	**ft_split(char *s, char c);
void stack_init(t_stack_node **a, char **argv);
long ft_atol(char *str);
void    free_matrix(char **matrix);
void	free_stack(t_stack_node **stack);
void	error_free(t_stack_node **a, char **argv);
int	error_syntax(char *str_nbr);
int	error_repetition(t_stack_node *a, int nbr);
void    append_node(t_stack_node **a, int nbr);

#endif