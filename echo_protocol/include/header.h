#pragma once

#include <arpa/inet.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

struct sockaddr_input {
  short sin_family;
  int port_num;
  unsigned long s_addr;
};

struct sockaddr_input input_from_commandline(int argc, char *argv[]);

struct sockaddr_in instantiate_sockaddr_in(struct sockaddr_input);

void capitalize_str(char *, char *);
