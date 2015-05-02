#include <adn_lst.h>
#include <moulitest.h>

static void test00(t_test *test)
{
	t_lst *list;

	list = adn_lst_newlist();
	
	mt_assert(list != 0);
}



void	suite_adn_lst_newlist(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test00);
}