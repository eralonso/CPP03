/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:11:01 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/09 13:58:26 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include	<string>
# include	<iostream>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hPts;
		unsigned int	_ePts;
		unsigned int	_aDmg;
	public:
		ClapTrap( void );
		ClapTrap( const ClapTrap& clap );
		ClapTrap( std::string name );
		ClapTrap( std::string name, unsigned int hPts, unsigned int ePts, \
			unsigned int aDmg );
		~ClapTrap( void );
		ClapTrap&				operator=( const ClapTrap& clap );
		virtual void			attack( const std::string& target );
		void					takeDamage( unsigned int amount );
		void					beRepaired( unsigned int amount );
		// Getters
		std::string				getName( void ) const;
		unsigned int			getHPts( void ) const;
		unsigned int			getEPts( void ) const;
		unsigned int			getADmg( void ) const;
		// Setters
		void					setName( std::string name );
		void					setHPts( unsigned int hPts );
		void					setEPts( unsigned int ePts );
		void					setADmg( unsigned int aDmg );
};

std::ostream&	operator<<( std::ostream& out, ClapTrap& clap );

#endif
