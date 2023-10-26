/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:35:21 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/27 03:27:43 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "HumanB.hpp"

class HumanA
{
	private:
		std::string			name;
		const std::string	&rwpon;

	public:
		HumanA(std::string name, Weapon &etc);
		void	attack();
};

#endif