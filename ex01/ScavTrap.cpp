/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:01:49 by jenne             #+#    #+#             */
/*   Updated: 2026/02/11 15:05:11 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _energy = 50;
    _hitPoints = 100;
    _damage = 20;
    std::cout << "\033[34mScavTrap Default Constructor called" << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _energy = 50;
    _hitPoints = 100;
    _damage = 20;
    std::cout << "\033[34mScavTrap " << _name << " is in the game!" << "\033[0m"<< std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[34mScavTrap " << _name << " has been destroyed" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "\033[34mCreated a copy of ScavTrap" << _name << "\033[0m" << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
    std::cout << "ScavTrap assigment operator called" << std::endl;
    if(this != &copy)
    {
        ClapTrap::operator=(copy);
    }
    return(*this);
}

void ScavTrap::attack(const std::string& target)
{
    if(this->_energy > 0 && this->_hitPoints > 0)
    {
        this->_energy--;
        std::cout << "\033[33mScavTrap " <<  _name << " was attacked from! " << target 
        << " Energy: " << this->_energy << "\033[0m" << std::endl;
    }
    else if(this->_hitPoints <= 0)
    {
        std::cout << "\033[31mYou can not attack, ScavTrap is DEAD!" << "\033[0m" << std::endl;
    }
    else 
    {
        std::cout << "\033[31mnot enough energy to attack" "\033[0m" << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "\033[33mScavTrap " << _name << " is in Gate keeper mode" << std::endl;
}

