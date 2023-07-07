/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:37:03 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/07 13:41:39 by eralonso         ###   ########.fr       */
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
int	main( void )
{
	ClapTrap	clap1( "clap1" );
	ClapTrap	clap2( clap1 );

	clap2.setName( "clap2" );
	attacking( clap1, clap2 );
	attacking( clap2, clap1 );
	clap1.setADmg( 1 );
	attacking( clap1, clap2 );
	clap2.setADmg( 1 );
	attacking( clap2, clap1 );
	clap1.setADmg( 8 );
	attacking( clap1, clap2 );
	clap2.setADmg( 6 );
	clap1.beRepaired( 100 );
	clap2.beRepaired( 100 );
	attacking( clap2, clap1 );
	attacking( clap1, clap2 );
	attacking( clap2, clap1 );
	clap1.setADmg( 1 );
	clap2.setADmg( 1 );
	attacking( clap1, clap2 );
	attacking( clap2, clap1 );
	attacking( clap1, clap2 );
	attacking( clap2, clap1 );
	attacking( clap1, clap2 );
	attacking( clap2, clap1 );
	attacking( clap1, clap2 );
	attacking( clap2, clap1 );
	attacking( clap1, clap2 );
	attacking( clap2, clap1 );
	attacking( clap1, clap2 );
	attacking( clap2, clap1 );
	std::cout << "clap1 -> " << clap1 << std::endl;
	std::cout << "clap2 -> " << clap2 << std::endl;
	return ( 0 );
}
