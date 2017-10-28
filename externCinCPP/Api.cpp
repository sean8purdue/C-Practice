#include "Api.hpp"

Api::Api(int x) : x(x) { }

int Api::method()
{
	return 10 * x;
}

