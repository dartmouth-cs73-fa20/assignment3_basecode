#include "align.h"
#include "demosaic.h"
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

// test denoising function by averaging function and visualizing SNR
void testDenoiseSeq()
{
	// load an image sequence
	vector<FloatImage> imSeq;
	int nImages = 44;

	// add each image to the vector of images
	for (int i = 1; i <= nImages; i++)
	{
		ostringstream ss;
		ss << DATA_DIR "/input/a3/aligned-ISO400/1D2N-iso400-under-" << i << ".png";
		string filename = ss.str();
		imSeq.push_back(FloatImage(filename));
	}

	// denoise by averaging across all of the images
	FloatImage imDenoise = sequenceMean(imSeq);
	imDenoise.write(DATA_DIR "/output/denoisedImg.png");

	// estimate the SNR of the image sequence
	FloatImage SNRIm = logSNR(imSeq);
	SNRIm.write(DATA_DIR "/output/snrImg.png");
}


// test your function to find the optimal offset between 2 images
void testOffset()
{
	// load the images that are not aligned
	FloatImage im1(DATA_DIR "/input/a3/green/noise-small-1.png");
	FloatImage im2(DATA_DIR "/input/a3/green/noise-small-2.png");

	// get the best offset for these 2 images
	int maxOffset = 10;
	vector<int> offset = align(im1, im2, maxOffset);

	// print out the offset values that best aligns im2 to im1
	cout << "x offset: " << offset[0] << " y offset: " << offset[1] << endl;
}

// test your denoising function by aligned averaging
void testDenoiseShiftSeq()
{
	// load an image sequence
	vector<FloatImage> imSeq;
	int nImages = 9;

	// add each image to the vector of images
	for (int i = 1; i <= nImages; i++)
	{
		ostringstream ss;
		ss << DATA_DIR "/input/a3/green/noise-small-" << i << ".png";
		string filename = ss.str();
		imSeq.push_back(FloatImage(filename));
	}

	// denoise using just pure averaging - this should result in a blurry output
	FloatImage imDenoiseBlur = sequenceMean(imSeq);
	imDenoiseBlur.write(DATA_DIR "/output/denoisedImg_Avg.png");

	// denoise by averaging aligned images
	FloatImage imDenoiseShift = alignAndDenoise(imSeq, 5);
	imDenoiseShift.write(DATA_DIR "/output/denoisedImg_AlignedAvg.png");

}

// test your demosaicing functions that use simple interpolation
void testBasicDemosaic()
{
	// load raw image (notice that although this is a 3 channel image each channel
	// has the same value so you can think of it as having only 1 channel)
	FloatImage raw(DATA_DIR "/input/a3/raw/signs-small.png");

	// demosaic the green channel
	FloatImage green = basicGreen(raw);
	green.write(DATA_DIR "/output/green_basic.png");

	// demosaic the red channel
	FloatImage red = basicRorB(raw, 1, 1);
	red.write(DATA_DIR "/output/red_basic.png");

	// demosaic the blue channel
	FloatImage blue = basicRorB(raw, 0, 0);
	blue.write(DATA_DIR "/output/blue_basic.png");

	// generate a full rgb image by demaosicing each of the channels
	// and concatinating them together
	FloatImage rgb = basicDemosaic(raw);
	rgb.write(DATA_DIR "/output/rgb_basic.png");
}

// test your demosaicing functions that use the green channel to incoperate information
// about edges in your image
void testGreenEdgeDemosaic()
{
	// load raw image (notice that although this is a 3 channel image each channel
	// has the same value so you can think of it as having only 1 channel)
	FloatImage raw(DATA_DIR "/input/a3/raw/signs-small.png");

	// demosaic the green channel using the edge-based method
	FloatImage green = edgeBasedGreen(raw);
	green.write(DATA_DIR "/output/green_edge.png");

	// generate the rgb image using edge based demosaicing algorithm for the
	// green channel but the naive red and blue demosaicing algorithm
	FloatImage rgb_greenEdge = edgeBasedGreenDemosaic(raw);
	rgb_greenEdge.write(DATA_DIR "/output/rgb_greenEdge.png");

	// generate the rgb image using the edge based demosaicing algorithm
	// for the green, red, and blue channels
	FloatImage rgb_fullEdge = improvedDemosaic(raw);
	rgb_fullEdge.write(DATA_DIR "/output/rgb_fullEdge.png");
}

// test your functions to generate an rgb image from the Sergey images
void testSergey()
{
	// load a sergey image
	// FloatImage sergeyImg(DATA_DIR "/input/a3/Sergey/01880v_third.png");
	// FloatImage sergeyImg(DATA_DIR "/input/a3/Sergey/00088v_third.png");
	// FloatImage sergeyImg(DATA_DIR "/input/a3/Sergey/00106v_third.png");
	// FloatImage sergeyImg(DATA_DIR "/input/a3/Sergey/00137v_third.png");
	FloatImage sergeyImg(DATA_DIR "/input/a3/Sergey/00757v_third.png");
	// FloatImage sergeyImg(DATA_DIR "/input/a3/Sergey/00888v_third.png");
	// FloatImage sergeyImg(DATA_DIR "/input/a3/Sergey/00889v_third.png");
	// FloatImage sergeyImg(DATA_DIR "/input/a3/Sergey/00907v_third.png");
	// FloatImage sergeyImg(DATA_DIR "/input/a3/Sergey/00911v_third.png");
	// FloatImage sergeyImg(DATA_DIR "/input/a3/Sergey/01031v_third.png");
	// FloatImage sergeyImg(DATA_DIR "/input/a3/Sergey/01880v_third.png");

	// split the grayscale image to generate a rgb image
	FloatImage rgb = split(sergeyImg);
	rgb.write(DATA_DIR "/output/sergeyRGB.png");

	// split the grayscale image and align the channels to
	// generate a clean RGB image
	FloatImage rgbAlign = sergeyRGB(sergeyImg);
	rgbAlign.write(DATA_DIR "/output/sergeyRGB_align.png");
}

// This is a way for you to test your functions.
// We will not grade the contents of the main function
int main()
{
	// uncomment these test functions as you complete the assignment
	//testDenoiseSeq();
	//testOffset();
	//testDenoiseShiftSeq();
	//testBasicDemosaic();
	//testGreenEdgeDemosaic();
	//testSergey();
}
