/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:10:59 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/07 13:36:28 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ClapTrap.hpp"
#include	<iostream>

ClapTrap::ClapTrap( void ): _name( NULL ), _hPts( 10 ), _ePts( 10 ), _aDmg( 0 )
{
	std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap& clap )
{
	std::cout << "ClapTrap: Copy constructor called" << std::endl;
	*this = clap;
}

ClapTrap::ClapTrap( std::string name ): _name( name ), _hPts( 10 ), \
	_ePts( 10 ), _aDmg( 0 )
{
	std::cout << "ClapTrap: String constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap: Destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=( ClapTrap& clap )
{
	std::cout << "Assignation operator called" << std::endl;
	this->_name = clap.getName();
	this->_hPts = clap.getHPts();
	this->_ePts = clap.getEPts();
	this->_aDmg = clap.getADmg();
	return ( *this );
}

void	ClapTrap::attack( const std::string& target )
{
	unsigned int	damage;

	std::cout << "ClapTrap: " << this->_name;
	if ( this->_ePts < 1 )
		std::cout << " not enough energy points to attack, at least 1.";
	else if ( this->_hPts < 1 )
		std::cout << " not enough hit points to attack, at least 1.";
	else
	{
		damage = this->_aDmg;
		if (damage > 10)
			damage = 10;
		std::cout << " attacks " << target \
			<< ", causing " << damage << " points damage!";
		this->_ePts--;
	}
	std::cout << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << "ClapTrap: " << this->_name;
	if ( this->_ePts < 1 )
		std::cout << " not enough energy points to reapir, at least 1.";
	else if ( this->_hPts < 1 )
		std::cout << " not enough hit points to attack, at least 1.";
	else if ( amount + this->_hPts >= this->_hPts )
	{
		std::cout << " be repaired with " << amount << " hit points. Hit points remaining == ";
		this->_hPts += amount;
		this->_ePts--;
		std::cout << this->_hPts;
	}
	else
		std::cout << " too many hit points to be repaired";
	std::cout << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << "ClapTrap: " << this->_name;
	if ( this->_hPts < 1 )
		std::cout << " cannot take more damage. Hit points == " << this->_hPts;
	else if ( this->_hPts  - amount <= this->_hPts )
	{
		std::cout << " take " << amount << " damage. Hit points remaining == ";
		this->_hPts -= amount;
		std::cout << this->_hPts;
	}
	else
		std::cout << " too many hit points to take damage";		
	std::cout << std::endl;
}

std::string	ClapTrap::getName( void )
{
	return ( this->_name );
}

unsigned int	ClapTrap::getHPts( void )
{
	return ( this->_hPts );
}

unsigned int	ClapTrap::getEPts( void )
{
	return ( this->_ePts );
}

unsigned int	ClapTrap::getADmg( void )
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
