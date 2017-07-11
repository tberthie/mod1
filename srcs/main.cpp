/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:06:17 by tberthie          #+#    #+#             */
/*   Updated: 2017/07/11 16:14:58 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int				main(int ac, char *av[]) {

	vector<map>		maps;
	visu			visual;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
		cerr << "mod1: Failed to init SDL: " << SDL_GetError() << endl;
		return 0;
	} else if (TTF_Init()) {
		cerr << "mod1: Failed to init TTF: " << TTF_GetError() << endl;
		return 0;
	} else if (ac < 2)
		cerr << "usage: ./mod1 [map file] [...]" << endl;
	else if (parse_args(--ac, av, &maps)) {
		if (!(visual.win = SDL_CreateWindow("mod1", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINX, WINY, SDL_WINDOW_SHOWN)) || !(visual.ren =
		SDL_CreateRenderer(visual.win, -1, SDL_RENDERER_ACCELERATED))) {
			cerr << "mod1: SDL error occured: " << SDL_GetError() << endl;
			return 0;
		}
		render(&visual, &maps);
	}
	SDL_Quit();
	return 0;
}
