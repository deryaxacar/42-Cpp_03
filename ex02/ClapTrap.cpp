/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:41:29 by deryacar          #+#    #+#             */
/*   Updated: 2024/09/25 18:41:29 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}
ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10),attackDamage(0)
{
    std::cout << this->getName() <<": Constructor call" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& copy)
{
    *this = copy;
}
ClapTrap::~ClapTrap()
{
    std::cout << this->getName()<<": Destructor call" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
    this->name = copy.name;
    this->hitPoint = copy.hitPoint;
    this->energyPoint = copy.energyPoint;
    this->attackDamage = copy.attackDamage;
    return *this;
}
void ClapTrap::setVar(std::string name,int hitPoint, int energyPoint, int attackDamage)
{
    this->name = name;
    this->hitPoint = hitPoint;
    this->energyPoint = energyPoint;
    this->attackDamage = attackDamage;
}
std::string ClapTrap::getName() const
{
    return(this->name);
}
int ClapTrap::getHitPoint() const
{
    return(this->hitPoint);
}
int ClapTrap::getEnergyPoint() const
{
    return(this->energyPoint);
}
int ClapTrap::getAttackDamage() const
{
    return(this->attackDamage);
}

void ClapTrap::attack(const std::string& target)
{
    if(this->hitPoint <= 0 || this->energyPoint <= 0)
	{
		std::cout << "I cannot do anything" << std::endl;
		return ;
	}

    if(this->energyPoint > 0)
    {
        std::cout << this->name << " attack " << target << " causing " << this->attackDamage << " damage!\n"; 
        this->energyPoint -= 1;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if(this->hitPoint <= 0)
        return;
    if(int(amount) > 0)
    {
        std::cout << this->name << " has taken " << (int)amount << " damage!" << std::endl;
        this->hitPoint -= (int)amount;
    }

    if(this->hitPoint <= 0)
    {
        std::cout << this->name << " die..\n";
    }

}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->hitPoint <= 0)
        return;
    if(this->energyPoint <= 0)
    {
        std::cout << this->name << " cant heal itself because of energy!\n";
        return;
    }
    if(this->energyPoint > 0 && (int)amount >= 0)
    {
        std::cout << this->name << " has healed " << amount << " point\n";
        this->hitPoint += (int)amount;
        this->energyPoint -= 1;
    }
}
