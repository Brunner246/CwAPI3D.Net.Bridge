#pragma once
#include <cmath>

namespace CwAPI3D_CLI
{
public
	ref class vector3D
	{
		double mX{0.0};
		double mY{0.0};
		double mZ{0.0};

	public:
		explicit vector3D(const double aX, const double aY, const double aZ)
			: mX{aX}
			, mY{aY}
			, mZ{aZ}
		{
		}

		vector3D(){};

		property double X
		{
			double get()
			{
				return mX;
			}

			void set(double aX)
			{
				mX = aX;
			}
		}

		property double Y
		{
			double get()
			{
				return mY;
			}

			void set(double aY)
			{
				mY = aY;
			}
		}

		property double Z
		{
			double get()
			{
				return mZ;
			}

			void set(double aZ)
			{
				mZ = aZ;
			}
		}

		static vector3D ^ operator+(vector3D ^ aLeft, vector3D ^ aRight)
		{
			return gcnew vector3D{aLeft->mX + aRight->mX, aLeft->mY + aRight->mY, aLeft->mZ + aRight->mZ};
		}

		static vector3D ^ operator-(vector3D ^ aLeft, vector3D ^ aRight)
		{
			return gcnew vector3D{aLeft->mX - aRight->mX, aLeft->mY - aRight->mY, aLeft->mZ - aRight->mZ};
		}

		static vector3D ^ operator*(vector3D ^ aLeft, vector3D ^ aRight)
		{
			return gcnew vector3D{aLeft->mX * aRight->mX, aLeft->mY * aRight->mY, aLeft->mZ * aRight->mZ};
		}

		static vector3D ^ operator*(vector3D ^ aVector, const double aFactor)
		{
			return gcnew vector3D{aVector->mX * aFactor, aVector->mY * aFactor, aVector->mZ * aFactor};
		}

		double scalar(const vector3D ^ aOther)
		{
			return mX * aOther->mX + mY * aOther->mY + mZ * aOther->mZ;
		}

		vector3D ^ cross(const vector3D ^ aOther) {
			return gcnew vector3D{
				mY * aOther->mZ - mZ * aOther->mY,
				mZ * aOther->mX - mX * aOther->mZ,
				mX * aOther->mY - mY * aOther->mX};
		}

			double length()
		{
			return sqrt(mX * mX + mY * mY + mZ * mZ);
		}

		vector3D ^ normalized() {
			const double lLength = length();
			return gcnew vector3D{mX / lLength, mY / lLength, mZ / lLength};
		}

			CwAPI3D::vector3D toVector3D()
		{
			return CwAPI3D::vector3D{mX, mY, mZ};
		}
	};
} // namespace CwAPI3D_CLI
