/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:43:58 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/07 14:02:40 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include	"ClapTrap.hpp"
# include	<string>

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap& scav );
		~ScavTrap( void );
		ScavTrap&	operator=( ScavTrap& scav );
		void		guardGate( void );
};

#endif
