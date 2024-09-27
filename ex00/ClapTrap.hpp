/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:55:52 by deryacar          #+#    #+#             */
/*   Updated: 2024/09/25 14:55:52 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
class ClapTrap
{
    private:
        std::string name;
        int hitPoint;
        int energyPoint;
        int attackDamage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& copy);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& copy);
        std::string getName() const;
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setVar(std::string name,int hitPoint, int energyPoint, int attackDamage);
        int getHitPoint() const;
        int getEnergyPoint() const;
        int getAttackDamage() const;
};

#endif