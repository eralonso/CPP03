/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:46:50 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/07 14:02:25 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	"ScavTrap.hpp"

ScavTrap::ScavTrap( void ): ClapTrap(NULL)
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	this->_hPts = 100;
	this->_ePts = 50;
	this->_aDmg = 20;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap(name)
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	this->_hPts = 100;
	this->_ePts = 50;
	this->_aDmg = 20;
}

ScavTrap::ScavTrap( ScavTrap& scav )
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
	*this = scav;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap: Default destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=( ScavTrap& scav )
{
	std::cout << "SacvTrap: Assignation operator called" << std::endl;
	this->_name = scav.getName();
	this->_hPts = scav.getHPts();
	this->_ePts = scav.getEPts();
	this->_aDmg = scav.getADmg();
	return ( *this );
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap: " << this->_name << " is now in Gate keeper mode" << std::endl;
}
