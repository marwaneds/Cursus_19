/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:28:05 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/07 20:28:05 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

static int	*ft_free_return(t_list **lst, char *line)
{
	ft_lstclear(lst);
	free(line);
	return (0);
}

static int	ft_strtoi(char *str)
{
	if (!str)
		return (-1);
	else if (!ft_strcmp(str, "sa\n"))
		return (SA);
	else if (!ft_strcmp(str, "sb\n"))
		return (SB);
	else if (!ft_strcmp(str, "ss\n"))
		return (SS);
	else if (!ft_strcmp(str, "pa\n"))
		return (PA);
	else if (!ft_strcmp(str, "pb\n"))
		return (PB);
	else if (!ft_strcmp(str, "ra\n"))
		return (RA);
	else if (!ft_strcmp(str, "rb\n"))
		return (RB);
	else if (!ft_strcmp(str, "rr\n"))
		return (RR);
	else if (!ft_strcmp(str, "rra\n"))
		return (RRA);
	else if (!ft_strcmp(str, "rrb\n"))
		return (RRB);
	else if (!ft_strcmp(str, "rrr\n"))
		return (RRR);
	return (-1);
}

static int	*ft_parselst(t_list *lst, int size)
{
	int		index;
	int		*res;
	t_list	*lstsave;

	res = malloc(sizeof(*res) * (size + 1));
	if (!res)
		return (ft_free_return(&lst, 0));
	index = 0;
	while (index < size)
	{
		res[index] = lst->content;
		lstsave = lst;
		lst = lst->next;
		free(lstsave);
		++index;
	}
	res[index] = -1;
	return (res);
}

int	*ft_read(void)
{
	int		size;
	int		move;
	char	*line;
	t_list	*lst;
	t_list	*tmp;

	line = get_next_line(0);
	lst = 0;
	size = 0;
	move = ft_strtoi(line);
	while (move != -1)
	{
		++size;
		tmp = ft_lstnew(move);
		if (!tmp)
			return (ft_free_return(&lst, line));
		ft_lstadd_back(&lst, tmp);
		free(line);
		line = get_next_line(0);
		move = ft_strtoi(line);
	}
	if (line)
		return (ft_free_return(&lst, line));
	return (ft_parselst(lst, size));
}
