/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:07:47 by tberthie          #+#    #+#             */
/*   Updated: 2017/07/11 15:59:45 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD1_H
# define MOD1_H

# include <SDL.h>
# include <SDL_ttf.h>

# include <iostream>
# include <fstream>
# include <vector>
# include <string>

# define WIN_SIZE	500

using namespace std;

class	vec3 {

	public:
		int	x;
		int	y;
		int	z;
};

class	map {

	public:
		char			*path;
		vector<vec3>	points;

		SDL_Window		*win;
		SDL_Renderer	*ren;

};	

char	parse_args(int ac, char *av[], vector<map> *maps);
void	render(vector<map> *maps);

#endif
