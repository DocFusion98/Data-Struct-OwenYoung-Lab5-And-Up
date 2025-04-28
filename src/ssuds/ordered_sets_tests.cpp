#include <linked_list.h>
#include <gtest/gtest.h>
#include <iostream>
#include <ordered_set.h>
#include "array_list.h"



class OrderedSetTests : public::testing::Test {
protected:
	OrderedSetTests() {

	}

	~OrderedSetTests() {

	}

	ssuds::OrderedSet<int> set1;
	

};

TEST_F(OrderedSetTests, contains) {
	set1.insert(1);
	EXPECT_EQ(set1.contains(1), true);
}
