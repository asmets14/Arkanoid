#include <adn_lst.h>
#include <moulitest.h>

static void test00(t_test *test)
{
	t_lst * lst;
	t_elem *elem;
	t_elem *elem1;
	t_elem *elem2;
	lst = adn_lst_newlist();
	elem = adn_lst_newelem("bonjour");
	adn_create_lst_end(lst, elem);
	elem1 = adn_lst_newelem("lol");
	adn_create_lst_end(lst, elem1);
	elem2 = adn_lst_newelem("k");
	adn_create_lst_end(lst, elem1);
	mt_assert(adn_lst_len(lst) == 3);
}

void	suite_adn_lst_len(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test00);
}