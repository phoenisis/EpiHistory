#ifndef			__DATA_STRUCTURES_H__
# define		__DATA_STRUCTURES_H__

# define SUCCESS 0
# define FAILURE 1
# define AUTHENTICATION_FAILURE 2
# define COMMAND_NOT_FOUND 3
# define INVALID_CONTACT_NAME 4
# define CALL_REFUSED 5
# define INVITATION_REFUSED 6
# define BAD_FORMAT 7

struct			PacketHeader
{
	unsigned short int	status;
	unsigned short int	cmd;
	unsigned short int	sourceId;
	unsigned short int	targetId;
};

struct			AuthenticationPacket
{
	PacketHeader			header;
	unsigned short int		dataSize;
	unsigned short int		loginSize;
	char					login[128];
	unsigned short int		passwordSize;
	char					password[128];
};

struct			NetworkInformationPacket
{
	PacketHeader			header;
	unsigned short int		dataSize;
	unsigned short int		ipLength;
	char					ip[15];
	unsigned short int		port;
};

struct			ContactPacket
{
	PacketHeader			header;
	unsigned short int		dataSize;
	unsigned short int		contactSize;
	char					contactName[128];
};

#endif