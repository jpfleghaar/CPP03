/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:21:05 by jenne             #+#    #+#             */
/*   Updated: 2026/02/11 13:04:36 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

unsigned int getRandomNum()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 10);
    return dist(gen);
}

void playTheGame(ClapTrap& hero, const std::string& enemy)
{
    while (hero.getHitPoints() > 0 && hero.getEnergy() > 0)
    {
        hero.attack(enemy);

        unsigned int damage = getRandomNum();
        hero.takeDamage(damage);

        unsigned int heal = getRandomNum();
        hero.beRepaired(heal);

        if (hero.getHitPoints() <= 0)
        {
            std::cout << "\033[33mOur hero is dead!\033[0m\n";
            return;
        }
        else if (hero.getEnergy() <= 0)
        {
            std::cout << "\033[33mOur hero has no energy left\033[0m\n";
            return;
        }
    }
}

int main (void)
{
    ClapTrap a("Bob");
    ClapTrap b;
    b = a;

  
    // a.attack("some other robot");
	// a.takeDamage(10);
	// a.takeDamage(10);
	// a.beRepaired(5);
	// a.attack("some other other robot");
    playTheGame(a, "harl");
    // b.palyTheGame("charls");
    // a.palyTheGame("harl");
    return (0);
}