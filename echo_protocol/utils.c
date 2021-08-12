#include "header.h"
struct sockaddr_in instantiate_sockaddr_in(struct sockaddr_input input) {
  struct sockaddr_in addr;

  addr.sin_family = input.sin_family;
  addr.sin_port = htons(input.port_num);
  addr.sin_addr.s_addr = input.s_addr;

  return addr;
}

struct sockaddr_input input_from_commandline(int argc, char *argv[]) {
  struct sockaddr_input input;
  input.sin_family = AF_INET;
  input.port_num = 9002;
  input.s_addr = INADDR_ANY;
  if (argc > 3) {
    input.s_addr = atoi(argv[3]);
  }
  if (argc > 2) {
    input.sin_family = atoi(argv[2]);
  }
  if (argc > 1) {
    input.port_num = atoi(argv[1]);
  }
  return input;
}

void capitalize_str(char *string, char *res) {
  int length = strlen(string);
  for (int i = 0; i < length; i++)
    res[i] = toupper(string[i]);
}
