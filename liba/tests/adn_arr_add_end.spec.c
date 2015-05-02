#include <adn_arr.h>
# include <moulitest.h>



static void test00(t_test *test)
{
	char **tab;

	tab = adn_arr_new(4);
	adn_arr_add_end(tab,"bonjour");
	adn_arr_add_end(tab,"nul");
	
	mt_assert(strcmp(tab[0], "bonjour") == 0);
	mt_assert(strcmp(tab[1], "nul") == 0);
}

void	suite_adn_arr_add_end(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test00);
}