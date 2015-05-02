#include <adn_lst.h>
#include <moulitest.h>

#include <stdio.h>

static void test00(t_test *test)
{
	t_lst *list;
	t_elem *elem1;
	t_elem *elem2;

	list =  adn_lst_newlist();
	elem1 = adn_lst_newelem("bonbon");
	elem2 = adn_lst_newelem("susucre");
	adn_lst_put_end(list, elem1);
	adn_lst_put_end(list, elem2);

	mt_assert(strcmp(list->head->data, "bonbon") == 0);
	mt_assert(strcmp(list->head->next->data, "susucre") == 0);

}

static void test01(t_test *test)
{
	t_elem *elem2;
	t_elem *elem1;
	t_elem *elem3;
	t_lst *list;

	list =  adn_lst_newlist();
	elem1 = adn_lst_newelem("bonbon");
	elem2 = adn_lst_newelem("susucre");
	elem3 = adn_lst_newelem("sucette");
	
	adn_lst_put_end(list, elem1);
	adn_lst_put_end(list, elem2);
	adn_lst_put_end(list, elem3);
	

	mt_assert(strcmp(list->head->next->next->data, "sucette") == 0);

}



void	suite_adn_lst_put_end(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test00);
	SUITE_ADD_TEST(suite, test01);

}