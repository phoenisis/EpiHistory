#include "SSL_mod.h"

extern	"C"
{
#ifndef _WIN32
	ModuleInfos *			get_module_infos() {
#else
	__declspec(dllexport) ModuleInfos * get_module_infos() {
#endif
			ModuleInfos	*m = new ModuleInfos;
			
			m->associatedDLL = SSL_ASSOCIATED_DLL;
			m->managedDirectives = PREPROCESS_REQUEST | PROCESS_REQUEST | CREATE_RESPONSE;
			m->managesHeaderOnly = true;
			m->name = "SSL";
			m->nbDirectives = 3;
			return m;
	}
#ifndef _WIN32
	Directives *		get_directives()
#else
	__declspec(dllexport) Directives *		get_directives()
#endif
	{
			return (new SSL_mod());
	}
}


SSL_mod::SSL_mod() {
}

SSL_mod::~SSL_mod() {
}

void	SSL_mod::init() {
	SSL_library_init();
		if (!(ssl_ctx_ = SSL_CTX_new(SSLv23_server_method())))
			std::cout << "Error: SSL_CTX_new()" << std::endl;
}

void	SSL_mod::callDirective(DirectivesOrder directiveorder, Request & request, Response & response, t_socket socket, struct sockaddr_in & connexionInfos) {
	if (directiveorder == PREPROCESS_REQUEST)
		handshake_call(socket);
	else if (directiveorder == PREPROCESS_REQUEST)
		process_request(request, socket);
	else if (directiveorder == PRESENDING_PROCESSING)
		create_response(response, socket);
}

// PREPROCESS_REQUEST

void	SSL_mod::handshake_call(t_socket socket) {
	BIO		*b_socket = BIO_new_socket(socket, NULL);
	SSL		*ssl;

	ssl = SSL_new(ssl_ctx_);
	SSL_set_bio(ssl, b_socket, b_socket);
	if (SSL_do_handshake(ssl) != 1)
		std::cout << "SSL_do_handshake error" << std::endl;
}

// PROCESS REQUEST

void	SSL_mod::process_request(Request & request, t_socket socket) {
	char	*buffer = new char[HTTP_GET_MAX_SIZE]();
	int		size;
	BIO		*b_buffer = BIO_new(BIO_f_buffer());
	SSL		*ssl = SSL_new(ssl_ctx_);
	BIO		*b_socket = BIO_new_socket(socket, NULL);

	SSL_set_bio(ssl, b_socket, b_socket);
	if (SSL_do_handshake(ssl) != 1)
		std::cout << "SSL_do_handshake error" << std::endl;
	BIO_write(b_buffer, request.getBuffer(), request.getLength());
	BIO_flush(b_buffer);
	SSL_set_bio(ssl, b_buffer, NULL);
	size = SSL_read(ssl, buffer, HTTP_GET_MAX_SIZE);
	request = Request(buffer, size);
	delete	buffer;
}

// CREATE_RESPONSE

void	SSL_mod::create_response(Response & response, t_socket socket) {
	char	*buffer;
	BIO		*b_buffer = BIO_new(BIO_f_buffer());
	int		size;
	BIO		*b_socket = BIO_new_socket(socket, NULL);
	SSL		*ssl = SSL_new(ssl_ctx_);

	SSL_set_bio(ssl, b_socket, b_socket);
	if (SSL_do_handshake(ssl) != 1)
		std::cout << "SSL_do_handshake error" << std::endl;
	SSL_set_bio(ssl, NULL, b_buffer);
	if (response.getLength() > HTTP_GET_MAX_SIZE)
		std::cout << "SSL: WARNING: Response seems too long for OpenSSL." << std::endl;
	size = SSL_write(ssl, response.getBuffer(), response.getLength());
	BIO_flush(b_buffer);
	buffer = new char[size]();
	BIO_read(b_buffer, buffer, size);
	response = Response(buffer, size);
	delete	buffer;
}