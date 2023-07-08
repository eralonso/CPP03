/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:03 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/08 17:43:44 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<iostream>
#include	<iomanip>
#include	"ClapTrap.hpp"
#include	"ScavTrap.hpp"
#include	"FragTrap.hpp"
#include	"DiamondTrap.hpp"

#define FILL	40

void	attacking( ClapTrap& clap1, ClapTrap& clap2 )
{
	bool	canAttack;

	canAttack = clap1.getEPts() < 1 ? false : true;
	clap1.attack( clap2.getName() );
	if ( canAttack == true )
		clap2.takeDamage( clap1.getADmg() );
}

void	test_clap( ClapTrap& one, ClapTrap& two, bool change_dmg )
{
	attacking( one, two );
	attacking( two, one );
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
	attacking( one, two );
	attacking( two, one );
	if ( change_dmg == true )
	{
		one.setADmg( 1 );
		two.setADmg( 1 );
	}
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
	test_clap( one, two, false );
	std::cout << std::endl;
	one.guardGate();
	two.guardGate();
}

void	test_frag( FragTrap& one, FragTrap& two )
{
	test_clap( one, two, false );
	std::cout << std::endl;
	one.highFivesGuys();
	two.highFivesGuys();
}

void	test_diamond( DiamondTrap& one, DiamondTrap& two )
{
	std::cout << "\none -> " << one << std::endl;
	std::cout << "two -> " << two << "\n" << std::endl;
	test_clap( one, two, false );
	std::cout << std::endl;
	one.whoAmI();
	two.whoAmI();
}

int	main( void )
{
	print_next_test( "ClapTrap test" );
	ClapTrap	clap1( "clap1" );
	ClapTrap	clap2( clap1 );

	clap2.setName( "clap2" );
	test_clap( clap1, clap2, true );



	print_next_test( "ScravTrap test" );
	ScavTrap	scav1;
	ScavTrap	scav2( "scav2" );

	scav1 = scav2;
	scav1.setName( "scav1" );
	test_scav( scav1, scav2 );



	print_next_test( "FragTrap test" );
	FragTrap	frag1( "frag1" );
	FragTrap	frag2;

	frag2 = frag1;
	frag2.setName( "frag2" );
	test_frag( frag1, frag2 );



	print_next_test( "DiamondTrap test" );
	DiamondTrap	diamond1( "diamond1" );
	DiamondTrap	diamond2( "diamond2" );

	test_diamond( diamond1, diamond2 );

	std::cout << std::endl;
	return ( 0 );
}
