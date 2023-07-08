/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:43:58 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/08 13:09:52 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include	"ClapTrap.hpp"
# include	<string>
# include	<iostream>

class ScavTrap: public ClapTrap
{
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
