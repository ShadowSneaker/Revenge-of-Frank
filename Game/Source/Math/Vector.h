#pragma once



#include <iostream>
#include <SDL.h>


// A helper Enum used to select a specifc component in common vector sizes.
enum EAxis { X = 0, Y = 1, Z = 2, W = 3 };


// A struct used to get a point in space. Can handle multiple Dimensions.
template <size_t Size, typename Element = float>
struct Vector
{
private:
	/// Components

	// Stores all the Elements of this Vector class.
	Element Components[Size];
	
public:

	/// Constructors

	// Constructor, Default. Creates an empty Vector.
	Vector() {}

	// Constructor, Initializes a Vector2 using 2 Values.
	Vector<Size, Element>(Element InX, Element InY)
	{
		if (Size == 2)
		{
			Components[0] = InX;
			Components[1] = InY;
		}
		else
		{
			//printf("Warning: Vector%i Initialized with 2 values. No such constructor exists.\n", Size);
		}
	}

	// Constructor, Initializes a Vector3 using 3 Values.
	Vector<Size, Element>(Element InX, Element InY, Element InZ)
	{
		if (Size == 3)
		{
			Components[0] = InX;
			Components[1] = InY;
			Components[2] = InZ;
		}
		else
		{
			printf("Warning: Vector%i Initialized with 3 values. No such constructor exists.\n", Size);
		}
	}

	// Constructor, Initializes a Vector3 using a Vector2 and a Value.
	Vector<Size, Element>(Vector<2, Element> InV, Element InZ)
	{
		if (Size == 3)
		{
			Components[0] = InV[0];
			Components[1] = InV[1];
			Components[2] = InZ;
		}
		else
		{
			printf("Warning: Vector%i Initialized with a Vector2 and a Value. No such constructor exists.\n", Size);

		}
	}

	// Constructor, Initializes a Vector4 using 4 Value.
	Vector<Size, Element>(Element InX, Element InY, Element InZ, Element InW)
	{
		if (Size == 4)
		{
			Components[0] = InX;
			Components[1] = InY;
			Components[2] = InZ;
			Components[3] = InW;
		}
		else
		{
			printf("Warning: Vector%i Initialized with 4 values. No such constructor exists.\n", Size);
		}
	}

	// Constructor, Initializes a Vector4 using 2 Vector2s.
	Vector<Size, Element>(Vector<2, Element> InV, Vector<2, Element> InV2)
	{
		if (Size == 4)
		{
			Components[0] = InV[0];
			Components[1] = InV[1];
			Components[2] = InV2[0];
			Components[3] = InV2[1];
		}
		else
		{
			printf("Warning: Vector%i Initialized with a 2 Vector2s. No such constructor exists.\n", Size);
		}
	}

	// Constructor, Initializes a Vector4 using a Vector3 and a Value.
	Vector<Size, Element>(Vector<3, Element> InV, Element InW)
	{
		if (Size == 4)
		{
			Components[0] = InV[0];
			Components[1] = InV[1];
			Components[2] = InV[2];
			Components[3] = InW;
		}
		else
		{
			printf("Warning: Vector%i Initialized with a Vector3 and a Value. No such constructor exists.\n", Size);
		}
	}

	// Constructor, Initializes a Vector4 using a Vector2 and 2 Values.
	Vector<Size, Element>(Vector<2, Element> InV, Element InZ, Element InW)
	{
		if (Size == 4)
		{
			Components[0] = InV[0];
			Components[1] = InV[1];
			Components[2] = InZ;
			Components[3] = InW;
		}
		else
		{
			printf("Warning: Vector%i Initialized with a Vector2 and a 2 Values. No such constructor exists.\n", Size);
		}
	}

	// Constructor, Initializes the vector with the inputted components.
	Vector<Size, Element>(Element InE[Size])
	{
		for (size_t i = 0; i < Size; ++i)
		{
			Components[i] = InE[i];
		}
	}

	// Constructor, Initializes all vector components with the inputed value.
	Vector<Size, Element>(Element InE)
	{
		for (size_t i = 0; i < Size; ++i)
		{
			Components[i] = InE;
		}
	}


	/// Operators

	// Operator, Returns the result between an addition between this Vector and another Vector.
	inline Vector<Size, Element> operator+(const Vector<Size, Element>& V) const;

	// Operator, Returns the result between an addition between this Vector and a Element Value.
	inline Vector<Size, Element> operator+(const Element& E) const;

