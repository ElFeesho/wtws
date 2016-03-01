#include <wtws/webserver.h>

#include <gtest/gtest.h>

#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

static int create_socket()
{
	struct addrinfo hints, *res;
	int sockfd;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	getaddrinfo("localhost", "8080", &hints, &res);

	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	int connectResult = connect(sockfd, res->ai_addr, res->ai_addrlen);
	ASSERT_NE(connectResult, -1);
	return sockfd;
}

TEST(WTWSTest, CanInstantiateAWebserver) {
	auto w = wtws::Webserver();
}

TEST(WTWSTest, WebserverWillAcceptASocketConnection) {
	auto w = wtws::Webserver();
	w.startServing();

	int connectedSocket = create_socket();

	close(connectedSocket);

	w.stopServing();

}
