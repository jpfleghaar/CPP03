/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:10:24 by jenne             #+#    #+#             */
/*   Updated: 2026/02/11 15:24:55 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _energy = 100;
    _hitPoints = 100;
    _damage = 30;
    std::cout << "\033[34mFragTrap Default Constructor called" << "\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _energy = 100;
    _hitPoints = 100;
    _damage = 30;
    std::cout << "\033[34mFragTrap " << _name << " is in the game!" << "\033[0m"<< std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "\033[34mFragTrap " << _name << " has been destroyed" << std::endl;
}
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "\033[34mCreated a copy of FragTrap" << _name << "\033[0m" << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap& copy)
{
    std::cout << "FragTrap assigment operator called" << std::endl;
    if(this != &copy)
    {
        ClapTrap::operator=(copy);
    }
    return(*this);
}

void FragTrap::attack(const std::string& target)
{
    if(this->_energy > 0 && this->_hitPoints > 0)
    {
        this->_energy--;
        std::cout << "\033[33mFragTrap " <<  _name << " was attacked from! " << target 
        << " Energy: " << this->_energy << "\033[0m" << std::endl;
    }
    else if(this->_hitPoints <= 0)
    {
        std::cout << "\033[31mYou can not attack, FragTrap is DEAD!" << "\033[0m" << std::endl;
    }
    else 
    {
        std::cout << "\033[31mnot enough energy to attack" "\033[0m" << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << _name << " 🙏 " << std::endl;
}

