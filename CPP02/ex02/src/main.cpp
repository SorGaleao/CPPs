/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:07:28 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/12 14:53:52 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int stringToEnum(std::string level) {
    if (level == "DEBUG" || level == "debug") return 0;
    else if (level == "INFO" || level == "info") return 1;
    else if (level == "WARNING" || level == "warning") return 2;
    else if (level == "ERROR" || level == "error") return 3;
    else return -1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./harlFilter LEVEL" << std::endl;
        return 1;
    }
    Harl harl;
    int level = stringToEnum(argv[1]);
    switch (level) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("debug");
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("info");
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("warning");
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("error");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return 0;
}