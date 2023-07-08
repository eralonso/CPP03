/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:03 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/08 13:15:23 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ClapTrap.hpp"
#include	<iostream>

void	attacking( ClapTrap& clap1, ClapTrap& clap2 )
{
	bool	canAttack;

	canAttack = clap1.getEPts() < 1 ? false : true;
	clap1.attack( clap2.getName() );
	if ( canAttack == true )
		clap2.takeDamage( clap1.getADmg() );
}

void	test( ClapTrap& one, ClapTrap& two )
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
	one.beRepaired( 100 );
	two.beRepaired( 100 );
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
	std::cout << "one -> " << one << std::endl;
	std::cout << "two -> " << two << std::endl;
}

int	main( void )
{
	ClapTrap	clap1( "clap1" );
	ClapTrap	clap2( clap1 );

	clap2.setName( "clap2" );
	test(clap1, clap2);
	return ( 0 );
}
