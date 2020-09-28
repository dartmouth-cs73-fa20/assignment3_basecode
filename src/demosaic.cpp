#include "demosaic.h"
#include "utils.h"
#include <math.h>

using namespace std;

// takes as input a raw image and returns a single-channel
// 2D image corresponding to the green channel using simple interpolation
FloatImage basicGreen(const FloatImage &raw, int offset)
{
	// create an appropriately sized output FloatImage
	FloatImage output;	//	CHANGEME

	// perform a simple interpolation given the offset

	return output;
}

// takes as input a raw image and returns a single-channel
// 2D image corresponding to the red or blue channel using simple interpolation
FloatImage basicRorB(const FloatImage &raw, int offsetX, int offsetY)
{
	cout << "RorB(" << offsetX << ", " << offsetY << ")" << endl;
	// create an appropriately sized output FloatImage
	FloatImage output; //	CHANGEME

	// horizontal interpolation


	// vertical interpolation


	// diagonal interpolation

	return output;
}

// takes as input a raw image and returns an rgb image
// using simple interpolation to demosaic each of the channels
FloatImage basicDemosaic(const FloatImage &raw, int offsetGreen, int offsetRedX, int offsetRedY, int offsetBlueX,
                         int offsetBlueY)
{
	// create an appropriately sized output FloatImage
	FloatImage output;	// CHANGEME

	//use basicGreen() and basicRorB() to demosaic the raw image


	return output;
}

// takes a raw image and outputs a single-channel
// image corresponding to the green channel taking into account edges
FloatImage edgeBasedGreen(const FloatImage &raw, int offset)
{
	// create an appropriately sized output FloatImage
	FloatImage output;	//	CHANGEME

	//	interpolate horizontally or vertically

	return output;
}

// takes as input a raw image and returns an rgb image
// using edge-based green demosaicing for the green channel and
// simple interpolation to demosaic the red and blue channels
FloatImage edgeBasedGreenDemosaic(const FloatImage &raw, int offsetGreen, int offsetRedX, int offsetRedY,
                                  int offsetBlueX, int offsetBlueY)
{
	// create an appropriately sized output FloatImage
	FloatImage output;	// CHANGEME

	//use edgeBasedGreen() and basicRorB() to demosaic the raw image


	return output;
}

// takes as input a raw image and returns a single-channel
// 2D image corresponding to the red or blue channel using green based interpolation
FloatImage greenBasedRorB(const FloatImage &raw, FloatImage &green, int offsetX, int offsetY)
{
	// create an appropriately sized output FloatImage
	FloatImage output;	// CHANGEME


	// like basicRorB(), but interpolate the differences R-G or B-G

	// horizontal interpolation


	// vertical interpolation


	// diagonal interpolation

	return output;
}

// takes as input a raw image and returns an rgb image
// using edge-based green demosaicing for the green channel and
// simple green based demosaicing of the red and blue channels
FloatImage improvedDemosaic(const FloatImage &raw, int offsetGreen, int offsetRedX, int offsetRedY, int offsetBlueX,
                            int offsetBlueY)
{
	// create an appropriately sized output FloatImage
	FloatImage output;	// CHANGEME

	// use edgeBasedGreen() and greenBasedRorB() to demosaic the image


	return output;
}
