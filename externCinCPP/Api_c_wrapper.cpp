#include "Api.hpp"

extern "C" {

void *create_api(int x)
{
	Api *api = new Api(x);
	return api;
}

int api_method(void *api)
{
	Api *_api = (Api *)api;	
	return _api->method();
}

void destroy_api(void *api)
{
	Api *_api = (Api *)api;
	delete _api;
}

}
