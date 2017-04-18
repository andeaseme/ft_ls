/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_foreach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:06:33 by aphan             #+#    #+#             */
/*   Updated: 2017/01/19 18:24:08 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	graph_foreach(t_graph *g, int src,
		void (*f)(t_graph *g, int src, int sink, void *data), void *data)
{
	int		i;

	if (src >= 0 && src < g->n)
	{
		i = 0;
		while (i < g->alist[src]->d)
		{
			f(g, src, g->alist[src]->list[i], data);
			i++;
		}
	}
}
