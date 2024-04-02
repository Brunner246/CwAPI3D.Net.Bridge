#include "CameraData.h"

#include <stdexcept>

CwAPI3D_Net::CameraData::CameraData(CwAPI3D::Interfaces::ICwAPI3DCameraData* aCameraData)
	: mCameraDataInstance{aCameraData}
{
	if(!mCameraDataInstance)
	{
		throw std::invalid_argument("CameraData pointer is null");
	}
}

CwAPI3D_Net::CameraData::~CameraData()
{
	this->!CameraData();
}

CwAPI3D_Net::CameraData::!CameraData() { }

void CwAPI3D_Net::CameraData::destroy()
{
	mCameraDataInstance->destroy();
}

void CwAPI3D_Net::CameraData::setPosition(CwAPI3D_Net::vector3D ^ aPosition)
{
	mCameraDataInstance->setPosition({aPosition->X, aPosition->Y, aPosition->Z});
}

CwAPI3D_Net::vector3D ^ CwAPI3D_Net::CameraData::getPosition()
{
	const auto [mX, mY, mZ] = mCameraDataInstance->getPosition();
	return gcnew CwAPI3D_Net::vector3D{mX, mY, mZ};
}

void CwAPI3D_Net::CameraData::setTarget(CwAPI3D_Net::vector3D ^ aTarget)
{
	mCameraDataInstance->setTarget({aTarget->X, aTarget->Y, aTarget->Z});
}

CwAPI3D_Net::vector3D ^ CwAPI3D_Net::CameraData::getTarget()
{
	const auto [mX, mY, mZ] = mCameraDataInstance->getTarget();
	return gcnew CwAPI3D_Net::vector3D{mX, mY, mZ};
}

void CwAPI3D_Net::CameraData::setUp(CwAPI3D_Net::vector3D ^ aUp)
{
	mCameraDataInstance->setUpVector({aUp->X, aUp->Y, aUp->Z});
}

CwAPI3D_Net::vector3D ^ CwAPI3D_Net::CameraData::getUp()
{
	const auto [mX, mY, mZ] = mCameraDataInstance->getUpVector();
	return gcnew CwAPI3D_Net::vector3D{mX, mY, mZ};
}

void CwAPI3D_Net::CameraData::setProjectionType(ICameraData::projectionType aProjectionType)
{
	mCameraDataInstance->setProjectionType(aProjectionType == ICameraData::projectionType::perspective
											   ? CwAPI3D::Interfaces::ICwAPI3DCameraData::Perspective
											   : CwAPI3D::Interfaces::ICwAPI3DCameraData::Orthographic);
}

CwAPI3D_Net::ICameraData::projectionType CwAPI3D_Net::CameraData::getProjectionType()
{
	return mCameraDataInstance->getProjectionType() == CwAPI3D::Interfaces::ICwAPI3DCameraData::Perspective
			   ? ICameraData::projectionType::perspective
			   : ICameraData::projectionType::orthographic;
}

void CwAPI3D_Net::CameraData::setFieldWidth(const float aFieldWidth)
{
	mCameraDataInstance->setFieldWidth(aFieldWidth);
}

float CwAPI3D_Net::CameraData::getFieldWidth()
{
	return mCameraDataInstance->getFieldWidth();
}

void CwAPI3D_Net::CameraData::setFieldHeight(const float aFieldHeight)
{
	mCameraDataInstance->setFieldHeight(aFieldHeight);
}

float CwAPI3D_Net::CameraData::getFieldHeight()
{
	return mCameraDataInstance->getFieldHeight();
}

void CwAPI3D_Net::CameraData::setFieldOfView(const double aFieldOfView)
{
	mCameraDataInstance->setFieldOfView(aFieldOfView);
}

double CwAPI3D_Net::CameraData::getFieldOfView()
{
	return mCameraDataInstance->getFieldOfView();
}
