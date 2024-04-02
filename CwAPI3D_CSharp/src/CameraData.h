#pragma once

#include "CwAPI3D.h"
#include "ICameraData.h"

namespace CwAPI3D_Net
{
public
	ref class CameraData sealed : public ICameraData
	{
	public:
		explicit CameraData(CwAPI3D::Interfaces::ICwAPI3DCameraData* aCameraData);

		~CameraData();

		!CameraData();

		virtual void destroy();

		virtual void setPosition(CwAPI3D_Net::vector3D ^ aPosition);
		virtual CwAPI3D_Net::vector3D ^ getPosition();

		virtual void setTarget(CwAPI3D_Net::vector3D ^ aTarget);
		virtual CwAPI3D_Net::vector3D ^ getTarget();

		virtual void setUp(CwAPI3D_Net::vector3D ^ aUp);
		virtual CwAPI3D_Net::vector3D ^ getUp();

		virtual void setProjectionType(ICameraData::projectionType aProjectionType);
		virtual ICameraData::projectionType getProjectionType();

		virtual void setFieldWidth(float aFieldWidth);
		virtual float getFieldWidth();

		virtual void setFieldHeight(float aFieldHeight);
		virtual float getFieldHeight();

		virtual void setFieldOfView(double aFieldOfView);
		virtual double getFieldOfView();

	private:
		CwAPI3D::Interfaces::ICwAPI3DCameraData* mCameraDataInstance{nullptr};
	};
} // namespace CwAPI3D_Net