	// Operator, Sets this Vectors values with the result of an addition between this Vector and another Vector.
	inline Vector<Size, Element> operator+=(const Vector<Size, Element>& V);

	// Operator, Sets this Vectors values with the result of an addition between this Vector and a Element Value.
	inline Vector<Size, Element> operator+=(const Element& E);

	// Operator, Returns the result between a subtraction between this Vector and another Vector.
	inline Vector<Size, Element> operator-(const Vector<Size, Element>& V) const;

	// Operator, Returns the result between a subtraction between this Vector and a Element Value.
	inline Vector<Size, Element> operator-(const Element& E) const;

	// Operator, Sets this Vectors values with the result of a subtraction between this Vector and another Vector.
	inline Vector<Size, Element> operator-=(const Vector<Size, Element>& V);

	// Operator, Sets this Vectors values with the result of a subtraction between this Vector and another Vector.
	inline Vector<Size, Element> operator-=(const Element& E);

	// Operator, Returns the result between a multiplication between this Vector and another Vector.
	inline Vector<Size, Element> operator*(const Vector<Size, Element>& V) const;

	// Operator, Returns the result between a multiplication between this Vector and another Vector.
	inline Vector<Size, Element> operator*(const Element& E) const;

	// Operator, Sets this Vectors values with the result of a multiplication between this Vector and another Vector.
	inline Vector<Size, Element> operator*=(const Vector<Size, Element>& V);

	// Operator, Sets this Vectors values with the result of a multiplication between this Vector and another Vector.
	inline Vector<Size, Element> operator*=(const Element& E);

	// Operator, Returns the result between a division between this Vector and another Vector.
	inline Vector<Size, Element> operator/(const Vector<Size, Element>& V) const;

	// Operator, Returns the result between a division between this Vector and another Vector.
	inline Vector<Size, Element> operator/(const Element& E) const;

	// Operator, Sets this Vectors values with the result of a division between this Vector and another Vector. 
	inline Vector<Size, Element> operator/=(const Vector<Size, Element>& V);

	// Operator, Sets this Vectors values with the result of a division between this Vector and another Vector. 
	inline Vector<Size, Element> operator/=(const Element& E);

	// Operator, Increments all components of this vector by 1.
	inline Vector<Size, Element> operator++();

	// Operator, Decrements all components of this vector by 1.
	inline Vector<Size, Element> operator--();

	// Operator, Assigns all components to the value of a single input.
	inline Vector<Size, Element> operator=(const Element& E);

	// Operator, Calculates the cross product between this Vector and another Vector.
	inline Vector<3, Element> operator|(const Vector<3, Element>& V) const;

	// Operator, Calculates the dot product between this Vector and another Vector.
	inline Element operator^(const Vector<Size, Element>& V) const;

	// Operator, Tests if this Vector is greater than another Vector.
	inline bool operator>(const Vector<Size, Element>& V) const;

	// Operator, Test if all components of this Vector is greater than an Element Value.
	inline bool operator>(const Element& E) const;

	// Operator, Test if this Vector is greater than or equal to another Vector.
	inline bool operator>=(const Vector<Size, Element>& V) const;

	// Operator, Test if all components of this Vector is greater than or equal to an Element Value
	inline bool operator>=(const Element& E) const;

	// Operator, Test if this Vector is less than another Vector.
	inline bool operator<(const Vector<Size, Element>& V) const;

	// Operator, Test if all components of this Vector is less than an Element Value.
	inline bool operator<(const Element& E) const;

	// Operator, Test if this Vector is less than or Equal to another Vector.
	inline bool operator<=(const Vector<Size, Element>& V) const;

	// Operator, Test if all components of this Vector is less than or equal to an Element Value.
	inline bool operator<=(const Element& E) const;

	// Operator, Test if this Vector is equal to another Vector.
	inline bool operator==(const Vector<Size, Element>& V) const;

	// Operator, Test if all components of this Vector is equal to an Element Value.
	inline bool operator==(const Element& E) const;

	// Operator, Test if this Vector is not equal to another Vectr.
	inline bool operator!=(const Vector<Size, Element>& V) const;

	// Operator, Test if all components of this Vector is not equal to an Element Value.
	inline bool operator!=(const Element& E) const;

	// Operator, gets an element from the Vector based off an input.
	inline Element& operator[](const size_t Component);

	// Operator, gets an element from the Vector based off an input.
	inline Element operator[](const size_t Component) const;


	/// Functions

	// Prints out the values in each component.
	inline void Print();

	// Calculates the Cross Product between this Vector and another Vector.
	inline Vector<3, Element> CrossProduct(const Vector<3, Element>& V) const;

