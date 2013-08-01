#ifndef		__DELEGATE_H__
# define	__DELEGATE_H__
# include	<iostream>
# include	"SmartPointer.h"
# include	"MemberFunction.h"
# include	"IFunction.h"
# include	"StaticFunction.h"

namespace Function
{
	template<typename Ret>
	class		Delegate
	{
	public:
		Delegate() {};
		Delegate(Delegate<Ret> const & d)
		{
			this->_func = const_cast< Delegate<Ret> & >(d).getFunction();
		}
		template<typename Callable>
		Delegate(Callable f) : _func(new detail::StaticFunction0<Ret, Callable>(f)) {};
		template<typename Obj>
		Delegate(Ret (Obj::*f)(), Obj *o) : _func(new detail::MemberFunction0<Ret, Obj>(f, o)) {};
		~Delegate() {};
		SmartPointer< detail::IFunction<Ret> > &	getFunction()
		{
			return (this->_func);
		}
		Delegate<Ret> &		operator=(Delegate<Ret> &f)
		{
			this->_func = f.getFunction();
			return (*this);
		}
		Ret		operator()()
		{
			return (this->_func->exec());
		}
		Ret		exec()
		{
			  return (this->_func->exec());
		}
	private:
		 SmartPointer< detail::IFunction<Ret> >	 _func;
	};

	template<typename Ret, typename Arg>
	class		Delegate <Ret (Arg)>
	{
	public:
		Delegate() {};
		Delegate(Delegate<Ret (Arg)> const & d)
		{
			this->_func = const_cast< Delegate<Ret (Arg)> & >(d).getFunction();
		}
		template<typename Callable>
		Delegate(Callable f) : _func(new detail::StaticFunction1<Ret, Callable, Arg>(f)) {};
		template<typename Obj>
		Delegate(Ret (Obj::*f)(Arg), Obj *o) : _func(new detail::MemberFunction1<Ret, Obj, Arg>(f, o)) {};
		~Delegate() {};
		SmartPointer< detail::IFunction<Ret (Arg)> > &	getFunction()
		{
			return (this->_func);
		}
		Delegate<Ret (Arg)> &		operator=(Delegate<Ret (Arg)> &f)
		{
			this->_func = f.getFunction();
			return (*this);
		}
		Ret		operator()(Arg arg)
		{
			return (this->_func->exec(arg));
		}
		Ret		exec(Arg arg)
		{
			return (this->_func->exec(arg));
		}
	private:
		SmartPointer< detail::IFunction<Ret (Arg)> >	 _func;
	};

	template<typename Ret, typename Arg1, typename Arg2>
	class		Delegate <Ret (Arg1, Arg2)>
	{
	public:
		Delegate() {};
		Delegate(Delegate<Ret (Arg1, Arg2)> const & d)
		{
			this->_func = const_cast< Delegate<Ret (Arg1, Arg2)> & >(d).getFunction();
		}
		template<typename Callable>
		Delegate(Callable f) : _func(new detail::StaticFunction2<Ret, Callable, Arg1, Arg2>(f)) {};
		template<typename Obj>
		Delegate(Ret (Obj::*f)(Arg1, Arg2), Obj *o) : _func(new detail::MemberFunction2<Ret, Obj, Arg1, Arg2>(f, o)) {};
		~Delegate() {};
		SmartPointer< detail::IFunction<Ret (Arg1, Arg2)> > &	getFunction()
		{
			return (this->_func);
		}
		Delegate<Ret (Arg1, Arg2)> &		operator=(Delegate<Ret (Arg1, Arg2)> &f)
		{
			this->_func = f.getFunction();
			return (*this);
		}
		Ret		operator()(Arg1 arg1, Arg2 arg2)
		{
			return (this->_func->exec(arg1, arg2));
		}
		Ret		exec(Arg1 arg, Arg2 arg2)
		{
			return (this->_func->exec(arg, arg2));
		}
	private:
		SmartPointer< detail::IFunction<Ret (Arg1, Arg2)> >	 _func;
	};

