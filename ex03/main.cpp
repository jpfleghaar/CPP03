/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenne <jpflegha@student.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:21:05 by jenne             #+#    #+#             */
/*   Updated: 2026/02/12 14:40:23 by jenne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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
void playFragTrap(FragTrap& hero, const std::string& enemy)
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
    DiamondTrap D("Daniel");
    DiamondTrap c;
    c = D;

    D.whoAmI();
    D.attack("ash");
    c.whoAmI();
    playFragTrap(c, "worrier");
    // ClapTrap a("Bob");
    // ScavTrap b("harald");
    // FragTrap c("Felix");


    
  
    // std::cout << "ClapTrap Testing\n" << std::endl;
    // playClapTrap(a, "harl");
    // std::cout << "\nScavTrap Testing\n" << std::endl;
    // playScavTrap(b, "thomas");
    // std::cout << "\nFragTrap Testing\n" << std::endl;
    // playFragTrap(c, "Alex");
    // c.highFivesGuys();
    return (0);
}