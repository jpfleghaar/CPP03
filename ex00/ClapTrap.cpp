/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:53:56 by jenne             #+#    #+#             */
/*   Updated: 2026/02/11 13:03:23 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _energy(10), _hitPoints(10), _damage(0)
{
    std::cout << "\033[34mClapTrap " << _name << " is in the game!" << "\033[0m"<< std::endl;
}
ClapTrap::ClapTrap() : _name("someone"), _energy(10), _hitPoints(10), _damage(0)
{
    std::cout << "ClapTrap Default Constructor called" << "\033[0m" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "\033[34mClapTrap " << _name << " has been destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _name(copy._name), _energy(copy._energy),
     _hitPoints(copy._hitPoints), _damage(copy._damage)
{
    std::cout << "\033[34mCreated a copy of ClapTrap" << _name << "\033[0m" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    if(this !=  &copy)
    {
        _name = copy._name;
        _energy = copy._energy;
        _hitPoints = copy._hitPoints;
        _damage = copy._damage;
    }
    return(*this);
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints > amount)
    {
        this->_hitPoints -= amount;
    }
    else
    {
        this->_hitPoints = 0;
    }
    
    std::cout << "\033[31m" << this->_name << " took " << amount
    << " damage, HP: " << this->_hitPoints << "\033[0m" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if(this->_energy > 0 && this->_hitPoints > 0)
    {
        std::cout << "\033[33m" <<  _name << " was attacked from! " << target << "\033[0m" << std::endl;
        this->_energy--;
    }
    else if(this->_hitPoints <= 0)
    {
        std::cout << "\033[31mYou can not attack, YOU ARE DEAD!" << "\033[0m" << std::endl;
    }
    else 
    {
        std::cout << "\033[31mnot enough energy to attack" "\033[0m" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energy > 0 && this->_hitPoints > 0)
    {
        this->_hitPoints += amount;
        if (this->_hitPoints > 10)
        this->_hitPoints = 10;
        
        this->_energy--;
        
        std::cout << "\033[32m" << this->_name << " repaired to "
        << this->_hitPoints << " HP" <<  "\033[0m" << std::endl;
    }
    else
    {
        std::cout << "\033[33mClapTrap " << this->_name << " cannot be repaired" << "\033[0m" << std::endl;
    }

}

int ClapTrap::getHitPoints() const
{
    return(_hitPoints);
}
int ClapTrap::getEnergy() const
{
    return(_energy);
}
