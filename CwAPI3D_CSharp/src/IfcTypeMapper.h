#pragma once

#include "CwAPI3D.h"
#include "EBimIfcType.h"

namespace CwAPI3D_Net::Utils
{
	EBimIfcType mapIfcType(CwAPI3D::Interfaces::ICwAPI3DIfc2x3ElementType* aIfcType);
}
