/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:11:01 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/05 19:23:44 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include	<string>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints = 10;
		unsigned int	_energyPoints = 10;
		unsigned int	_attackDamage = 0;
	public:
		ClapTrap( void );
		ClapTrap( std::string name );
		~ClapTrap( void );
		ClapTrap&	operator=( ClapTrap& clap );
		void		attack( const std::string& target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );
};

std::ostream&	operator<<( std::ostream& out, ClapTrap& clap );

#endif
