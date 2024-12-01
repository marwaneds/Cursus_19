/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mael-faq <mael-faq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:18:30 by mael-faq          #+#    #+#             */
/*   Updated: 2024/11/21 19:18:31 by mael-faq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strindex(char *haystack, char *needle)
{
	int i;
	int j;
	int n;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		n = i;
		while (needle[j] == haystack[n])
		{
			if (needle[j + 1] == '\0')
				return (i);
			n++;
			j++;
		}
		i++;
	}
	return (-1);
}
