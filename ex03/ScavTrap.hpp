/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:01:52 by jenne             #+#    #+#             */
/*   Updated: 2026/02/12 13:41:55 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& copy);
    ScavTrap& operator=(const ScavTrap& copy);
    ~ScavTrap();

    void guardGate();
    void attack(const std::string& target);
    void beRepaird(unsigned int amount);
};

#endif