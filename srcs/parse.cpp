/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:53:13 by tberthie          #+#    #+#             */
/*   Updated: 2017/07/11 16:08:21 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

static string	remove_spaces(string data) {

	string		str;

	for (size_t i = 0; i < data.size(); i++)
		if (data[i] != ' ' && data[i] != '\t')
			str += data[i];
	return str;
}

static vector<string>	split_coords(string data) {

	vector<string>	split;
	vector<string>	err;
	string			coord;
	char			in = 0;

	for (size_t i = 0; i < data.size(); i++) {
		if (data[i] == '(' && i + 1 != data.size()) {
			if (in)
				return err;
			in = 1;
		} else if (data[i] == ')') {
			if (!in || !coord.size())
				return err;
			split.push_back(coord);
			coord.clear();
			in = 0;
		} else if ((data[i] < '0' || data[i] > '9') && data[i] != ',')
			return err;
		else
			coord += data[i];
	}
	return split;
}

static char		add_map(char *path, vector<string> split, vector<map> *maps) {

	map		nmap;
	vec3	coords;
	int		count;
	int		tmp;

	for (size_t i = 0; i < split.size(); i++) {
		count = 0;
		tmp = 0;
		for (size_t j = 0; j < split[i].size(); j++) {
			if (split[i][j] >= '0' && split[i][j] <= '9')
				tmp = tmp * 10 + split[i][j] - '0';
			else if (split[i][j] == ',' && j != split[i].size() - 1 &&
			split[i][j + 1] != ',' && j && count < 2) {
				!count ? coords.x = tmp : 0;
				count == 1 ? coords.y = tmp : 0;
				tmp = 0;
				count++;
			} else
				return 0;
		}
		coords.z = tmp;
		nmap.points.push_back(coords);
	}
	if (count < 2)
		return 0;
	nmap.path = path;
	maps->push_back(nmap);	
	return 1;
}

char			parse_args(int ac, char *av[], vector<map> *maps) {

	fstream			fs;
	string			buf;
	string			data;
	vector<string>	split;

	for (int i = 1; i <= ac; i++) {
		fs.open(av[i], fstream::in);
		if (!fs) {
			cerr << "mod1: " << av[i] << ": Failed to open file" << endl;
			return 0;
		} else {
			while (getline(fs, buf))
				data += buf;
			data = remove_spaces(data);
			if (!(split = split_coords(data)).size() ||
			!add_map(av[i], split, maps)) {
				cerr << "mod1: " << av[i] << ": Invalid map file" << endl;
				return 0;
			}
		}
		data.clear();
		fs.close();
	}
	return 1;
}
