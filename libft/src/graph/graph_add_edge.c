/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_add_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:10:11 by aphan             #+#    #+#             */
/*   Updated: 2017/02/25 20:50:36 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	graph_add_edge(t_graph *g, int u, int v)
{
	if (u >= 0 && u < g->n && v >= 0 && v < g->n)
	{
		while (g->alist[u]->d >= g->alist[u]->len)
		{
			g->alist[u]->len *= 2;
			g->alist[u] = (t_successors *)ft_realloc(g->alist[u],
				sizeof(t_successors) + sizeof(int) * (g->alist[u]->len / 2 - 1),
				sizeof(t_successors) + sizeof(int) * (g->alist[u]->len - 1));
		}
		g->alist[u]->list[g->alist[u]->d++] = v;
		g->alist[u]->is_sorted = 0;
		g->m++;
	}
}
