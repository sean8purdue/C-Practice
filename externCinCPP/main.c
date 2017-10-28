#include "Api.h"

#include <stdio.h>

int main()
{
	void *api = create_api(42);
	printf("%d\n", api_method(api));
	destroy_api(api);
}
