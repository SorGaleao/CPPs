/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: automated <auto@local>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 00:00:00 by automated         #+#    #+#             */
/*   Updated: 2026/04/17 00:00:00 by automated        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include <string>
#include <cstddef>
#include <stdexcept>

template <typename T>
Array<T>::Array(): data(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n): data(NULL), length(n) {
    if (length > 0)
        data = new T[length]();
    else
        data = NULL;
}

template <typename T>
Array<T>::Array(const Array& other): data(NULL), length(other.length) {
    if (length > 0) {
        data = new T[length];
        for (std::size_t i = 0; i < length; ++i)
            data[i] = other.data[i];
    } else {
        data = NULL;
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        T* newdata = NULL;
        if (other.length > 0) {
            newdata = new T[other.length];
            for (std::size_t i = 0; i < other.length; ++i)
                newdata[i] = other.data[i];
        }
        delete[] data;
        data = newdata;
        length = other.length;
    }
    return *this;
}

template <typename T>
Array<T>::~Array() { delete[] data; }

template <typename T>
T& Array<T>::operator[](std::size_t idx) {
    if (idx >= length)
        throw std::out_of_range("Array index out of range");
    return data[idx];
}

template <typename T>
const T& Array<T>::operator[](std::size_t idx) const {
    if (idx >= length)
        throw std::out_of_range("Array index out of range");
    return data[idx];
}

template <typename T>
std::size_t Array<T>::size() const { return length; }

// Explicit instantiations for types used in tests
template class Array<int>;
template class Array<std::string>;
