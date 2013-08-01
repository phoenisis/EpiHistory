#ifndef		__STATICFUNCTION_H__
# define	__STATICFUNCTION_H__
# include	"IFunction.h"

namespace Function
{
	namespace detail
	{
		template <typename Ret, typename Callable>
		class StaticFunction0 : public IFunction<Ret>
		{
		public:
		  StaticFunction0(Callable func) : _func(func){}
		  virtual Ret exec()
		  {
			return (_func());
		  }
		private:
		  Callable _func;
		};

		template <typename Ret, typename Callable, typename Arg1>
		class StaticFunction1 : public IFunction<Ret (Arg1)>
		{
		public:
		  StaticFunction1(Callable func) : _func(func){}
		  virtual Ret exec(Arg1 arg1)
		  {
			return (_func(arg1));
		  }
		private:
		  Callable	_func;
		};

		template <typename Ret, typename Callable, typename Arg1, typename Arg2>
		class StaticFunction2 : public IFunction<Ret (Arg1, Arg2)>
		{
		public:
		  StaticFunction2(Callable func) : _func(func){}
		  virtual Ret exec(Arg1 arg1, Arg2 arg2)
		  {
			return (_func(arg1, arg2));
		  }
		private:
		  Callable	_func;
		};

		template <typename Ret, typename Callable, typename Arg1, typename Arg2, typename Arg3>
		class StaticFunction3 : public IFunction<Ret (Arg1, Arg2, Arg3)>
		{
		public:
		  StaticFunction3(Callable func) : _func(func){}
		  virtual Ret exec(Arg1 arg1, Arg2 arg2, Arg3 arg3)
		  {
			return (_func(arg1, arg2, arg3));
		  }
		private:
		  Callable	_func;
		};
		
		template <typename Ret, typename Callable, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		class StaticFunction4 : public IFunction<Ret (Arg1, Arg2, Arg3, Arg4)>
		{
		public:
		  StaticFunction4(Callable func) : _func(func){}
		  virtual Ret exec(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4)
		  {
			return (_func(arg1, arg2, arg3, arg4));
		  }
		private:
		  Callable	_func;
		};

		template <typename Ret, typename Callable, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class StaticFunction5 : public IFunction<Ret (Arg1, Arg2, Arg3, Arg4, Arg5)>
		{
		public:
		  StaticFunction5(Callable func) : _func(func){}
		  virtual Ret exec(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5)
		  {
			return (_func(arg1, arg2, arg3, arg4, arg5));
		  }
		private:
		  Callable	_func;
		};

		template <typename Ret, typename Callable, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class StaticFunction6 : public IFunction<Ret (Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)>
		{
		public:
		  StaticFunction6(Callable func) : _func(func){}
		  virtual Ret exec(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6)
		  {
			return (_func(arg1, arg2, arg3, arg4, arg5, arg6));
		  }
		private:
		  Callable	_func;
		};
	}
}
#endif