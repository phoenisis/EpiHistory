# include <iostream>
# include <exception>
# include <assert.h>
# include "Assert.hpp"

namespace gdl
{
  void	Assert(bool condition, const std::string& msg)
  {
#if DEBUG
    if (condition)
      return;
    std::cerr << msg << std::endl;
    assert(false);
#endif /* DEBUG */    
  }
}

// AssertException::AssertException(const std::string& _what)
//   : m_what(_what)
// {
// }

// const char*	AssertException::what()	const throw()
// {
//   return m_what.c_str();
// }

// void	AssertException::Assert(bool expression, const std::string& msg) throw(AssertException)
// {
// #if DEBUG
//   std::cerr << msg << std::endl;
//   assert(false);
// //   if (!expression)
// //     throw AssertException(msg);

// #endif /* DEBUG */
// }
