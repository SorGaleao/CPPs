/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:14:32 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/02/10 17:21:51 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <cstddef>

template <typename T, typename F>
void iter(T *array, std::size_t const size, F func) {
    if (!array)
        return;
    for (std::size_t i = 0; i < size; ++i)
        func(array[i]);
}

template <typename T, typename F>
void iter(T const *array, std::size_t const size, F func) {
    if (!array)
        return;
    for (std::size_t i = 0; i < size; ++i)
        func(array[i]);
}

#endif