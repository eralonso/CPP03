/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:51:24 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/09 10:58:30 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap( "Unnamed", FragTrap::def_hpts, FragTrap::def_epts, FragTrap::def_admg )
{
	std::cout << "FragTrap -> " << this->getName() << ": Default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ): ClapTrap( name, FragTrap::def_hpts, FragTrap::def_epts, FragTrap::def_admg )
{
	std::cout << "FragTrap -> " << this->getName() << ": String constructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& frag ): ClapTrap( frag )
{
	std::cout << "FragTrap -> " << frag.getName() << ": Copy constructor called" << std::endl;
	*this = frag;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap -> " << this->getName() << ": Destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=( const FragTrap& frag )
{
	std::cout << "FragTrap -> " << frag.getName() << ": Assignation operator called" << std::endl;
	this->setName( frag.getName() );
	this->setHPts( frag.getHPts() );
	this->setEPts( frag.getEPts() );
	this->setADmg( frag.getADmg() );
	return ( *this );
}

void	FragTrap::highFivesGuys( void )
{
	std::string	unused;

	std::cout << "FragTrap -> " << this->getName() << ": Hey guys, High five" << std::endl;
	std::getline(std::cin, unused);
}

std::ostream&	operator<<( std::ostream& out, FragTrap& frag )
{
	out << "Name: " << frag.getName() << " Hit points: " << frag.getHPts() \
		<< " Energy Points: " << frag.getEPts() << " Attack Damage: " << frag.getADmg();
	return ( out );
}
