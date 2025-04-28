#include <linked_list.h>
#include <gtest/gtest.h>
#include <iostream>


/*
class LinkedListTests : public::testing::Test {
protected:
	LinkedListTests() {

	}

	~LinkedListTests() {

	}

	ssuds::LinkedList<int> list1 = { 2, 16, 8, 14, 3 };
	ssuds::LinkedList<int> list2 = { 2, 8, 8, 14, 2};
	ssuds::LinkedList<int> list3 = { 2, 9, 8, 14, 15, 1, 6, 18 };
	ssuds::LinkedList<int> list4 = { 2, 9, 8, 14, 15, 1, 6, 18 };
	ssuds::LinkedList<int> list5 = { 2, 6, 8, 14, 2, 9 };
	ssuds::LinkedList<int>::LinkedListIterator iter1;

};


TEST_F(LinkedListTests, Find1) {
	list1.append(12);

	EXPECT_EQ(list1.find(12), 6);
}
TEST_F(LinkedListTests, Find2) {
	list1.append(8);
	EXPECT_EQ(list1.find(8), 3);
}

TEST_F(LinkedListTests, Find3) {
	EXPECT_EQ(list1.find(2), 1);
}

TEST_F(LinkedListTests, Remove) {
	//std::cout << "Linked List Size: " << list1.size() << "\n";
	list1.remove(8);
	//std::cout << "Linked List Size: " << list1.size() << "\n";

	EXPECT_EQ(list1.find(8), -1);
}

TEST_F(LinkedListTests, RemoveAll) {
	//std::cout << "Linked List Size: " << list2.size() << "\n";

	list2.remove_all(8);

	//std::cout << "Linked List Size: " << list2.size() << "\n";
	
	EXPECT_EQ(list2.find(8), -1);
	EXPECT_EQ(list2.find(2), 1);
	list2.remove_all(2);
	EXPECT_EQ(list2.find(2), -1);
}

TEST_F(LinkedListTests, Clear) {
	list3.clear();
	EXPECT_EQ(list3.find(18), -1);
	list3.prepend(9);
	EXPECT_EQ(list3.at(0), 9);
}

TEST_F(LinkedListTests, Prepend) {
	list4.prepend(1);
	EXPECT_EQ(list4.at(0), 1);
	EXPECT_EQ(list4.at(1), 2);
	EXPECT_EQ(list4.at(2), 9);
	EXPECT_EQ(list4.at(3), 8);
	EXPECT_EQ(list4.at(4), 14);
	EXPECT_EQ(list4.at(5), 15);
	EXPECT_EQ(list4.at(6), 1);
	EXPECT_EQ(list4.at(7), 6);
	EXPECT_EQ(list4.at(8), 18);
	EXPECT_EQ(list4.size(), 9);
}


TEST_F(LinkedListTests, FindIter) {
	EXPECT_EQ(list5.find_it(6), 2);
}
*/