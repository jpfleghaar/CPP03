/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:21:05 by jenne             #+#    #+#             */
/*   Updated: 2026/02/10 13:47:39 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap a("Bob");
    ClapTrap b;
    b = a;

  
    a.attack("some other robot");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
    // a.palyTheGame("harl");
    // b.palyTheGame("charls");
    // a.palyTheGame("harl");
    return (0);
}