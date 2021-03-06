/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:07:47 by tberthie          #+#    #+#             */
/*   Updated: 2017/07/11 16:21:47 by tberthie         ###   ########.fr       */
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

# define WINX	750
# define WINY	750

using namespace std;

class	vec3 {

	public:
		int	x;
		int	y;
		int	h;
};

class	map {

	public:
		char			*path;
		vector<vec3>	points;
};	

class	visu {

	public:
		SDL_Window		*win;
		SDL_Renderer	*ren;
};

char	parse_args(int ac, char *av[], vector<map> *maps);
void	render(visu *visual, vector<map> *maps);

#endif
