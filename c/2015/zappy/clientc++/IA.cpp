#include "player.hh"

void		doAction(void *i)
{
  player	*me = (player*) i;
  std::string	str;

  while (42)
    {
      me->getSocket()->client.setBlocking(false);
      str = me->getSocket()->recieveMessage();
      if (str.find("message") != std::string::npos)
	// check_message(str);
	;
      else if (str.find("mort") != std::string::npos)
	me->death();
      else if (str.compare("disconnect") == 0)
	break;
    }
}

void		runIA(std::string host, std::string port, std::string teamname)
{
  player	me;
  pid_t		pid;
  bool		connected = false;
  std::string	str;
  int		nb_connect = 0;

  pid = getpid();
  me.setSocket(host, port);
  if (me.getSocket()->tryConnect() == false)
    return;
  else
    {
      str = me.getSocket()->recieveMessage();
      if (str.compare(0, 10,"BIENVENUE\n") == 0)
	{
	  me.getSocket()->sendMessage(teamname);
	  str = me.getSocket()->recieveMessage();
	  str = me.getSocket()->recieveMessage();
	  std::cout << str << std::endl;
	}
    }
  while (me.getAlive())
    {
      if (pid != 0)
      	{
      	  if (me.connect_nbr() > 0)
      	    pid = fork();
      	  // fork pour nouveau joueur
	  if (me.getLifetime() > 1500 && nb_connect <= 7)
	    {
	      if (me.fork())
		nb_connect++;
	    }

      	}
      if (pid == 0 && connected == false)
      	{
      	  me.setSocket(host, port);
      	  if (me.getSocket()->tryConnect() == false)
      	    return;
      	  else
      	    {
      	      str = me.getSocket()->recieveMessage();
      	      if (str.compare(0, 10, "BIENVENUE\n") == 0)
      		{
      		  me.getSocket()->sendMessage(teamname);
      		  str = me.getSocket()->recieveMessage();
      		  str = me.getSocket()->recieveMessage();
      		}
      	    }
      	  // connection
      	  connected = true;
      	}
      if (me.getLifetime() > 5000 && me.getHungry() == true)
	me.setHungry(false);
      if (me.getLifetime() < 1600 && me.getHungry() == false) //j'ai tres faim
	me.setHungry(true);
      else
	{
	  if (false) // j'ai de quoi faire une elevation
	    {
	      // regroupement pour elevation si besoin sinon elevation
	    }
	  else
	    {
	      if (me.getToGet().ress.compare("") != 0 && me.getToGet().vect.first == 0 && me.getToGet().vect.second == 0) // je suis sur une case a ressource
		{
		  me.take();
		  // je rammasse
		}
	      else
		{
		  if (me.getToGet().ress.compare("") != 0) // j'ai trouver une ressource
		    {
		      if (me.getToGet().vect.first > 0)
			{
			  if (me.forward())
			    me.getToGet().vect.first--;
			}
		      else if (me.getToGet().vect.second > 0)
			{
			  me.left();
			  me.getToGet().vect.first = me.getToGet().vect.second;
			  me.getToGet().vect.second = 0;
			}
		      else if (me.getToGet().vect.second < 0)
			{
			  me.right();
			  me.getToGet().vect.first = - me.getToGet().vect.second;
			  me.getToGet().vect.second = 0;
			}
		      //goto case
		    }
		  else
		    {
		      if (me.getToMove() > 0) //j'ai regarder et pas assez avance
			{
			  if (me.forward())// j'avance
			    me.setToMove(me.getToMove() - 1);
			}
		      else
			{
			  me.watch();
			  me.setToMove(me.getLvl());
			  // je regade
			}
		    }
		}
	    }
	}
      if (me.getLifetime() < 0)
	{
	  me.death();
	  std::cout << "mort" << std::endl;
	}
    }
}