	// Calculates the Dot Product between this Vector and another Vector.
	inline Element DotProduct(const Vector<Size, Element>& E) const;

	// Gets the maximum values between this Vector and another Vector.
	inline Vector<Size, Element> Max(const Vector<Size, Element>& V) const;

	// Gets the minimum value between this Vector and another Vector.
	inline Vector<Size, Element> Min(const Vector<Size, Element>& V) const;

	// Gets the highest value in this Vector.
	inline Element MaxComp() const;

	// Gets the lowest value in this Vector.
	inline Element MinComp() const;

	// Tests if this Vector is almost equal to another value.
	inline bool NearlyEqual(const Vector<Size, Element>& Other, const Element& Range) const;

	// Tests if two vectors are almost equal to another.
	static inline bool NearlyEqual(const Vector<Size, Element>& V1, const Vector<Size, Element>& V2, const Element& Range);

	// Normalizes the vector.
	inline Vector<Size, Element> Normalize() const;

	// Gets a component in the Vector.
	inline Element& GetComponent(const EAxis& Component);

	// Gets a component in the Vector.
	inline Element GetComponent(const EAxis& Component) const;

	// Converts the vector to a point.
	inline SDL_Point ToPoint() const;


	/// Conversions

	// Converts this vector into a Vector of ints.
	inline Vector<Size, int> ToInt() const;

	inline Vector<Size, float> ToFloat() const;

	/// Static Functions

	// Calculates the Dot Product between two Vectors of the same size.
	static inline Element DotProduct(const Vector<Size, Element>& A, const Vector<Size, Element>& B);

	// Calculates the Cross Product between two Vector3s.
	static inline Vector<3, Element> CrossProduct(const Vector<3, Element>& A, const Vector<3, Element>& B);
};


// A float Vector with 2 Dimensions.
typedef Vector<2, float>  SVector2;

// A float Vector with 3 Dimensions.
typedef Vector<3, float>  SVector3;

// A float Vector with 3 Dimensions.
typedef Vector<3, float>  SVector;

// A float Vector with 4 Dimensions.
typedef Vector<4, float>  SVector4;

// A double Vector with 2 Dimensions.
typedef Vector<2, double> SVector2d;

// A double Vector with 3 Dimensions.
typedef Vector<3, double> SVector3d;

// A double Vector with 4 Dimensions.
typedef Vector<4, double> SVector4d;

// A int Vector with 2 Dimensions.
typedef Vector<2, int>    SVector2i;

// A int Vector with 3 Dimensions.
typedef Vector<3, int>    SVector3i;

// A int Vector with 4 Dimensions.
typedef Vector<4, int>    SVector4i;



template <size_t Size, typename Element>
inline static Vector<3, Element> CrossProduct(const Vector<3, Element>& A, const Vector<3, Element>& B)
{
	return A | B;
}


