#include "CameraData.h"

#include <stdexcept>

CwAPI3D_CLI::CameraData::CameraData(CwAPI3D::Interfaces::ICwAPI3DCameraData* aCameraData)
	: mCameraDataInstance{aCameraData}
{
	if(!mCameraDataInstance)
	{
		throw std::invalid_argument("CameraData pointer is null");
	}
}

CwAPI3D_CLI::CameraData::~CameraData()
{
	this->!CameraData();
}

CwAPI3D_CLI::CameraData::!CameraData() { }

void CwAPI3D_CLI::CameraData::destroy()
{
	mCameraDataInstance->destroy();
}

void CwAPI3D_CLI::CameraData::setPosition(CwAPI3D_CLI::vector3D ^ aPosition)
{
	mCameraDataInstance->setPosition({aPosition->X, aPosition->Y, aPosition->Z});
}

CwAPI3D_CLI::vector3D ^ CwAPI3D_CLI::CameraData::getPosition()
{
	const auto [mX, mY, mZ] = mCameraDataInstance->getPosition();
	return gcnew CwAPI3D_CLI::vector3D{mX, mY, mZ};
}

void CwAPI3D_CLI::CameraData::setTarget(CwAPI3D_CLI::vector3D ^ aTarget)
{
	mCameraDataInstance->setTarget({aTarget->X, aTarget->Y, aTarget->Z});
}

CwAPI3D_CLI::vector3D ^ CwAPI3D_CLI::CameraData::getTarget()
{
	const auto [mX, mY, mZ] = mCameraDataInstance->getTarget();
	return gcnew CwAPI3D_CLI::vector3D{mX, mY, mZ};
}

void CwAPI3D_CLI::CameraData::setUp(CwAPI3D_CLI::vector3D ^ aUp)
{
	mCameraDataInstance->setUpVector({aUp->X, aUp->Y, aUp->Z});
}

CwAPI3D_CLI::vector3D ^ CwAPI3D_CLI::CameraData::getUp()
{
	const auto [mX, mY, mZ] = mCameraDataInstance->getUpVector();
	return gcnew CwAPI3D_CLI::vector3D{mX, mY, mZ};
}

void CwAPI3D_CLI::CameraData::setProjectionType(ICameraData::projectionType aProjectionType)
{
	mCameraDataInstance->setProjectionType(aProjectionType == ICameraData::projectionType::perspective
											   ? CwAPI3D::Interfaces::ICwAPI3DCameraData::Perspective
											   : CwAPI3D::Interfaces::ICwAPI3DCameraData::Orthographic);
}

CwAPI3D_CLI::ICameraData::projectionType CwAPI3D_CLI::CameraData::getProjectionType()
{
	return mCameraDataInstance->getProjectionType() == CwAPI3D::Interfaces::ICwAPI3DCameraData::Perspective
			   ? ICameraData::projectionType::perspective
			   : ICameraData::projectionType::orthographic;
}

void CwAPI3D_CLI::CameraData::setFieldWidth(const float aFieldWidth)
{
	mCameraDataInstance->setFieldWidth(aFieldWidth);
}

float CwAPI3D_CLI::CameraData::getFieldWidth()
{
	return mCameraDataInstance->getFieldWidth();
}

void CwAPI3D_CLI::CameraData::setFieldHeight(const float aFieldHeight)
{
	mCameraDataInstance->setFieldHeight(aFieldHeight);
}

float CwAPI3D_CLI::CameraData::getFieldHeight()
{
	return mCameraDataInstance->getFieldHeight();
}

void CwAPI3D_CLI::CameraData::setFieldOfView(const double aFieldOfView)
{
	mCameraDataInstance->setFieldOfView(aFieldOfView);
}

double CwAPI3D_CLI::CameraData::getFieldOfView()
{
	return mCameraDataInstance->getFieldOfView();
}
