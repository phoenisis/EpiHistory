#ifndef		__READWRITE_HANDLER_H__
# define	__READWRITE_HANDLER_H__
# include	"SmartPointer.h"
# include	"Function.h"
# include	"Buffer.h"
# include	"ISocket.h"
# include	"Neterror.h"

namespace Network
{
	namespace detail
	{
		enum eAction
		{
			READ,
			WRITE,
			ACCEPT
		};

		class		IOOperation
		{
		public:
			virtual ~IOOperation() {};
			virtual ISocket * 	getSocket() = 0;
			virtual int			getAction() const = 0;
		};

		class		ReadWriteOperation : public IOOperation
		{
		public:
			ReadWriteOperation(ISocket * s, eAction a, Buffer & p, ReadHandler & c)
				: _socket(s), _action(a), _buf(p), _callback(c) {};
			~ReadWriteOperation() {};
			ISocket *		getSocket() {return (this->_socket);};
			int				getAction() const {return (this->_action);};
			Buffer &		getBuffer() {return (this->_buf);};
			ReadHandler &	getCallback() {return (this->_callback);};
		private:
			ISocket *		_socket;
			int				_action;
			Buffer			_buf;
			ReadHandler  _callback;
		};

		class		AcceptOperation : public IOOperation
		{
		public:
			AcceptOperation(ISocket * s, eAction a, AcceptHandler & c)
				: _socket(s), _action(a), _callback(c) {};
			~AcceptOperation() {};
			ISocket *		getSocket() {return (this->_socket);};
			int				getAction() const {return (this->_action);};
			AcceptHandler &	getCallback() {return (this->_callback);};
		private:
			ISocket *		_socket;
			int				_action;
			AcceptHandler  _callback;
		};
	}
}
#endif
