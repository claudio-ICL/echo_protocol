#include "header.h"

int main(int argc, char *argv[]) {
  // create socket
  int sock;
  sock = socket(AF_INET, SOCK_STREAM, 0);

  // specify an address for the socket
  struct sockaddr_in address;
  address = instantiate_sockaddr_in(input_from_commandline(argc, argv));

  // connect socket
  int status;
  status = connect(sock, (struct sockaddr *)&address, sizeof(address));
  if (status != 0) {
    fprintf(stderr, "Cannot connect socket.\n");
    exit(1);
  }

  // sleep for 1 sec
  sleep(1);

  // send message from client to server
  char message[256] = "Hello World!";
  ssize_t written = write(sock, message, sizeof(message));
  if (written < 0) {
    fprintf(stderr, "Client cannot write.\n");
    exit(1);
  } else {
    printf("Client sends: %s\n", message);
  }

  // sleep for 1 sec
  sleep(1);

  // receive data from server
  char server_response[256];
  ssize_t received = read(sock, server_response, sizeof(server_response));
  if (received < 0) {
    fprintf(stderr, "Client cannot receive.\n");
    exit(1);
  } else {
    printf("Client receives: %s\n", server_response);
  }

  // close socket
  close(sock);

  return 0;
}
