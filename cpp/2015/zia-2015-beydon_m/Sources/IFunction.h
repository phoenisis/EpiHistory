#ifndef		__IFUNCTION_H__
# define	__IFUNCTION_H__

namespace Function
{
	namespace detail
	{
		template<typename Ret>
		class		IFunction
		{
		public:
			virtual ~IFunction() {};
			virtual Ret		exec() {};
		};

		template<typename Ret, typename Arg>
		class		IFunction <Ret (Arg)>
		{
		public:
			virtual ~IFunction() {};
			virtual Ret		exec(Arg) = 0;
		};

		template<typename Ret, typename Arg, typename Arg2>
		class		IFunction <Ret (Arg, Arg2)>
		{
		public:
			virtual ~IFunction() {};
			virtual Ret		exec(Arg, Arg2) = 0;
		};

		template<typename Ret, typename Arg, typename Arg2, typename Arg3>
		class		IFunction <Ret (Arg, Arg2, Arg3)>
		{
		public:
			virtual ~IFunction() {};
			virtual Ret		exec(Arg, Arg2, Arg3) = 0;
		};

		template<typename Ret, typename Arg, typename Arg2, typename Arg3, typename Arg4>
		class		IFunction <Ret (Arg, Arg2, Arg3, Arg4)>
		{
		public:
			virtual ~IFunction() {};
			virtual Ret		exec(Arg, Arg2, Arg3, Arg4) = 0;
		};
		
		template<typename Ret, typename Arg, typename Arg2, typename Arg3, typename Arg4, typename Arg5>
		class		IFunction <Ret (Arg, Arg2, Arg3, Arg4, Arg5)>
		{
		public:
			virtual ~IFunction() {};
			virtual Ret		exec(Arg, Arg2, Arg3, Arg4, Arg5) = 0;
		};

		template<typename Ret, typename Arg, typename Arg2, typename Arg3, typename Arg4, typename Arg5, typename Arg6>
		class		IFunction <Ret (Arg, Arg2, Arg3, Arg4, Arg5, Arg6)>
		{
		public:
			virtual ~IFunction() {};
			virtual Ret		exec(Arg, Arg2, Arg3, Arg4, Arg5, Arg6) = 0;
		};
	}
}

#endif
