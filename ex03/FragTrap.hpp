/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:10:27 by jenne             #+#    #+#             */
/*   Updated: 2026/02/12 13:41:46 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& copy);
    FragTrap& operator=(const FragTrap& copy);
    ~FragTrap();

    void highFivesGuys(void);
    void attack(const std::string& target);
    void beRepaird(unsigned int amount);
};

#endif