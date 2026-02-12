/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 13:32:54 by jenne             #+#    #+#             */
/*   Updated: 2026/02/12 14:21:37 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap("Default"), FragTrap("Default"), _name("Default")
{
    _energy = ScavTrap::_energy;
    _hitPoints = FragTrap::_hitPoints;
    _damage = FragTrap::_damage;
    std::cout << "\033[34mDiamondTrap Default Constructor called" << "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
    _energy = ScavTrap::_energy;
    _hitPoints = FragTrap::_hitPoints;
    _damage = FragTrap::_damage;
    std::cout << "\033[34mDiamondTrap " << _name << " is in the game!" << "\033[0m"<< std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "\033[34mDiamondTrap " << _name << " has been destroyed" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy), _name(copy._name)
{
    std::cout << "\033[34mCreated a copy of DiamondTrap" << _name << "\033[0m" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
    std::cout << "DiamondTrap assigment operator called" << std::endl;
    if(this != &copy)
    {
        ClapTrap::operator=(copy);
        _name = copy._name;
    }
    return(*this);
}
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}


void DiamondTrap::whoAmI()
{
    std::cout << "My DiamondTrap name is " << _name << std::endl;
    std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}