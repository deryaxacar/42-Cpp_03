/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:41:19 by deryacar          #+#    #+#             */
/*   Updated: 2024/09/25 18:41:19 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->setVar(name,100,100,30);
    std::cout << this->getName() << ": FragTrap Constructor call\n";
}
FragTrap::~FragTrap()
{
    std::cout << this->getName() << ": FragTrap Destructor call\n";
}
void FragTrap::highFivesGuys(void)
{
    if(this->getHitPoint() <= 0)
        return;
    std::cout << this->getName() << ": GİVE ME A FİVER, MAN!\n";
}