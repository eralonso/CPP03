/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eralonso <eralonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:36:43 by eralonso          #+#    #+#             */
/*   Updated: 2023/07/09 10:41:33 by eralonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_H__
# define __FRAGTRAP_H__

# include	<iostream>
# include	<string>
# include	"ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	protected:
		static const int	def_hpts = 100;
		static const int	def_epts = 100;
		static const int	def_admg = 30;
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap& frag );
		~FragTrap( void );
		FragTrap&	operator=( const FragTrap& frag );
		void		highFivesGuys( void );
};

std::ostream&	operator<<( std::ostream& out, FragTrap& frag );

#endif
