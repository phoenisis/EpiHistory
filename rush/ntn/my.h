/*
** my.h for my.h in /u/all/lorill_a/cu/rendu/ntn/version
** 
** Made by anthony lorillon
** Login   <lorill_a@epitech.net>
** 
** Started on  Sun Dec  7 15:34:32 2008 anthony lorillon
** Last update Sun Dec  7 16:28:44 2008 anthony lorillon
*/

#ifndef __MY_H__
#define __MY_H__


void	cent(char *str, int j);
void	dix(char str);
void	dix2(char *str);
void	dix22(char *str);
int	dix1(char *str, int j);
void	huitdix(char *str);
void	sixdix(char *str);
void	mille(char *str, int j);
void	mille2(char *str, int j);
void	mille3(char *str, int j);
void	million(char str);
void	my_putchar(char c);
int	ntn(char *str);
int	except(int j, char *str, int d);
int	space(int j, char *str, int d);
int	unity(char str);
int	my_putstr(char *str);
int	my_put_nbr(int n);
int	my_strlen(char *str);
int	main(int argc, char **argv);

#endif
