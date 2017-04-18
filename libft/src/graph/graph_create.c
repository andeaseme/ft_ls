/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:41:56 by aphan             #+#    #+#             */
/*   Updated: 2017/01/23 16:04:47 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

/*
** create a new graph with n vertices labeled 0..n-1 and no edges
*/

t_graph		*graph_create(int n)
{
	t_graph	*g;
	int		i;

	g = (t_graph *)malloc(sizeof(t_graph) + sizeof(t_successors *) * (n - 1));
	if (g)
	{
		g->n = n;
		g->m = 0;
		i = 0;
		while (i < n)
		{
			if (!(g->alist[i] = malloc(sizeof(t_successors))))
				return (0);
			g->alist[i]->d = 0;
			g->alist[i]->len = 1;
			g->alist[i]->is_sorted = 1;
			i++;
		}
	}
	return (g);
}
