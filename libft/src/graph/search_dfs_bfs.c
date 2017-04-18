/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_dfs_bfs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 22:06:37 by aphan             #+#    #+#             */
/*   Updated: 2017/02/25 20:31:51 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_search.h"
#include "ft_printf.h"

static void	push_edge(t_graph *g, int u, int v, void *data)
{
	t_queue *q;

	q = data;
	if ((q->top < graph_edge_count(g) + 1))
	{
		q->e[q->top].u = u;
		q->e[q->top].v = v;
		q->top++;
	}
}

static void	generic_search(t_search_info *r, int root, int use_queue)
{
	t_queue	q;
	t_edge	cur;

	q.e = (t_edge *)malloc(sizeof(t_edge) * (graph_edge_count(r->graph) + 1));
	if (q.e)
	{
		q.bottom = 0;
		q.top = 0;
		push_edge(r->graph, root, root, &q);
		while (q.bottom < q.top)
		{
			cur = (use_queue) ? q.e[q.bottom++] : q.e[--q.top];
			if (r->parent[cur.v] != SEARCH_INFO_NULL)
				continue ;
			if (r->reached >= graph_vertex_count(r->graph))
				break ;
			r->parent[cur.v] = cur.u;
			r->time[cur.v] = r->reached;
			r->preorder[r->reached++] = cur.v;
			r->depth[cur.v] = (cur.u == cur.v) ? 0 : r->depth[cur.u] + 1;
			graph_foreach(r->graph, cur.v, push_edge, &q);
		}
	}
	free(q.e);
}

void		dfs(t_search_info *results, int root)
{
	generic_search(results, root, 0);
}

void		bfs(t_search_info *results, int root)
{
	generic_search(results, root, 1);
}
