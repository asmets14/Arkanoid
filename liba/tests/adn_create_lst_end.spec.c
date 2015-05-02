#include <adn_lst.h>
#include <moulitest.h>

static void test00(t_test *test)
{
	t_lst *list;
	t_elem *elem;

	list = adn_lst_newlist();
	adn_create_lst_end(list, strdup("bonbon"));
	adn_create_lst_end(list, "blup");
	adn_create_lst_end(list, "Boobs");
	elem = list->head;

	mt_assert(strcmp(elem->data, "bonbon") == 0);
	mt_assert(strcmp(elem->next->data, "blup") == 0);
	mt_assert(strcmp(elem->next->next->data, "Boobs") == 0);
}



void	suite_adn_create_lst_end(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test00);
}