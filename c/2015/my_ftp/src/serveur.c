#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

void do_client(int cs, struct sockaddr_in addr)
{
  puts("connection from ");
  puts(inet_ntoa(addr.sin_addr));
  puts(" ");
  printf("%d", ntohs(addr.sin_port));
  puts("\n");
  write(cs, "Hello...Goobye\n", 15);
  close(cs);
}

int     main(int argc, char **argv)
{
  struct hostent        *h;
  struct in_addr        addr;   

  if (argc != 2)
    {
      printf("usage: %s hostname.\n", argv[0]);
      exit (1);
    }
  if (!(h = gethostbyname(argv[1])))
    {
      puts("host not found\n");
      exit(1);
    }
  bcopy(h->h_addr_list, &addr, sizeof(addr));
  puts(inet_ntoa(addr));
  puts("\n");
  return (0);
}
