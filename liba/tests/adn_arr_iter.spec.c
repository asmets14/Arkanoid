#include <moulitest.h>
#include <adn_arr.h>
#include <string.h>

void	itern_fn(void *data, void *context)
{
	char *str;

	str = data;
	str[0] += 1;
	(void)context;
}


static void test00(t_test *test)
{
	char **arr;

	arr = (char **)malloc((sizeof(char *) * 4));
	arr[0] = strdup("Bonjour");
	arr[1] = strdup("salut");
	arr[2] = strdup("Chausette");
	arr[3] = NULL;

	adn_arr_iter(arr, itern_fn, NULL);
	mt_assert(strcmp(arr[0], "Conjour") == 0);
	
}

void	suite_adn_arr_iter(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test00);
}