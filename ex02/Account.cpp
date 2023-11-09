/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:39:14 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/09 10:54:12 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

static int	sb_increment_date(int *v1, int max)
{
	if (*v1 >= max)
	{
		*v1 = *v1 - max;
		return 1;
	}
	return 0;
}

static int	sb_calculate_month(int old_mon, int *day, int year)
{
	int		limit;
	bool	isLeapYear;

	// check leap year
	isLeapYear = false;
	if (year % 100 == 0)
	{
		isLeapYear = (year % 400 == 0);
	}
	else if (year % 4 == 0)
	{
		isLeapYear = true;
	}

	// find month limit
	if (old_mon == 2)
	{
		limit = isLeapYear ? 28:29;
	}
	else if (old_mon == 4 || old_mon == 6 || old_mon == 9 || old_mon == 11)
	{
		limit = 30;
	}
	else
	{
		limit = 31;
	}

	// check if day more than limit
	if (*day > limit)
	{
		*day = 1;
		return old_mon + 1;
	}
	return old_mon;
}

static void	sb_full_print(int val)
{
	if (val < 10)
		std::cout << "0";
	std::cout << val;
}

void	Account::_displayTimestamp()
{
	std::tm			*gtm;
	std::time_t		now;
	int				year;
	int				month;
	int				day;
	int				hour;
	int				minute;
	int				second;

	// Calculate time unit
	now = std::time(NULL);
	gtm = gmtime(&now);
	second = gtm->tm_sec;
	minute = gtm->tm_min + sb_increment_date(&second, 60);
	hour = gtm->tm_hour + sb_increment_date(&minute, 60);
	day = gtm->tm_mday + sb_increment_date(&hour, 24);
	month = sb_calculate_month(gtm->tm_mon + 1, &day, gtm->tm_year);
	year = 1900 + gtm->tm_year + sb_increment_date(&month, 12);

	// Print timestamp
	std::cout << "[" << year;
	sb_full_print(month);
	sb_full_print(day);
	std::cout << "_";
	sb_full_print(hour);
	sb_full_print(minute);
	sb_full_print(second);
	std::cout << "]";
}

int	Account::getNbAccounts()
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount()
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits()
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals()
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::_amount << ";";
	std::cout << "deposit:" << deposit << ";";

	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_nbDeposits++;
	Account::_totalNbDeposits++;
	
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "nb_deposits:" << Account::_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "p_amount:" << Account::_amount << ";";
	std::cout << "withdrawal:";

	if (withdrawal <= 0 || Account::_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return false;
	}

	Account::_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_nbWithdrawals++;
	Account::_totalNbWithdrawals++;

	std::cout << withdrawal << ";" << "amount:" << Account::_amount << ";";
	std::cout << "nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
	return true;
}

int	Account::checkAmount() const
{
	return Account::_amount;
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << Account::_amount << ";";
	std::cout << "deposits:" << Account::_nbDeposits << ";";
	std::cout << "withdrawals:" << Account::_nbWithdrawals << std::endl;
}

Account::Account()
{
}

Account::Account(int initial_deposit)
{
	Account::_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "amount:" << initial_deposit <<  ";" << "created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex << ";";
	std::cout << "amount:" <<  Account::_amount <<  ";" << "closed" << std::endl;
}