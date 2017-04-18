/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:26:02 by aphan             #+#    #+#             */
/*   Updated: 2017/01/23 14:34:56 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "libft.h"

/*
** basic directed graph type
** the implementation uses adjacency lists represented as variable-length
** arrays.  These arrays may or may not be sorted: if one gets long enough and
** you call graph_has_edge on its source, it will be
*/

/*
** t_successors
** d			number of succesors
** len			number of slots in array
** is_sorted	true if list is already sorted
** list			actual list of successors
**
** t_graph
** n			number of vertices
** m			number of edges
*/

typedef struct		s_successors
{
	int				d;
	int				len;
	char			is_sorted;
	int				list[1];
}					t_successors;

typedef struct		s_graph
{
	int				n;
	int				m;
	t_successors	*alist[1];
}					t_graph;

t_graph				*graph_create(int n);
void				graph_destroy(t_graph *g);
void				graph_add_edge(t_graph *g, int u, int v);
int					graph_has_edge(t_graph *g, int src, int sink);
int					graph_vertex_count(t_graph *g);
int					graph_edge_count(t_graph *g);
int					graph_out_degree(t_graph *g, int src);
void				graph_foreach(t_graph *g, int src,
		void (*f)(t_graph *g, int src, int sink, void *data), void *data);
#endif
