#include "header.h"

int main(int argc, char *argv[]) {
  // create socket
  int sock;
  sock = socket(AF_INET, SOCK_STREAM, 0);

  // specify an address for the socket
  struct sockaddr_in address;
  address = instantiate_sockaddr_in(input_from_commandline(argc, argv));

  // bind socket
  int status;
  status = bind(sock, (struct sockaddr *)&address, sizeof(address));
  if (status != 0) {
    fprintf(stderr, "Cannot bind socket.\n");
    exit(1);
  }

  // listen for client connections
  listen(sock, 5);

  // accept client socket that has been connected
  int client_socket;
  client_socket = accept(sock, NULL, NULL);

  // receive from client
  char incoming_msg[256];
  ssize_t received = read(client_socket, incoming_msg, sizeof(incoming_msg));
  if (received < 0) {
    fprintf(stderr, "Server cannot receive from client.\n");
    exit(1);
  } else {
    printf("Server receives: %s\n", incoming_msg);
  }

  // send message from server to client
  char message[256];
  capitalize_str(incoming_msg, message);
  ssize_t written = write(client_socket, message, sizeof(message));
  if (written < 0) {
    fprintf(stderr, "Server cannot write.\n");
    exit(1);
  } else {
    printf("Server sends: %s\n", message);
  }

  // close socket
  close(sock);

  return 0;
}
