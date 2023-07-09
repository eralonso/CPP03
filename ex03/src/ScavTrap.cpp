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

ScavTrap::ScavTrap( void ): ClapTrap( "Unnamed", ScavTrap::def_hpts, ScavTrap::def_epts, ScavTrap::def_admg )
{
	std::cout << "ScavTrap -> " << this->getName() << ": Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ): ClapTrap( name, ScavTrap::def_hpts, ScavTrap::def_epts, ScavTrap::def_admg )
{
	std::cout << "ScavTrap -> " << this->getName() << ": String constructor called" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& scav ): ClapTrap( scav )
{
	std::cout << "ScavTrap -> " << this->getName() << ": Copy constructor called" << std::endl;
	*this = scav;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap -> " << this->getName() << ": Destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& scav )
{
	std::cout << "SacvTrap -> " << scav.getName() << ": Assignation operator called" << std::endl;
	this->setName( scav.getName() );
	this->setHPts( scav.getHPts() );
	this->setEPts( scav.getEPts() );
	this->setADmg( scav.getADmg() );
	return ( *this );
}

void	ScavTrap::attack( const std::string& target )
{
	unsigned int	damage;

	std::cout << "ScavTrap -> " << this->getName() << ": ";
	if ( this->getEPts() < 1 )
		std::cout << "Not enough energy points to attack, at least 1.";
	else if ( this->getHPts() < 1 )
		std::cout << "Not enough hit points to attack, at least 1.";
	else
	{
		damage = this->getADmg();
		std::cout << "Hits " << target \
			<< ", causing " << damage << " points damage!";
		this->setEPts( this->getEPts() - 1 );
	}
	std::cout << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap -> " << this->getName() << ": Is now in Gate keeper mode" << std::endl;
}

std::ostream&	operator<<( std::ostream& out, ScavTrap& scav )
{
	out << "Name: " << scav.getName() << " Hit points: " << scav.getHPts() \
		<< " Energy Points: " << scav.getEPts() << " Attack Damage: " << scav.getADmg();
	return ( out );
}
