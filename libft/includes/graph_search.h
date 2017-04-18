/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_search.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:23:47 by aphan             #+#    #+#             */
/*   Updated: 2017/02/25 21:00:05 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_SEARCH_H
# define GRAPH_SEARCH_H

# include "graph.h"

/*
**		Typical usage
**
** 		s_search_info	*s;
**		int				n;
**
**		s = search_info_create(g);
**		n = graph_vertices(g);
**		for(i = 0; i < n; i++)
**		{
**			dfs(s, i);
**		}
**
**		... use results in s ...
**
**		search_info_destroy(s);
*/

/*
** t_search_info
** reached		count of reached nodes
** *preorder	list of nodes in order first reached
** *time		time[i] == position of node i in preorder list
** *parent		parent in DFS or BFS forest
** *depth		distance from root
**
** t_edge
** u			source
** v			sink
*/

# define SEARCH_INFO_NULL (-1)

typedef struct	s_search_info
{
	t_graph		*graph;
	int			reached;
	int			*preorder;
	int			*time;
	int			*parent;
	int			*depth;
}				t_search_info;

typedef struct	s_edge
{
	int			u;
	int			v;
}				t_edge;

typedef struct	s_queue
{
	t_edge		*e;
	int			bottom;
	int			top;
}				t_queue;

t_search_info	*search_info_create(t_graph *g);
void			search_info_destroy(t_search_info *s);
void			dfs(t_search_info *results, int root);
void			bfs(t_search_info *results, int root);

#endif
