/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_info_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <aphan@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 21:57:26 by aphan             #+#    #+#             */
/*   Updated: 2017/01/24 22:00:49 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph_search.h"

void	search_info_destroy(t_search_info *s)
{
	free(s->depth);
	free(s->parent);
	free(s->time);
	free(s->preorder);
	free(s);
}
