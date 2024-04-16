#pragma once

namespace CwAPI3D::Net::Bridge
{
	public
		ref class windowGeometry
		{
			public:
				ref class point
				{
						int mX{0};
						int mY{0};

					public:
						point(const int aX, const int aY)
							: mX(aX)
							, mY(aY)
						{}

						point() {}

						property int X
						{
								int get()
								{
										return mX;
								}
								void set(const int aX)
								{
										mX = aX;
								}
						}

						property int Y
						{
								int get()
								{
										return mY;
								}
								void set(const int aY)
								{
										mX = aY;
								}
						}
				};
				// clang-format off
		property point^ BottomLeft
		{
			point^ get()
			{
				return mBottomLeft;
			}
			void set(point^ aPoint)
			{
			  mBottomLeft = aPoint;
			}
		}
		property point^ BottomRight
		{
			point^ get()
			{
				return mBottomRight;
			}
			void set(point^ aPoint)
			{
			  mBottomRight = aPoint;
			}
		}
		property point^ TopLeft
		{
			point^ get()
			{
				return mTopLeft;
			}
			void set(point^ aPoint)
			{
			  mTopLeft = aPoint;
			}
		}
		property point^ TopRight
		{
			point^ get()
			{
				return mTopRight;
			}
			void set(point^ aPoint)
			{
			  mTopRight = aPoint;
			}
		}

private:
    point ^ mBottomLeft;

		point ^ mBottomRight;

		point ^ mTopLeft;

		point ^ mTopRight;
				// clang-format on
		};
}; // namespace CwAPI3D::Net::Bridge
