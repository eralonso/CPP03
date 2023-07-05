/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:10:59 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/05 19:24:33 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ClapTrap.hpp"
#include	<iostream>

ClapTrap::ClapTrap( void ): _name(NULL)
{
	std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ): _name(name)
{
	std::cout << "ClapTrap: String constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap: Destructor called" << std::endl;
}

void	ClapTrap::attack( const std::string& target )
{
	std::cout << "ClapTrap: " << this->_name << " attacks " << target \
		<< ", causing " << this->_attackDamage << " points damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << "ClapTrap: " << this->_name << " repaired " << amount \
		<< ", causing " << this->_hitPoints << " points damage!" << std::endl;
	this->_energyPoints--;
}
