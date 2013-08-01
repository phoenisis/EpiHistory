#include "../include/get_next_line.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int                     main(int argc, char **argv)
{
  int                   s;
  struct sockaddr_in    sin;
  /*struct sockaddr_in    client_sin;
    int                   client_sin_len;*/
  int                   port;
  (void) argc;

  s = socket(PF_INET, SOCK_STREAM, 0);
  port = atoi(argv[2]);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(argv[1]);
  connect(s, (struct sockaddr *)&sin, sizeof (struct sockaddr_in));
  puts("Connected to ");
  puts(inet_ntoa(sin.sin_addr));
  puts(" ");
  printf("%d", port);
  puts("\n");
  puts(get_next_line(s));
  close(s);
  return (0);
}
