/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:07:47 by tberthie          #+#    #+#             */
/*   Updated: 2017/07/11 14:50:44 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD1_H
# define MOD1_H

# include <iostream>
# include <fstream>
# include <vector>
# include <string>

using namespace std;

class	vec3 {

	public:
		int	x;
		int	y;
		int	z;
};

class	map {

	public:
		vector<vec3>	points;
};	

char	parse_args(int ac, char *av[], vector<map> *maps);

#endif
