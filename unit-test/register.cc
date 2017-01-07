#include <gtest/gtest.h>
#include <cstdint>

TEST( register_test, setting_bits )
{
	uint32_t register_value = 0;
	register_value = 1;
	EXPECT_EQ( register_value , 1 );
	register_value = 0;
	register_value |= 1 << 0;
	EXPECT_EQ( regisppter_value , 1 );
	register_value = 0;
	register_value |= 1 << 1;

	EXPECT_EQ( register_value , 2 );
}
TEST( register_test, uno_igual_uno )
{
	uint32_t register_value = 0;
	register_value = 1;
	EXPECT_EQ( 1, 1);
}

TEST( register_test, dos_igual_dos )
{
	uint32_t register_value = 0;
	register_value = 1;
	EXPECT_EQ( 2, 2);
}
		 
