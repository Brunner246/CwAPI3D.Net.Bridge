#pragma once
#include "cwapi3d.net.vector3d.h"

namespace CwAPI3D::Net::Bridge
{
public
	interface class ICameraData
	{
		enum class projectionType
		{
			perspective,
			orthographic
		};

		void destroy();

		void setPosition(vector3D ^ aPosition);
		vector3D ^ getPosition();

		void setTarget(vector3D ^ aTarget);
		vector3D ^ getTarget();

		void setUp(vector3D ^ aUp);
		vector3D ^ getUp();

		void setProjectionType(projectionType aProjectionType);
		projectionType getProjectionType();

		void setFieldWidth(float aFieldWidth);
		float getFieldWidth();

		void setFieldHeight(float aFieldHeight);
		float getFieldHeight();

		void setFieldOfView(double aFieldOfView);
		double getFieldOfView();
	};
} // namespace CwAPI3D_Net
