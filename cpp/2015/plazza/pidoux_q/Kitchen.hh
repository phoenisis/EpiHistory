#ifndef kitchen_hh_
# define kitchen_hh_
# include "pipe.hh"
# include "Thread.hh"

class Kitchen
{
public:
  Kitchen(const int);
  ~Kitchen();
  bool get_cooker_status();
  void send_msg(const std::string);
  std::string listen_pipe();
private:
  pipe &p;
  std::map<std::string, int> food;
  std::map<int, >  cooker;
  int id;
};

#endif
