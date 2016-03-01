#include <wtws/webserver.h>

#include <gtest/gtest.h>

TEST(WTWSTest, CanInstantiateAWebserver) {
	auto w = wtws::Webserver();
}
