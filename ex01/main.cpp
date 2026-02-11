/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:21:05 by jenne             #+#    #+#             */
/*   Updated: 2026/02/11 15:06:01 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

unsigned int getRandomNum10()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 10);
    return dist(gen);
}
unsigned int getRandomNum100()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);
    return dist(gen);
}

void playClapTrap(ClapTrap& hero, const std::string& enemy)
{
    while (hero.getHitPoints() > 0 && hero.getEnergy() > 0)
    {
        hero.attack(enemy);

        unsigned int damage = getRandomNum10();
        hero.takeDamage(damage);

        unsigned int heal = getRandomNum10();
        hero.beRepaired(heal);

        if (hero.getHitPoints() <= 0)
        {
            std::cout << "\033[33mOur ClapTrap is dead!\033[0m\n";
            return;
        }
        else if (hero.getEnergy() <= 0)
        {
            std::cout << "\033[33mOur ClapTrap has no energy left\033[0m\n";
            return;
        }
    }
}
void playScavTrap(ScavTrap& hero, const std::string& enemy)
{
    while (hero.getHitPoints() > 0 && hero.getEnergy() > 0)
    {
        hero.attack(enemy);

        unsigned int damage = getRandomNum100();
        hero.takeDamage(damage);

        unsigned int heal = getRandomNum100();
        hero.beRepaired(heal);

        if (hero.getHitPoints() <= 0)
        {
            std::cout << "\033[33mOur ScavTrap is dead!\033[0m\n";
            return;
        }
        else if (hero.getEnergy() <= 0)
        {
            std::cout << "\033[33mOur ScavTrap has no energy left\033[0m\n";
            return;
        }
    }
}

int main (void)
{
    ClapTrap a("Bob");
    ScavTrap b("harald");

  
    std::cout << "ClapTrap Testing\n" << std::endl;
    playClapTrap(a, "harl");
    std::cout << "\nScavTrap Testing\n" << std::endl;
    playScavTrap(b, "thomas");
    b.guardGate();
    return (0);
}