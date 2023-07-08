/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:03 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/08 15:04:28 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ClapTrap.hpp"
#include	"ScavTrap.hpp"
#include	<iostream>
#include	<iomanip>

#define FILL	40

void	attacking( ClapTrap& clap1, ClapTrap& clap2 )
{
	bool	canAttack;

	canAttack = clap1.getEPts() < 1 ? false : true;
	clap1.attack( clap2.getName() );
	if ( canAttack == true )
		clap2.takeDamage( clap1.getADmg() );
}

void	test_clap( ClapTrap& one, ClapTrap& two )
{
	attacking( one, two );
	attacking( two, one );
	one.setADmg( 1 );
	attacking( one, two );
	two.setADmg( 1 );
	attacking( two, one );
	one.setADmg( 8 );
	attacking( one, two );
	two.setADmg( 6 );
	std::cout << std::endl;
	one.beRepaired( 100 );
	two.beRepaired( 100 );
	std::cout << std::endl;
	attacking( two, one );
	attacking( one, two );
	attacking( two, one );
	one.setADmg( 1 );
	two.setADmg( 1 );
	attacking( one, two );
	attacking( two, one );
	attacking( one, two );
	attacking( two, one );
	attacking( one, two );
	attacking( two, one );
	attacking( one, two );
	attacking( two, one );
	attacking( one, two );
	attacking( two, one );
	attacking( one, two );
	attacking( two, one );
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

void	test_scav( ScavTrap& one, ScavTrap& two )
{
	test_clap( one, two );
	std::cout << std::endl;
	one.guardGate();
	two.guardGate();
}

int	main( void )
{
	ClapTrap	clap1( "clap1" );
	ClapTrap	clap2( clap1 );
	ScavTrap	scav1;
	ScavTrap	scav2( "scav2" );

	clap2.setName( "clap2" );
	scav1 = scav2;
	scav1.setName( "scav1" );
	print_next_test( "ClapTrap test" );
	test_clap( clap1, clap2 );
	print_next_test( "ScravTrap test" );
	test_scav( scav1, scav2 );
	std::cout << std::endl;
	return ( 0 );
}
