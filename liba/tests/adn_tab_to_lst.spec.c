#include <adn_arr.h>
#include <adn_lst.h>
#include <moulitest.h>

static void test00(t_test *test)
{
	char *tab[4];
	t_lst *list;


	tab[0] = "journee";
	tab[1] = "fesses";
	tab[2] = "nuances";
	tab[3] = NULL;

	list = adn_tab_to_lst(tab);
	mt_assert(strcmp(list->head->data, "journee") == 0);
}

void	suite_adn_tab_to_lst(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test00);

}