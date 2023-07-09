/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:03 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/09 13:53:50 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<iomanip>
#include	"ClapTrap.hpp"

#define FILL	40

void	attacking( ClapTrap& clap1, ClapTrap& clap2 )
{
	bool	canAttack;

	canAttack = clap1.getEPts() < 1 ? false : true;
	clap1.attack( clap2.getName() );
	if ( canAttack == true )
		clap2.takeDamage( clap1.getADmg() );
}

void	war( ClapTrap& one, ClapTrap& two, int times )
{
	for ( int i = 0; i < times; i++ )
	{
		attacking( one, two );
		attacking( two, one );
	}
}

void	test( ClapTrap& one, ClapTrap& two, bool change_dmg )
{
	war( one, two, 1 );
	if ( change_dmg == true )
		one.setADmg( 1 );
	attacking( one, two );
	if ( change_dmg == true )
		two.setADmg( 1 );
	attacking( two, one );
	if ( change_dmg == true )
		one.setADmg( 8 );
	attacking( one, two );
	if ( change_dmg == true )
		two.setADmg( 6 );
	std::cout << std::endl;
	one.beRepaired( one.getADmg() * 10 );
	two.beRepaired( one.getADmg() * 10 );
	std::cout << std::endl;
	attacking( two, one );
	war( one, two, 1 );
	if ( change_dmg == true )
	{
		one.setADmg( 1 );
		two.setADmg( 1 );
	}
	war( one, two, 6 );
	std::cout << "\none -> " << one << std::endl;
	std::cout << "two -> " << two << std::endl;
}

void	print_next_test( std::string msg )
{
	int	fill;
	int	odd;

	fill = ( FILL - msg.length() ) / 2;
	odd = msg.length() % 2;
	std::cout << "\n " << std::setfill('_') << std::setw(FILL - 1) << "" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw( fill + odd ) << "" << msg << std::setw( fill ) << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
	std::cout << "|" << std::setfill('_') << std::setw(FILL + 1) << "|\n" << std::endl;
}

void	test_clap( void )
{
	ClapTrap	clap1( "clap1" );
	ClapTrap	clap2( clap1 );

	clap2.setName( "clap2" );
	std::cout << "\none -> " << clap1 << std::endl;
	std::cout << "two -> " << clap2 << "\n" << std::endl;
	test( clap1, clap2, true );
	std::cout << std::endl;
}

int	main( void )
{
	print_next_test( "ClapTrap test" );
	test_clap();

	return ( 0 );
}
