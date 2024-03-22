#pragma once
#include "vector3D.h"

namespace CwAPI3D_CLI
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

		void setPosition(CwAPI3D_CLI::vector3D ^ aPosition);
		CwAPI3D_CLI::vector3D ^ getPosition();

		void setTarget(CwAPI3D_CLI::vector3D ^ aTarget);
		CwAPI3D_CLI::vector3D ^ getTarget();

		void setUp(CwAPI3D_CLI::vector3D ^ aUp);
		CwAPI3D_CLI::vector3D ^ getUp();

		void setProjectionType(projectionType aProjectionType);
		projectionType getProjectionType();

		void setFieldWidth(float aFieldWidth);
		float getFieldWidth();

		void setFieldHeight(float aFieldHeight);
		float getFieldHeight();

		void setFieldOfView(double aFieldOfView);
		double getFieldOfView();
	};
} // namespace CwAPI3D_CLI
