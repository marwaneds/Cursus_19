/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:27:48 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/13 14:33:12 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

enum
{
	SA = 0,
	SB = 1,
	SS = 2,
	PA = 3,
	PB = 4,
	RA = 5,
	RB = 6,
	RR = 7,
	RRA = 8,
	RRB = 9,
	RRR = 10
};

typedef struct s_stack
{
	int		size;
	int		*arr;
}				t_stack;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

/*	gnl */

char		*get_next_line(int fd);

/*	gnl_utils */

char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char **str);
char		*ft_strcpy_until_nl(char *str);
char		*ft_strcpy_from_nl(char **str);

/*	do_move */

int			ft_move(t_stack *stack_a, int *move);

/*	main	*/

int			main(int argc, char **argv);

/*	operation	*/

void		ft_operation(t_stack *stack_a, t_stack *stack_b, int move);

/*	read	*/

int			*ft_read(void);

/*	parsing	*/

int			*parse_arg(int *argc, char **argv);

/* ft_split */

char		**ft_split(const char *s, char c);

/*	utils	*/

void		ft_lstclear(t_list **lst);
size_t		ft_strlen(const char *str);
t_list		*ft_lstnew(int content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_putstr(char *str);

/*	utils 2	*/

long		ft_atoi(const char *str);
int			ft_tablen(char **tab);
int			ft_strcmp(const char *s1, const char *s2);

#endif