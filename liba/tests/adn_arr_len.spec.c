#include <adn_arr.h>
# include <moulitest.h>
#include <string.h>


static void test00(t_test *test)
{
	
	char tab[4][10];
	strcpy(tab[0],"bonjour");
	strcpy(tab[1],"salut");
	strcpy(tab[2],"lol");
	bzero(tab[3], 1);
	mt_assert(adn_arr_len(tab) == 3);
}

void	suite_adn_arr_len(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test00);
}