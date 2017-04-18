/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:46:42 by aphan             #+#    #+#             */
/*   Updated: 2017/01/19 18:56:10 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int		graph_vertex_count(t_graph *g)
{
	return (g->n);
}

int		graph_edge_count(t_graph *g)
{
	return (g->m);
}

int		graph_out_degree(t_graph *g, int src)
{
	if (src >= 0 && src < g->n)
	{
		return (g->alist[src]->d);
	}
	return (0);
}
