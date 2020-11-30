#include "pch.h"
#include "C:\Users\urkae\Desktop\лабараторные\cем3\githab\laba3a\Hash-a.cpp"
#include <math.h>



TEST(HashConstruct, Test_constructor_1)
{
	Hash h;
	ASSERT_EQ(0, h.getN());
	for (int i=0;i<sztab;i++)
	{ 
		ASSERT_EQ(0, h.getI(i).busy);
		ASSERT_EQ(-1, h.getI(i).key);
		for (int j = 0; j < szinfo; j++)
			ASSERT_EQ(' ', h.getI(i).info[j]);
		ASSERT_EQ('\0', h.getI(i).info[szinfo]);
	}
}

TEST(HashConstruct, Test_constructor_2)
{
	Hash h1(1);
	Hash h2(5);
	Hash h3(10);
	ASSERT_EQ(1, h1.getN());
	ASSERT_EQ(5, h2.getN());
	ASSERT_EQ(10, h3.getN());
}

TEST(HashConstruct, Test_constructor_3)
{
	EXPECT_ANY_THROW(Hash h(0));
	EXPECT_ANY_THROW(Hash h(sztab+1));
}

TEST(HashMethods, PrintHash_1)
{
	Hash h;
	EXPECT_ANY_THROW(h.printHash());
}

TEST(HashMethods, Find_1)
{
	Hash h;
	h.add(46, "tyuio");
	h.add(3, "ghjkl");

	ASSERT_EQ(1, h.find(46));
	ASSERT_EQ(3, h.find(3));
	ASSERT_EQ(-1, h.find(45));
	ASSERT_EQ(-1, h.find(100));

}

TEST(HashMethods, Add_1)
{
	Hash h;
	h.add(46, "tyuio");
	ASSERT_EQ(1, h.getN());
	ASSERT_EQ(1, h.find(46));
	ASSERT_EQ(1, h.getI(1).busy);

	h.add(3, "ghjkl");
	ASSERT_EQ(2, h.getN());
	ASSERT_EQ(3, h.find(3));
	ASSERT_EQ(1, h.getI(3).busy);
}

TEST(HashMethods, Add_2)
{
	Hash h;
	h.add(46, "tyuio");
	h.add(3, "ghjkl");

	EXPECT_ANY_THROW(h.add(-1, "mnbvco")); //неправильный ключ
	EXPECT_ANY_THROW(h.add(-20, "cxzas"));

	EXPECT_ANY_THROW(h.add(46, "tyuio"));//повторение
	EXPECT_ANY_THROW(h.add(3, "ghjkl"));

	Hash h1(sztab);
	EXPECT_ANY_THROW(h1.add(100, "asdfg"));//переполнение
	EXPECT_ANY_THROW(h1.add(101, "hjklp"));
}

TEST(HashMethods, Delete_1)
{
	Hash h;
	h.add(46, "tyuio");
	h.add(3, "ghjkl");
	ASSERT_EQ(2, h.getN());

	h.del(46);
	ASSERT_EQ(1, h.getN());
	ASSERT_EQ(-1, h.getI(1).busy);

	h.del(3);
	ASSERT_EQ(0, h.getN());
	ASSERT_EQ(-1, h.getI(3).busy);

}

TEST(HashMethods, Delete_2)
{
	Hash h;
	EXPECT_ANY_THROW(h.del(100));
	EXPECT_ANY_THROW(h.del(25));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}