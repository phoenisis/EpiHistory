#ifndef _EX_min1_H_
#define _EX_min1_H_

typedef struct s_cthulhu
{
  int m_power;
  char * m_name;
}t_cthulhu;

typedef struct s_koala
{
  t_cthulhu m_parent;
  char      m_isALegend;
 }t_koala;

void	        Eat(t_koala* this);
t_koala*	NewKoala(char* name, char _isALegend);
t_cthulhu*	NewCthulhu();
void            PrintPower(t_cthulhu* this);
void            Attack(t_cthulhu* this);
void            Sleeping(t_cthulhu* this);
#endif
