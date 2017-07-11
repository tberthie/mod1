/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:06:17 by tberthie          #+#    #+#             */
/*   Updated: 2017/07/11 15:38:09 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int				main(int ac, char *av[]) {

	vector<map>		maps;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
		cerr << "mod1: Failed to init SDL: " << SDL_GetError() << endl;
		return 0;
	} else if (TTF_Init()) {
		cerr << "mod1: Failed to init TTF: " << TTF_GetError() << endl;
		return 0;
	} else if (ac < 2)
		cerr << "mod1: Not enough arguments" << endl;
	else if (parse_args(--ac, av, &maps)) {
		for (size_t i = 0; i < maps.size(); i++) {
			if (!(maps[i].win = SDL_CreateWindow("mod1", WINX * i, 0,
			WINX, WINY, SDL_WINDOW_SHOWN)) || !(maps[i].ren =
			SDL_CreateRenderer(maps[i].win, -1, SDL_RENDERER_ACCELERATED))) {
				cerr << "mod1: SDL error occured: " << SDL_GetError() << endl;
				return 0;
			}
		}
		render(&maps);
	}
	SDL_Quit();
	return 0;
}
