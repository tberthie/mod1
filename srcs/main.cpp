/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:06:17 by tberthie          #+#    #+#             */
/*   Updated: 2017/07/11 14:53:04 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

int			main(int ac, char *av[]) {

	vector<map>		maps;

	if (ac < 2)
		cerr << "mod1: Not enough arguments" << endl;
	else if (parse_args(--ac, av, &maps)) {
		cout << "mod1: " << maps.size() << " valid maps" << endl;
	}


	for (size_t i = 0; i < maps.size(); i++) {
		cout << "Map #" << i << endl;
		for (size_t j = 0; j < maps[i].points.size(); j++) {
			cout << "x " << maps[i].points[j].x;
			cout << "\ty " << maps[i].points[j].y;
			cout << "\tz " << maps[i].points[j].z << endl;
		}
	}


	return 0;
}
