/*
** Skat.h for ex_0 in /home/pidoux_q/rendu/cpp/d08a/ex_0
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Jan 11 19:12:03 2011 quentin PIDOUX
** Last update Tue Jan 11 20:00:43 2011 quentin PIDOUX
*/

#ifndef _SKAT_H_
#define _SKAT_H_

class Skat
{
    public:
        Skat(std::string const& m_name, int stimPaks);
        ~Skat();

    public:
        void stimPaks();
        const std::string& name();

    public:
        void    shareStimPaks(int number, [...] stock);
        void    addStimPaks(unsigned int number);
        void    useStimPaks();

    public:
        void status();
	int _stimPaks;
    private:
        [...]
};
