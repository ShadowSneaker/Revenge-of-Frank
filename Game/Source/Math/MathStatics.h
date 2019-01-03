#pragma once


// Gets the value between a minimum value and a maximum value based on the percentage.
// @param Min - The starting value.
// @param Max - The ending value.
// @param Value - The percentage between the values.
// @return - The value percentage between the two numbers based off the value.
static float Lerp(float Min, float Max, float Value)
{
	return (Min + (Max - Min) * Value);
}


// Gets the value between a minimum value and a maximum value based on the percentage.
// @param Min - The starting value.
// @param Max - The ending value.
// @param Value - The percentage between the values.
// @return - The value percentage between the two numbers based off the value.
static int Lerp(int Min, int Max, int Value)
{
	return (Min + (Max - Min) * Value);
}


// Locks a value between a minimum value and a maximum value.
// @param Min - The lowest value the inputted value can be.
// @param Max - The largest value the inputted value can be.
// @param Value - The variable being clamped.
static void Clamp(float Min, float Max, float& Value)
{
	Value = (Value > Max) ? Max : (Value < Min) ? Min : Value;
}


static float Percent(float Min, float Max, float Value)
{
	return (Value - Min) / (Max - Min);
}


static bool NearlyEqual(float Val1, float Val2, float Range)
{
	return ((Val1 >= Val2 - Range) && (Val1 <= Val2 + Range));
}


static bool NearlyEqual(int Val1, int Val2, int Range)
{
	return ((Val1 >= Val2 - Range) && (Val1 <= Val2 + Range));
}


static float Power(float Val, size_t Exp)
{
	float Result = Val;
	for (size_t i = 0; i < Exp; ++i)
	{
		Result *= Val;
	}
	return Result;
}