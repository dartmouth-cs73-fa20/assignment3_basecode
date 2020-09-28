#pragma once

#include "floatimage.h"
#include <iostream>
#include <math.h>

FloatImage basicGreen(const FloatImage &raw, int offset=1);
FloatImage basicRorB(const FloatImage &raw, int offsetX, int offsetY);
FloatImage basicDemosaic(const FloatImage &raw, int offsetGreen=1, int offsetRedX=1, int offsetRedY=1, int offsetBlueX=0, int offsetBlueY=0);
FloatImage edgeBasedGreen(const FloatImage &raw, int offset=1);
FloatImage edgeBasedGreenDemosaic(const FloatImage &raw, int offsetGreen=1, int offsetRedX=1, int offsetRedY=1, int offsetBlueX=0, int offsetBlueY=0);
FloatImage greenBasedRorB(const FloatImage &raw, FloatImage &green, int offsetX, int offsetY);
FloatImage improvedDemosaic(const FloatImage &raw, int offsetGreen=1, int offsetRedX=1, int offsetRedY=1, int offsetBlueX=0, int offsetBlueY=0);

