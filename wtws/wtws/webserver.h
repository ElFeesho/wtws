#pragma once

namespace wtws
{
	class Webserver
	{
	public:
		explicit Webserver();

		void startServing();

		void handleRequest();

		void stopServing();
	private:
		int serverSocket;
	};
}
