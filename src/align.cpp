#include "align.h"
#include "utils.h"
#include <math.h>

using namespace std;

// Basic denoising by computing the average of a sequence of images
FloatImage sequenceMean(const vector<FloatImage> &imSeq)
{
	// create an appropriately sized output FloatImage
	FloatImage output;  //   CHANGEME

	// compute average of sequence

	return output;
}

// Grad students only:
// Compute the per-pixel median of a sequence of images
FloatImage sequenceMedian(const vector<FloatImage> &imSeq)
{
	// create an appropriately sized output FloatImage
	FloatImage output;  //   CHANGEME

	// compute median of sequence
	// you may find std::nth_element useful

	return output;
}

// returns an image visualizing the per-pixel and
// per-channel log of the signal-to-noise ratio scaled by scale.
FloatImage logSNR(const vector<FloatImage> &imSeq, float scale)
{
	// create an appropriately sized logSNR FloatImage
   FloatImage logSNR;   //  CHANGEME

	//  compute average of sequence

	//  compute variance of sequence

	//  computer 10 x log of the signal-to-noise ratio multiplied by scale

	return logSNR;
}

// returns the (x,y) offset that best aligns im2 to match im1.
vector<int> align(const FloatImage &im1, const FloatImage &im2, int maxOffset)
{
	//  offset that best aligns images
	vector<int> offset(2, 0);

	//  find the best offset to align im1 to im2 for all the pixels <= maxOffset
	//  Hint: you might find roll() useful

	return offset;
}

// registers all images to the first one in a sequence and outputs
// a denoised image even when the input sequence is not perfectly aligned.
FloatImage alignAndDenoise(const vector<FloatImage> &imSeq, int maxOffset)
{
	//  register all images to the first one in sequence
	FloatImage output;  //  CHANGEME

	//  iterate over the remaining images in sequence
	//  and do the required processing to denoise image by aligning with first image in sequence

	return output;
}

// split a Sergey images to turn it into one 3-channel image.
FloatImage split(const FloatImage &sergeyImg)
{
	//  create output image with appropriate height (hint: use floor())
	FloatImage output;  //  CHANGEME

	//  store values from sergeyImg into output's 3 channels

	return output;
}

// aligns the green and blue channels of your rgb channel of a sergey
// image to the red channel. This should return an aligned RGB image
FloatImage sergeyRGB(const FloatImage &sergeyImg, int maxOffset)
{
	//  call split()
	FloatImage rgb; //  CHANGEME

	//  align green to red channel
	//  align blue to red channel

	return rgb;
}


/**************************************************************
 //               DON'T EDIT BELOW THIS LINE                //
 *************************************************************/

// This circularly shifts an image by xRoll in the x direction and
// yRoll in the y direction. xRoll and yRoll can be negative or postive
FloatImage roll(const FloatImage &im, int xRoll, int yRoll)
{
	int xNew, yNew;
	FloatImage imRoll(im.width(), im.height(), im.channels());

	// for each pixel in the original image find where its corresponding
	// location is in the rolled image
	for (int x = 0; x < im.width(); x++)
	{
		for (int y = 0; y < im.height(); y++)
		{
			// use modulo to figure out where the new location is in the
			// rolled image. Then take care of when this returns a negative number
			xNew = (x + xRoll) % im.width();
			yNew = (y + yRoll) % im.height();
			xNew = (xNew < 0) * (imRoll.width() + xNew) + (xNew >= 0) * xNew;
			yNew = (yNew < 0) * (imRoll.height() + yNew) + (yNew >= 0) * yNew;

			// assign the rgb values for each pixel in the original image to
			// the location in the new image
			for (int z = 0; z < im.channels(); z++)
				imRoll(xNew, yNew, z) = im(x, y, z);
		}
	}

	// return the rolled image
	return imRoll;
}
