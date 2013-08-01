#ifndef _SSL_MOD_H_
#define	_SSL_MOD_H_

#include <iostream>
#include <list>
#include <openssl/ssl.h>
#include "ModuleInfos.h"
#include "Directives.h"

#define		HTTP_GET_MAX_SIZE	4096 // SSL BIO LIMIT

#define		SSL_ASSOCIATED_DLL		"ssl_mod.dll"
#define		SSL_MANAGED_DIRECTIVES	3
#define		SSL_NUMBER_OF_DIRECTIVES	3

//extern	"C"	{
//	int	SSL_library_init();
//	SSL_CTX *SSL_CTX_new(const SSL_METHOD *);
//	const SSL_METHOD	*SSLv23_server_method();
//	BIO			*BIO_new_socket(int, int);
//	SSL			*SSL_new(SSL_CTX *);
//	void		SSL_set_bio(SSL *, BIO *, BIO*);
//	int			SSL_do_handshake(SSL *);
//	int			SSL_read(SSL *, void *, int);
//	int			SSL_write(SSL *, const void *, int);
//}

class SSL_mod: public Directives {
private:
	SSL_CTX			*ssl_ctx_;
public:
	SSL_mod();
	~SSL_mod();
	void			callDirective(DirectivesOrder directiveorder, Request & request, Response & response, t_socket socket, struct sockaddr_in & connexionInfos);
	void			init();

	// Specifics methods
	void		handshake_call(t_socket);
	void		process_request(Request &, t_socket);
	void		create_response(Response &, t_socket);
};

#endif // !_SSL_H_