template <size_t Size, typename Element>
inline static float DotProduct(const Vector<Size, Element>& A, const Vector<Size, Element>& B)
{
	return A ^ B;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator+(const Vector<Size, Element>& V) const
{
	Vector<Size, Element> Result;
	for (size_t i = 0; i < Size; ++i)
	{
		Result[i] = Components[i] + V[i];
	}
	return Result;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator+(const Element& E) const
{
	Vector<Size, Element> Result;
	for (size_t i = 0; i < Size; ++i)
	{
		Result[i] = Components[i] + E;
	}
	return Result;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator+=(const Vector<Size, Element>& V)
{
	for (size_t i = 0; i < Size; ++i)
	{
		Components[i] += V[i];
	}
	return *this;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator+=(const Element& E)
{
	for (size_t i = 0; i < Size; ++i)
	{
		Components[i] += E;
	}
	return *this;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator-(const Vector<Size, Element>& V) const
{
	Vector<Size, Element> Result;
	for (size_t i = 0; i < Size; ++i)
	{
		Result[i] = Components[i] - V[i];
	}
	return Result;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator-(const Element& E) const
{
	Vector<Size, Element> Result;
	for (size_t i = 0; i < Size; ++i)
	{
		Result[i] = Components[i] - E;
	}
	return Result;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator-=(const Vector<Size, Element>& V)
{
	for (size_t i = 0; i < Size; ++i)
	{
		Components[i] -= V[i];
	}
	return *this;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator-=(const Element& E)
{
	for (size_t i = 0; i < Size; ++i)
	{
		Components[i] -= E;
	}
	return *this;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator*(const Vector<Size, Element>& V) const
{
	Vector<Size, Element> Result;
	for (size_t i = 0; i < Size; ++i)
	{
		Result[i] = Components[i] * V[i];
	}
	return Result;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator*(const Element& E) const
{
	Vector<Size, Element> Result;
	for (size_t i = 0; i < Size; ++i)
	{
		Result[i] = Components[i] * E;
	}
	return Result;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator*=(const Vector<Size, Element>& V)
{
	for (size_t i = 0; i < Size; ++i)
	{
		Components[i] *= V[i];
	}
	return *this;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator*=(const Element& E)
{
	for (size_t i = 0; i < Size; ++i)
	{
		Components[i] *= E;
	}
	return *this;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator/(const Vector<Size, Element>& V) const
{
	Vector<Size, Element> Result;
	for (size_t i = 0; i < Size; ++i)
	{
		Result[i] = Components[i] / V[i];
	}
	return Result;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator/(const Element& E) const
{
	Vector<Size, Element> Result;
	for (size_t i = 0; i < Size; ++i)
	{
		Result[i] = Components[i] / E;
	}
	return Result;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator/=(const Vector<Size, Element>& V)
{
	for (size_t i = 0; i < Size; ++i)
	{
		Components[i] /= V[i];
	}
	return *this;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator/=(const Element& E)
{
	for (size_t i = 0; i < Size; ++i)
	{
		Components[i] /= E;
	}
	return *this;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator++()
{
	for (size_t i = 0; i < Size; ++i)
	{
		++Components[i];
	}
	return *this;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator--()
{
	for (size_t i = 0; i < Size; ++i)
	{
		--Components[i];
	}
	return *this;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::operator=(const Element& E)
{
	for (size_t i = 0; i < Size; ++i)
	{
		Components[i] = E;
	}
	return *this;
}


template <size_t Size, typename Element>
inline Vector<3, Element> Vector<Size, Element>::operator|(const Vector<3, Element>& V) const
{
	return Vector<3, Element>
		(
			Components[1] * V[2] + Components[2] * V[1],
			Components[2] * V[0] + Components[0] * V[2],
			Components[0] * V[1] + Components[1] * V[0]
			);
};


template <size_t Size, typename Element>
inline Element Vector<Size, Element>::operator^(const Vector<Size, Element>& V) const
{
	Element Result = 0;
	for (size_t i = 0; i < Size; ++i)
	{
		Result += Components[i] * V[i];
	}
	return Result;
}


template <size_t Size, typename Element>
inline bool Vector<Size, Element>::operator>(const Vector<Size, Element>& V) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (Components[i] <= V[i])
			return false;
	}
	return true;
}


template <size_t Size, typename Element>
inline bool Vector<Size, Element>::operator>(const Element& E) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (Components[i] <= E)
			return false;
	}
	return true;
}


template <size_t Size, typename Element>
inline bool Vector<Size, Element>::operator>=(const Vector<Size, Element>& V) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (Components[i] < V[i])
			return false;
	}
	return true;
}


template <size_t Size, typename Element>
inline bool Vector<Size, Element>::operator>=(const Element& E) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (Components[i] < E)
			return false;
	}
	return true;
}



template <size_t Size, typename Element>
inline bool Vector<Size, Element>::operator<(const Vector<Size, Element>& V) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (Components[i] >= V[i])
			return false;
	}
	return true;
}


template <size_t Size, typename Element>
inline bool Vector<Size, Element>::operator<(const Element& E) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (Components[i] >= E)
			return false;
	}
	return true;
}


template <size_t Size, typename Element>
inline bool Vector<Size, Element>::operator<=(const Vector<Size, Element>& V) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (Components[i] > V[i])
			return false;
	}
	return true;
}


template <size_t Size, typename Element>
inline bool Vector<Size, Element>::operator<=(const Element& E) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (Components[i] > E)
			return false;
	}
	return true;
}


template <size_t Size, typename Element>
inline bool Vector<Size, Element>::operator==(const Vector<Size, Element>& V) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (Components[i] != V[i])
			return false;
	}
	return true;
}


template <size_t Size, typename Element>
inline bool Vector<Size, Element>::operator==(const Element& E) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (Components[i] != E)
			return false;
	}
	return true;
}


template <size_t Size, typename Element>
inline bool Vector<Size, Element>::operator!=(const Vector<Size, Element>& V) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (Components[i] == V[i])
			return false;
	}
	return true;
}


