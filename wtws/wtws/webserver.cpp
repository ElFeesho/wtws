#include "webserver.h"

#include <iostream>

#include <netdb.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/fcntl.h>
#include <sys/unistd.h>

namespace wtws
{
	Webserver::Webserver()
	{
	}

	void Webserver::startServing()
	{
		struct addrinfo hints { 0 }, *res = nullptr;

		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_flags = AI_PASSIVE;

		getaddrinfo(NULL, "8080", &hints, &res);

		serverSocket = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

		bind(serverSocket, res->ai_addr, res->ai_addrlen);

		fcntl(serverSocket, F_SETFL, O_NONBLOCK);
		fcntl(serverSocket, F_SETFL, O_ASYNC);
	}

	void Webserver::handleRequest()
	{
		static fd_set readFds;
		static struct timeval tv { .tv_sec = 1, .tv_usec = 0 };

		FD_ZERO(&readFds);

		FD_SET(serverSocket, &readFds);

		if (select(serverSocket + 1, &readFds, NULL, NULL, &tv))
		{
			if (FD_ISSET(serverSocket, &readFds))
			{
				std::cout << "Accepting incoming connection" << std::endl;
				struct sockaddr addr;
				socklen_t addrlen;
				int client = accept(serverSocket, &addr, &addrlen);
			}
		}
	}

	void Webserver::stopServing()
	{
	}
}
