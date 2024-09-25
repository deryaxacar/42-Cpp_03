/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:42:45 by deryacar          #+#    #+#             */
/*   Updated: 2024/09/25 18:42:45 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap b("Derya : ");
    ScavTrap a("Mert : ");
    b.attack("one");
    b.takeDamage(10);
    b.beRepaired(10);

    std::cout << "------------------------" << std::endl;
    
    a.attack("two");
    a.takeDamage(10);
    a.beRepaired(10);
    a.guardGate();
}