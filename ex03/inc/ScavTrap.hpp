/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:43:58 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/09 10:41:56 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include	"ClapTrap.hpp"
# include	<string>
# include	<iostream>

class ScavTrap: virtual public ClapTrap
{
	protected:
		static const int	def_hpts = 100;
		static const int	def_epts = 50;
		static const int	def_admg = 20;
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& scav );
		~ScavTrap( void );
		ScavTrap&	operator=( const ScavTrap& scav );
		void		guardGate( void );
		void		attack( const std::string& target );
};

std::ostream&	operator<<( std::ostream& out, ScavTrap& scav );

#endif
