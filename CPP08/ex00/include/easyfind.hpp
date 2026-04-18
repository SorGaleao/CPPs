/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:14:32 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/02/10 17:21:51 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int to_find) {
	typename T::iterator i = std::find(container.begin(), container.end(), to_find);
	if (i == container.end())
		throw std::runtime_error("value not found");
	return i;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int to_find) {
	typename T::const_iterator i = std::find(container.begin(), container.end(), to_find);
	if (i == container.end())
		throw std::runtime_error("value not found");
	return i;
}


#endif
