#ifndef		__MEMBERFUNCTION_H__
# define	__MEMBERFUNCTION_H__
# include	"IFunction.h"

namespace	Function
{
	namespace detail
	{
#ifndef __CALL_MEM_FN__
#define __CALL_MEM_FN__
#define CALL_FN(object, func) ((object)->*(func))
#endif
		template<typename Ret, typename Obj>
		class		MemberFunction0 : public IFunction<Ret>
		{
		public:
		  MemberFunction0(Ret (Obj::*f)(), Obj * o) : _func(f), _o(o) {};
		  Ret			operator()()
		  {
			return (CALL_FN(this->_o, this->_func)());
		  }
		  virtual Ret	exec()
		  {
			return (CALL_FN(this->_o, this->_func)());
		  }
		private:
		  Ret		(Obj::*_func)();
		  Obj *		_o;
		};

		template<typename Ret, typename Obj, typename Arg1>
		class		MemberFunction1 : public IFunction<Ret (Arg1)>
		{
		public:
		  MemberFunction1(Ret (Obj::*f)(Arg1), Obj *o) : _func(f), _o(o) {};
		  Ret			operator()(Arg1 arg1)
		  {
			return (CALL_FN(this->_o, this->_func)(arg1));
		  }
		  virtual Ret	exec(Arg1 arg1)
		  {
			return (CALL_FN(this->_o, this->_func)(arg1));
		  }
		private:
		  Ret		(Obj::*_func)(Arg1);
		  Obj *		_o;
		};

		template<typename Ret, typename Obj, typename Arg1, typename Arg2>
		class		MemberFunction2 : public IFunction<Ret (Arg1, Arg2)>
		{
		public:
		  MemberFunction2(Ret (Obj::*f)(Arg1, Arg2), Obj * o) : _func(f), _o(o) {};
		  Ret			operator()(Arg1 arg1, Arg2 arg2)
		  {
			return (CALL_FN(this->_o, this->_func)(arg1, arg2));
		  }
		  virtual Ret	exec(Arg1 arg1, Arg2 arg2)
		  {
			return (CALL_FN(this->_o, this->_func)(arg1, arg2));
		  }
		private:
		  Ret		(Obj::*_func)(Arg1, Arg2);
		  Obj *		_o;
		};

		template<typename Ret, typename Obj, typename Arg1, typename Arg2, typename Arg3>
		class		MemberFunction3 : public IFunction<Ret (Arg1, Arg2, Arg3)>
		{
		public:
		  MemberFunction3(Ret (Obj::*f)(Arg1, Arg2, Arg3), Obj * o) : _func(f), _o(o) {};
		  Ret			operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3)
		  {
			return (CALL_FN(this->_o, this->_func)(arg1, arg2, arg3));
		  }
		  virtual Ret	exec(Arg1 arg1, Arg2 arg2, Arg3 arg3)
		  {
			return (CALL_FN(this->_o, this->_func)(arg1, arg2, arg3));
		  }
		private:
		  Ret		(Obj::*_func)(Arg1, Arg2, Arg3);
		  Obj *		_o;
		};

		template<typename Ret, typename Obj, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class		MemberFunction4 : public IFunction<Ret (Arg1, Arg2, Arg3, Arg4)>
		{
		public:
		  MemberFunction4(Ret (Obj::*f)(Arg1, Arg2, Arg3, Arg4), Obj * o) : _func(f), _o(o) {};
		  Ret			operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4)
		  {
			return (CALL_FN(this->_o, this->_func)(arg1, arg2, arg3, arg4));
		  }
		  virtual Ret	exec(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4)
		  {
			return (CALL_FN(this->_o, this->_func)(arg1, arg2, arg3, arg4));
		  }
		private:
		  Ret		(Obj::*_func)(Arg1, Arg2, Arg3, Arg4);
		  Obj *		_o;
		};
		
		template<typename Ret, typename Obj, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class		MemberFunction5 : public IFunction<Ret (Arg1, Arg2, Arg3, Arg4, Arg5)>
		{
		public:
		  MemberFunction5(Ret (Obj::*f)(Arg1, Arg2, Arg3, Arg4, Arg5), Obj * o) : _func(f), _o(o) {};
		  Ret			operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5)
		  {
			return (CALL_FN(this->_o, this->_func)(arg1, arg2, arg3, arg4, arg5));
		  }
		  virtual Ret	exec(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5)
		  {
			return (CALL_FN(this->_o, this->_func)(arg1, arg2, arg3, arg4, arg5));
		  }
		private:
		  Ret		(Obj::*_func)(Arg1, Arg2, Arg3, Arg4, Arg5);
		  Obj *		_o;
		};
				
		template<typename Ret, typename Obj, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class		MemberFunction6 : public IFunction<Ret (Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)>
		{
		public:
		  MemberFunction6(Ret (Obj::*f)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6), Obj * o) : _func(f), _o(o) {};
		  Ret			operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6)
		  {
			return (CALL_FN(this->_o, this->_func)(arg1, arg2, arg3, arg4, arg5, arg6));
		  }
		  virtual Ret	exec(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6)
		  {
			return (CALL_FN(this->_o, this->_func)(arg1, arg2, arg3, arg4, arg5, arg6));
		  }
		private:
		  Ret		(Obj::*_func)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6);
		  Obj *		_o;
		};
	}
}

#endif