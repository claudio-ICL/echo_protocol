#include "header.h"
#define MAX_PENDING_CONNECTIONS 5
#define BUFFER_SIZE 1024

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
  status = listen(sock, MAX_PENDING_CONNECTIONS);
  if (status != 0) {
    fprintf(stderr, "Server failed to listen.\n");
    exit(1);
  } else {
    printf("Server listening for a connection on port %d...\n",
           address.sin_port);
  }

  // accept client socket that has been connected
  int client_socket;
  struct sockaddr_in client_address;
  socklen_t client_address_size = sizeof(client_address);
  client_socket =
      accept(sock, (struct sockaddr *)&client_address, &client_address_size);

  // Get client info
  struct hostent *client_host;
  char *client_ip;
  client_host = gethostbyaddr((const char *)&client_address.sin_addr.s_addr,
                              sizeof(client_address.sin_addr.s_addr), AF_INET);
  client_ip = inet_ntoa(client_address.sin_addr);
  printf("Server establishes connection with %s (%s)\n", client_host->h_name,
         client_ip);

  // receive from client
  char buffer[BUFFER_SIZE];
  ssize_t received = read(client_socket, buffer, sizeof(buffer));
  if (received < 0) {
    fprintf(stderr, "Server cannot receive from client.\n");
    exit(1);
  } else {
    printf("Server receives: %s\n", buffer);
  }

  // responde to client
  capitalize_str(buffer, buffer);
  ssize_t written = write(client_socket, buffer, sizeof(buffer));
  if (written < 0) {
    fprintf(stderr, "Server cannot write.\n");
    exit(1);
  } else {
    printf("Server sends: %s\n", buffer);
  }

  // close socket
  close(sock);

  return 0;
}
