#include <adn_lst.h>
#include <moulitest.h>


static void test00(t_test *test)
{
	t_elem *elem2;
	t_elem *elem1;
	
	elem1 = adn_lst_newelem("bonbon");
	elem2 = adn_lst_newelem("susucre");
	adn_lst_fusion(elem1, elem2);

	mt_assert(strcmp(elem2->prev->data, "bonbon") == 0);
}

void	suite_adn_lst_fusion(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test00);
}