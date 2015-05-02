#include <adn_arr.h>
# include <moulitest.h>
#include <string.h>


static void test00(t_test *test)
{
	char **tab;

	tab = adn_arr_new(4);
	tab[0] = "bonjour";
	tab[1] = "nul";
	
	mt_assert(strcmp(tab[0], "bonjour") == 0);
}

void	suite_adn_arr_new(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test00);
}