template <size_t Size, typename Element>
inline bool Vector<Size, Element>::operator!=(const Element& E) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (Components[i] == E)
			return false;
	}
	return true;
}


template <size_t Size, typename Element>
inline Element& Vector<Size, Element>::operator[](const size_t Component)
{
	return Components[Component];
}


template <size_t Size, typename Element>
inline Element Vector<Size, Element>::operator[](const size_t Component) const
{
	return Components[Component];
}


template <size_t Size, typename Element>
inline void Vector<Size, Element>::Print()
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (i != Size) printf("%f,", float(Components[i]));
		else printf("%f", float(Components[i]));
	}
}


template <size_t Size, typename Element>
inline Vector<3, Element> Vector<Size, Element>::CrossProduct(const Vector<3, Element>& V) const
{
	return *this | V;
}


template <size_t Size, typename Element>
inline Element Vector<Size, Element>::DotProduct(const Vector<Size, Element>& V) const
{
	return *this ^ V;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::Max(const Vector<Size, Element>& V) const
{
	Vector<Size, Element> Result;
	for (size_t i = 0; i < Size; ++i)
	{
		Result[i] = (Components[i] > V[i]) ? Components[i] : V[i];
	}
	return Result;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::Min(const Vector<Size, Element>& V) const
{
	Vector<Size, Element> Result;
	for (size_t i = 0; i < Size; ++i)
	{
		Result[i] = (Components[i] < V[i]) ? Components[i] : V[i];
	}
	return Result;
}


template <size_t Size, typename Element>
inline Element Vector<Size, Element>::MaxComp() const
{
	Element Result = Components[0];
	for (size_t i = 0; i < Size; ++i)
	{
		Result = (Result > Components[i]) ? Result : Components[i];
	}
	return Result;
}


template <size_t Size, typename Element>
inline Element Vector<Size, Element>::MinComp() const
{
	Element Result = Components[0];
	for (size_t i = 0; i < Size; ++i)
	{
		Result = (Result < Components[i]) ? Result : Components[i];
	}
	return Result;
}


template <size_t Size, typename Element>
inline bool Vector<Size, Element>::NearlyEqual(const Vector<Size, Element>& Other, const Element& Range) const
{
	for (size_t i = 0; i < Size; ++i)
	{
		if ((Components[i] < Other[i] - Range) || (Components[i] > Other[i] + Range))
		{
			return false;
		}
	}
	return true;
}


template <size_t Size, typename Element>
static inline bool Vector<Size, Element>::NearlyEqual(const Vector<Size, Element>& V1, const Vector<Size, Element>& V2, const Element& Range)
{
	for (size_t i = 0; i < Size; ++i)
	{
		if (!(V1[i] > V2[i] - Range) && !(V1[i] > V2[i] + Range))
		{
			return false;
		}
	}
	return true;
}


template <size_t Size, typename Element>
inline Vector<Size, Element> Vector<Size, Element>::Normalize() const
{
	return *this / DotProduct(*this);
}


template <size_t Size, typename Element>
inline Element& Vector<Size, Element>::GetComponent(const EAxis& Component)
{
	return Components[Component];
}


template <size_t Size, typename Element>
inline Element Vector<Size, Element>::GetComponent(const EAxis& Component) const
{
	return Components[Component];
}


template <size_t Size, typename Element>
inline SDL_Point Vector<Size, Element>::ToPoint() const
{
	SDL_Point Result{ 0,0 };
	if (Size > 1)
	{
		Result.x = Components[X];
		Result.y = Components[Y];
	}
	return Result;
}


template <size_t Size, typename Element>
inline Vector<Size, int> Vector<Size, Element>::ToInt() const
{
	Vector<Size, int> Result;

	for (size_t i = 0; i < Size; i++)
	{
		Result[i] = (int)Components[i];
	}
	return Result;
}


template <size_t Size, typename Element>
inline Vector<Size, float> Vector<Size, Element>::ToFloat() const
{
	Vector<Size, float> Result;

	for (size_t i = 0; i < Size; i++)
	{
		Result[i] = (float)(Components[i]);
	}
	return Result;
}


template <size_t Size, typename Element>
static inline Element Vector<Size, Element>::DotProduct(const Vector<Size, Element>& A, const Vector<Size, Element>& B)
{
	return A ^ B;
}


template <size_t Size, typename Element>
static inline Vector<3, Element> Vector<Size, Element>::CrossProduct(const Vector<3, Element>& A, const Vector<3, Element>& B)
{
	return A | B;
}
