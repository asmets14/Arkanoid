#include <adn_lst.h>
#include <moulitest.h>


static void test00(t_test *test)
{
	t_elem *lst;

	lst = adn_lst_newelem("bonbon");
	mt_assert(strcmp(lst->data, "bonbon") == 0);
}

void	suite_adn_lst_newelem(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test00);
}