#pragma once

#include "CwAPI3D.h"
#include "cwapi3d.net.icamera-data.h"

namespace CwAPI3D::Net::Bridge
{
	public
		ref class CameraData sealed : public ICameraData
		{
			public:
				explicit CameraData(CwAPI3D::Interfaces::ICwAPI3DCameraData* aCameraData);

				~CameraData();

				!CameraData();

				virtual void destroy();

				virtual void setPosition(vector3D ^ aPosition);
				virtual vector3D ^ getPosition();

				virtual void setTarget(vector3D ^ aTarget);
				virtual vector3D ^ getTarget();

				virtual void setUp(vector3D ^ aUp);
				virtual vector3D ^ getUp();

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
} // namespace CwAPI3D::Net::Bridge
