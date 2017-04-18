/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_has_edge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:46:28 by aphan             #+#    #+#             */
/*   Updated: 2017/01/19 17:56:48 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int		graph_has_edge(t_graph *g, int src, int sink)
{
	int		i;

	if (src >= 0 && src < g->n && sink >= 0 && sink < g->n)
	{
		i = 0;
		while (i < g->alist[src]->d)
		{
			if (g->alist[src]->list[i] == sink)
				return (1);
			i++;
		}
	}
	return (0);
}
