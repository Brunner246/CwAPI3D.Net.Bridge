#include "CameraData.h"

#include <stdexcept>

CwAPI3D::Net::Bridge::CameraData::CameraData(CwAPI3D::Interfaces::ICwAPI3DCameraData* aCameraData)
	: mCameraDataInstance{aCameraData}
{
	if(!mCameraDataInstance)
	{
		throw std::invalid_argument("CameraData pointer is null");
	}
}

CwAPI3D::Net::Bridge::CameraData::~CameraData()
{
	this->!CameraData();
}

CwAPI3D::Net::Bridge::CameraData::!CameraData() { }

void CwAPI3D::Net::Bridge::CameraData::destroy()
{
	mCameraDataInstance->destroy();
}

void CwAPI3D::Net::Bridge::CameraData::setPosition(vector3D ^ aPosition)
{
	mCameraDataInstance->setPosition({aPosition->X, aPosition->Y, aPosition->Z});
}

CwAPI3D::Net::Bridge::vector3D ^ CwAPI3D::Net::Bridge::CameraData::getPosition()
{
	const auto [mX, mY, mZ] = mCameraDataInstance->getPosition();
	return gcnew vector3D{mX, mY, mZ};
}

void CwAPI3D::Net::Bridge::CameraData::setTarget(vector3D ^ aTarget)
{
	mCameraDataInstance->setTarget({aTarget->X, aTarget->Y, aTarget->Z});
}

CwAPI3D::Net::Bridge::vector3D ^ CwAPI3D::Net::Bridge::CameraData::getTarget()
{
	const auto [mX, mY, mZ] = mCameraDataInstance->getTarget();
	return gcnew vector3D{mX, mY, mZ};
}

void CwAPI3D::Net::Bridge::CameraData::setUp(vector3D ^ aUp)
{
	mCameraDataInstance->setUpVector({aUp->X, aUp->Y, aUp->Z});
}

CwAPI3D::Net::Bridge::vector3D ^ CwAPI3D::Net::Bridge::CameraData::getUp()
{
	const auto [mX, mY, mZ] = mCameraDataInstance->getUpVector();
	return gcnew vector3D{mX, mY, mZ};
}

void CwAPI3D::Net::Bridge::CameraData::setProjectionType(ICameraData::projectionType aProjectionType)
{
	mCameraDataInstance->setProjectionType(aProjectionType == ICameraData::projectionType::perspective
											   ? CwAPI3D::Interfaces::ICwAPI3DCameraData::Perspective
											   : CwAPI3D::Interfaces::ICwAPI3DCameraData::Orthographic);
}

CwAPI3D::Net::Bridge::ICameraData::projectionType CwAPI3D::Net::Bridge::CameraData::getProjectionType()
{
	return mCameraDataInstance->getProjectionType() == CwAPI3D::Interfaces::ICwAPI3DCameraData::Perspective
			   ? ICameraData::projectionType::perspective
			   : ICameraData::projectionType::orthographic;
}

void CwAPI3D::Net::Bridge::CameraData::setFieldWidth(const float aFieldWidth)
{
	mCameraDataInstance->setFieldWidth(aFieldWidth);
}

float CwAPI3D::Net::Bridge::CameraData::getFieldWidth()
{
	return mCameraDataInstance->getFieldWidth();
}

void CwAPI3D::Net::Bridge::CameraData::setFieldHeight(const float aFieldHeight)
{
	mCameraDataInstance->setFieldHeight(aFieldHeight);
}

float CwAPI3D::Net::Bridge::CameraData::getFieldHeight()
{
	return mCameraDataInstance->getFieldHeight();
}

void CwAPI3D::Net::Bridge::CameraData::setFieldOfView(const double aFieldOfView)
{
	mCameraDataInstance->setFieldOfView(aFieldOfView);
}

double CwAPI3D::Net::Bridge::CameraData::getFieldOfView()
{
	return mCameraDataInstance->getFieldOfView();
}
