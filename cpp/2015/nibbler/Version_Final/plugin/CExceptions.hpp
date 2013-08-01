
#ifndef		__CEXCEPTIONS_HPP__
# define	__CEXCEPTIONS_HPP__

#include <exception>
#include <string>

class		CExceptions : public	std::exception
{
public:
  CExceptions(void);
  CExceptions(std::string const &);
  CExceptions(CExceptions const &);
  ~CExceptions(void) throw();

public:
  CExceptions			&operator=(CExceptions const &);
  virtual const char	*what(void) const throw();

private:
  std::string			_msg;
};

class		CError : public			CExceptions
{
public:
  CError(std::string const &msg)
    : CExceptions(msg) {}
};

#endif		// !__CEXCEPTIONS_HPP__
