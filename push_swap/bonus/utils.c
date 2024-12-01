/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:28:02 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/07 20:28:03 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*save;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		save = current->next;
		free(current);
		current = save;
	}
	*lst = 0;
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len ++;
	return (len);
}

t_list	*ft_lstnew(int content)
{
	t_list	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (0);
	res->content = content;
	res->next = 0;
	return (res);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	current = *lst;
	if (!current)
		*lst = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	ft_putstr(char *str)
{
	int		len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	write(1, str, len);
}
