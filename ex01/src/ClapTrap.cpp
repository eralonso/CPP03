/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:10:59 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/09 13:48:34 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ClapTrap.hpp"
#include	<iostream>

ClapTrap::ClapTrap( void ): _name( "Unnamed" ), _hPts( 10 ), _ePts( 10 ), _aDmg( 0 )
{
	std::cout << "ClapTrap -> " << this->getName() << ": Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& clap )
{
	std::cout << "ClapTrap -> " << clap.getName() << ": Copy constructor called" << std::endl;
	*this = clap;
}

ClapTrap::ClapTrap( std::string name, unsigned int hPts, unsigned int ePts, \
	unsigned int aDmg ): _name( name ), _hPts( hPts ), _ePts( ePts ), _aDmg( aDmg )
{
	std::cout << "ClapTrap -> " << this->getName() << ": All parameters constructor " << std::endl;
}

ClapTrap::ClapTrap( std::string name ): _name( name ), _hPts( 10 ), \
	_ePts( 10 ), _aDmg( 0 )
{
	std::cout << "ClapTrap -> " << this->getName() << ": String constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap -> " << this->getName() << ": Destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& clap )
{
	std::cout << "ClapTrap -> " << clap.getName() << ": Assignation operator called" << std::endl;
	this->setName( clap.getName() );
	this->setHPts( clap.getHPts() );
	this->setEPts( clap.getEPts() );
	this->setADmg( clap.getADmg() );
	return ( *this );
}

void	ClapTrap::attack( const std::string& target )
{
	unsigned int	damage;

	std::cout << "ClapTrap -> " << this->getName() << ": ";
	if ( this->getEPts() < 1 )
		std::cout << "Not enough energy points to attack, at least 1.";
	else if ( this->getHPts() < 1 )
		std::cout << "Not enough hit points to attack, at least 1.";
	else
	{
		damage = this->getADmg();
		std::cout << "Attacks " << target \
			<< ", causing " << damage << " points damage!";
		this->setEPts( this->getEPts() - 1 );
	}
	std::cout << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << "ClapTrap -> " << this->getName() << ": ";
	if ( this->getEPts() < 1 )
		std::cout << "Not enough energy points to reapir, at least 1.";
	else if ( this->getHPts() < 1 )
		std::cout << "Not enough hit points to attack, at least 1.";
	else if ( amount + this->getHPts() >= this->getHPts() )
	{
		std::cout << "Be repaired with " << amount << " hit points. Hit points remaining == ";
		this->setHPts( this->getHPts() + amount );
		this->setEPts( this->getEPts() - 1 );
		std::cout << this->getHPts();
	}
	else
		std::cout << "Too many hit points to be repaired";
	std::cout << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap -> " << this->getName() << ": ";
	if ( this->getHPts() < 1 )
		std::cout << "Cannot take more damage. Hit points == " << this->getHPts();
	else if ( this->getHPts()  - amount <= this->getHPts() )
	{
		std::cout << "Take " << amount << " damage. Hit points remaining == ";
		this->setHPts( this->getHPts() - amount );
		std::cout << this->getHPts();
	}
	else
		std::cout << "Too many hit points to take damage";		
	std::cout << std::endl;
}

std::string	ClapTrap::getName( void ) const
{
	return ( this->_name );
}

unsigned int	ClapTrap::getHPts( void ) const
{
	return ( this->_hPts );
}

unsigned int	ClapTrap::getEPts( void ) const
{
	return ( this->_ePts );
}

unsigned int	ClapTrap::getADmg( void ) const
{
	return ( this->_aDmg );
}

void	ClapTrap::setName( std::string name )
{
	this->_name = name;
}

void	ClapTrap::setHPts( unsigned int hPts )
{
	this->_hPts = hPts;
}

void	ClapTrap::setEPts( unsigned int ePts )
{
	this->_ePts = ePts;
}

void	ClapTrap::setADmg( unsigned int aDmg )
{
	this->_aDmg = aDmg;
}

std::ostream&	operator<<( std::ostream& out, ClapTrap& clap )
{
	out << "Name: " << clap.getName() << " Hit points: " << clap.getHPts() \
		<< " Energy Points: " << clap.getEPts() << " Attack Damage: " << clap.getADmg();
	return ( out );
}