	template<typename Ret, typename Arg1, typename Arg2, typename Arg3>
	class		Delegate <Ret (Arg1, Arg2, Arg3)>
	{
	public:
		Delegate() {};
		Delegate(Delegate<Ret (Arg1, Arg2, Arg3)> const & d)
		{
			this->_func = const_cast< Delegate<Ret (Arg1, Arg2, Arg3)> & >(d).getFunction();
		}
		template<typename Callable>
		Delegate(Callable f) : _func(new detail::StaticFunction3<Ret, Callable, Arg1, Arg2, Arg3>(f)) {};
		template<typename Obj>
		Delegate(Ret (Obj::*f)(Arg1, Arg2, Arg3), Obj *o) : _func(new detail::MemberFunction3<Ret, Obj, Arg1, Arg2, Arg3>(f, o)) {};
		~Delegate() {};
		SmartPointer< detail::IFunction<Ret (Arg1, Arg2, Arg3)> > &	getFunction()
		{
			return (this->_func);
		}
		Delegate<Ret (Arg1, Arg2, Arg3)> &		operator=(Delegate<Ret (Arg1, Arg2, Arg3)> &f)
		{
			this->_func = f.getFunction();
			return (*this);
		}
		Ret		operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3)
		{
			return (this->_func->exec(arg1, arg2, arg3));
		}
		Ret		exec(Arg1 arg1, Arg2 arg2, Arg3 arg3)
		{
			return (this->_func->exec(arg1, arg2, arg3));
		}
	private:
		SmartPointer< detail::IFunction<Ret (Arg1, Arg2, Arg3)> >	_func;
	};
	
	template<typename Ret, typename Arg1, typename Arg2, typename Arg3, typename Arg4>
	class		Delegate <Ret (Arg1, Arg2, Arg3, Arg4)>
	{
	public:
		Delegate() {};
		Delegate(Delegate<Ret (Arg1, Arg2, Arg3, Arg4)> const & d)
		{
			this->_func = const_cast< Delegate<Ret (Arg1, Arg2, Arg3, Arg4)> & >(d).getFunction();
		}
		template<typename Callable>
		Delegate(Callable f) : _func(new detail::StaticFunction4<Ret, Callable, Arg1, Arg2, Arg3, Arg4>(f)) {};
		template<typename Obj>
		Delegate(Ret (Obj::*f)(Arg1, Arg2, Arg3, Arg4), Obj *o) : _func(new detail::MemberFunction4<Ret, Obj, Arg1, Arg2, Arg3, Arg4>(f, o)) {};
		~Delegate() {};
		SmartPointer< detail::IFunction<Ret (Arg1, Arg2, Arg3, Arg4)> > &	getFunction()
		{
			return (this->_func);
		}
		Delegate<Ret (Arg1, Arg2, Arg3, Arg4)> &		operator=(Delegate<Ret (Arg1, Arg2, Arg3, Arg4)> &f)
		{
			this->_func = f.getFunction();
			return (*this);
		}
		Ret		operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4)
		{
			return (this->_func->exec(arg1, arg2, arg3, arg4));
		}
		Ret		exec(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4)
		{
			return (this->_func->exec(arg1, arg2, arg3, arg4));
		}
	private:
		SmartPointer< detail::IFunction<Ret (Arg1, Arg2, Arg3, Arg4)> >	_func;
	};
	
	template<typename Ret, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
	class		Delegate <Ret (Arg1, Arg2, Arg3, Arg4, Arg5)>
	{
	public:
		Delegate() {};
		Delegate(Delegate<Ret (Arg1, Arg2, Arg3, Arg4, Arg5)> const & d)
		{
			this->_func = const_cast< Delegate<Ret (Arg1, Arg2, Arg3, Arg4, Arg5)> & >(d).getFunction();
		}
		template<typename Callable>
		Delegate(Callable f) : _func(new detail::StaticFunction5<Ret, Callable, Arg1, Arg2, Arg3, Arg4, Arg5>(f)) {};
		template<typename Obj>
		Delegate(Ret (Obj::*f)(Arg1, Arg2, Arg3, Arg4, Arg5), Obj *o) : _func(new detail::MemberFunction5<Ret, Obj, Arg1, Arg2, Arg3, Arg4, Arg5>(f, o)) {};
		~Delegate() {};
		SmartPointer< detail::IFunction<Ret (Arg1, Arg2, Arg3, Arg4, Arg5)> > &	getFunction()
		{
			return (this->_func);
		}
		Delegate<Ret (Arg1, Arg2, Arg3, Arg4, Arg5)> &		operator=(Delegate<Ret (Arg1, Arg2, Arg3, Arg4, Arg5)> &f)
		{
			this->_func = f.getFunction();
			return (*this);
		}
		Ret		operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5)
		{
			return (this->_func->exec(arg1, arg2, arg3, arg4, arg5));
		}
		Ret		exec(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5)
		{
			return (this->_func->exec(arg1, arg2, arg3, arg4, arg5));
		}
	private:
		SmartPointer< detail::IFunction<Ret (Arg1, Arg2, Arg3, Arg4, Arg5)> >	_func;
	};
		
	template<typename Ret, typename Arg1, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
	class		Delegate <Ret (Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)>
	{
	public:
		Delegate() {};
		Delegate(Delegate<Ret (Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)> const & d)
		{
			this->_func = const_cast< Delegate<Ret (Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)> & >(d).getFunction();
		}
		template<typename Callable>
		Delegate(Callable f) : _func(new detail::StaticFunction6<Ret, Callable, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>(f)) {};
		template<typename Obj>
		Delegate(Ret (Obj::*f)(Arg1, Arg2, Arg3, Arg4, Arg5, Arg6), Obj *o) : _func(new detail::MemberFunction6<Ret, Obj, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6>(f, o)) {};
		~Delegate() {};
		SmartPointer< detail::IFunction<Ret (Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)> > &	getFunction()
		{
			return (this->_func);
		}
		Delegate<Ret (Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)> &		operator=(Delegate<Ret (Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)> &f)
		{
			this->_func = f.getFunction();
			return (*this);
		}
		Ret		operator()(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6)
		{
			return (this->_func->exec(arg1, arg2, arg3, arg4, arg5, arg6));
		}
		Ret		exec(Arg1 arg1, Arg2 arg2, Arg3 arg3, Arg4 arg4, Arg5 arg5, Arg6 arg6)
		{
			return (this->_func->exec(arg1, arg2, arg3, arg4, arg5, arg6));
		}
	private:
		SmartPointer< detail::IFunction<Ret (Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)> >	_func;
	};
}

#endif
