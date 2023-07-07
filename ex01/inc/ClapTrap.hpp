/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:11:01 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/07 13:53:33 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include	<string>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hPts;
		unsigned int	_ePts;
		unsigned int	_aDmg;
	public:
		ClapTrap( void );
		ClapTrap( ClapTrap& clap );
		ClapTrap( std::string name );
		~ClapTrap( void );
		ClapTrap&		operator=( ClapTrap& clap );
		void			attack( const std::string& target );
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );
		// Getters
		std::string		getName( void );
		unsigned int	getHPts( void );
		unsigned int	getEPts( void );
		unsigned int	getADmg( void );
		// Setters
		void			setName( std::string name );
		void			setHPts( unsigned int hPts );
		void			setEPts( unsigned int ePts );
		void			setADmg( unsigned int aDmg );
};

std::ostream&	operator<<( std::ostream& out, ClapTrap& clap );

#endif
