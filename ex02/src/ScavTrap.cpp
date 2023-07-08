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

ScavTrap::ScavTrap( void ): ClapTrap("unnamed", 100, 50, 20)
{
	std::cout << "ScavTrap -> " << this->_name << ": Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap -> " << this->_name << ": Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& scav )
{
	std::cout << "ScavTrap -> " << this->_name << ": Copy constructor called" << std::endl;
	*this = scav;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap -> " << this->_name << ": Default destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& scav )
{
	std::cout << "SacvTrap -> " << this->_name << ": Assignation operator called" << std::endl;
	this->_name = scav.getName();
	this->_hPts = scav.getHPts();
	this->_ePts = scav.getEPts();
	this->_aDmg = scav.getADmg();
	return ( *this );
}

void	ScavTrap::attack( const std::string& target )
{
	unsigned int	damage;

	std::cout << "ScavTrap: " << this->_name;
	if ( this->_ePts < 1 )
		std::cout << " not enough energy points to attack, at least 1.";
	else if ( this->_hPts < 1 )
		std::cout << " not enough hit points to attack, at least 1.";
	else
	{
		damage = this->_aDmg;
		if (damage > 10)
			damage = 10;
		std::cout << " hits " << target \
			<< ", causing " << damage << " points damage!";
		this->_ePts--;
	}
	std::cout << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap: " << this->_name << " is now in Gate keeper mode" << std::endl;
}

std::ostream&	operator<<( std::ostream& out, ScavTrap& scav )
{
	out << "Name: " << scav.getName() << " Hit points: " << scav.getHPts() \
		<< " Energy Points: " << scav.getEPts() << " Attack Damage: " << scav.getADmg();
	return ( out );
}
