/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:42:03 by deryacar          #+#    #+#             */
/*   Updated: 2024/09/25 18:42:03 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    FragTrap a("Derya");
    FragTrap b("Mert");
    
    b.attack("FİRE!");
    b.takeDamage(10);
    b.beRepaired(1000);

    b.highFivesGuys();
    a.highFivesGuys();
}
