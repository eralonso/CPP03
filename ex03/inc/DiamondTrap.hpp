/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:48:38 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/08 17:37:54 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_H__
# define __DIAMONDTRAP_H__

# include	<iostream>
# include	<string>
# include	"ScavTrap.hpp"
# include	"FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap& diamond );
		~DiamondTrap( void );
		DiamondTrap&	operator=( const DiamondTrap& diamond );
		void			whoAmI( void );
		std::string		getName( void ) const;
		std::string		getClapTrapName( void ) const;
		void			setName( std::string name );
		void			setClapTrapName( std::string name );
};

std::ostream&	operator<<( std::ostream& out, DiamondTrap& diamond );

#endif
