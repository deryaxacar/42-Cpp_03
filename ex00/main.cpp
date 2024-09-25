/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:55:43 by deryacar          #+#    #+#             */
/*   Updated: 2024/09/25 14:55:43 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("Derya");
	clapTrap.attack("Character");
	clapTrap.takeDamage(7);
	clapTrap.beRepaired(5);
	return 0;
}