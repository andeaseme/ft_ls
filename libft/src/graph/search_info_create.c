/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_info_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:46:01 by aphan             #+#    #+#             */
/*   Updated: 2017/01/24 21:56:47 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_search.h"

static int		*create_empty_array(int n)
{
	int		*a;
	int		i;

	if ((a = (int *)malloc(sizeof(int) * n)))
	{
		i = 0;
		while (i < n)
		{
			a[i] = SEARCH_INFO_NULL;
			i++;
		}
	}
	return (a);
}

t_search_info	*search_info_create(t_graph *g)
{
	t_search_info	*s;
	int				n;

	if ((s = (t_search_info *)malloc(sizeof(t_search_info))))
	{
		s->graph = g;
		s->reached = 0;
		n = graph_vertex_count(g);
		s->preorder = create_empty_array(n);
		s->time = create_empty_array(n);
		s->parent = create_empty_array(n);
		s->depth = create_empty_array(n);
	}
	return (s);
}
