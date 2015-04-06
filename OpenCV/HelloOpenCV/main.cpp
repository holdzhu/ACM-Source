#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/nonfree/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include <opencv2/gpu/gpu.hpp>
using namespace cv;
using namespace std;

int bins = 25;
Mat src, hsv, hue;

void Hist_and_Backproj(int, void*);

int main(int argc, char *argv[])
{
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		cerr << "Can not open a camera or file." << endl;
		return -1;
	}
    namedWindow("src", 1);
    Mat img_object;
    for (;;)
	{
        cap >> img_object;
        imshow("src", img_object);
        if (waitKey(30) >= 0)
		{
			break;
		}
	}
		int minHessian = 4000;
		SurfFeatureDetector detector(minHessian);
		SurfDescriptorExtractor extractor;
//	cvtColor(img_object, img_object, CV_BGR2GRAY);
    for (;;)
	{
        if (waitKey(1) >= 0)
		{
			break;
		}
		Mat img_scene;
        cap >> img_scene;
        Mat gray_img_scene;
//        cvtColor(img_scene, img_scene, CV_BGR2GRAY);
		vector<KeyPoint> keypoints_object, keypoints_scene;
		detector.detect(img_object, keypoints_object);
		detector.detect(img_scene, keypoints_scene);
		Mat descriptors_object, descriptors_scene;
		extractor.compute(img_object, keypoints_object, descriptors_object);
		extractor.compute(img_scene, keypoints_scene, descriptors_scene);
		if (keypoints_scene.empty() || keypoints_scene.empty()) continue;
		FlannBasedMatcher matcher;
		  std::vector< DMatch > matches;
		  matcher.match( descriptors_object, descriptors_scene, matches );

		  double max_dist = 0; double min_dist = 100;

		  //-- Quick calculation of max and min distances between keypoints
		  for( int i = 0; i < descriptors_object.rows; i++ )
		  { double dist = matches[i].distance;
			if( dist < min_dist ) min_dist = dist;
			if( dist > max_dist ) max_dist = dist;
		  }

		  printf("-- Max dist : %f \n", max_dist );
		  printf("-- Min dist : %f \n", min_dist );

		  //-- Draw only "good" matches (i.e. whose distance is less than 3*min_dist )
		  std::vector< DMatch > good_matches;

		  for( int i = 0; i < descriptors_object.rows; i++ )
		  { if( matches[i].distance < 3*min_dist )
			 { good_matches.push_back( matches[i]); }
		  }

		  Mat img_matches;
//		  drawMatches( img_object, keypoints_object, img_scene, keypoints_scene,
//					   good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
//					   vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

		  //-- Localize the object
		  std::vector<Point2f> obj;
		  std::vector<Point2f> scene;

		  for( int i = 0; i < good_matches.size(); i++ )
		  {
			//-- Get the keypoints from the good matches
			obj.push_back( keypoints_object[ good_matches[i].queryIdx ].pt );
			scene.push_back( keypoints_scene[ good_matches[i].trainIdx ].pt );
		  }
			if (good_matches.size() < 4) continue;
		  Mat H = findHomography( obj, scene, CV_RANSAC );

		  //-- Get the corners from the image_1 ( the object to be "detected" )
		  std::vector<Point2f> obj_corners(4);
		  obj_corners[0] = cvPoint(0,0); obj_corners[1] = cvPoint( img_object.cols, 0 );
		  obj_corners[2] = cvPoint( img_object.cols, img_object.rows ); obj_corners[3] = cvPoint( 0, img_object.rows );
		  std::vector<Point2f> scene_corners(4);

		  perspectiveTransform( obj_corners, scene_corners, H);

		  //-- Draw lines between the corners (the mapped object in the scene - image_2 )
		  line( img_scene, scene_corners[0], scene_corners[1], Scalar(0, 255, 0), 4 );
		  line( img_scene, scene_corners[1], scene_corners[2], Scalar( 0, 255, 0), 4 );
		  line( img_scene, scene_corners[2], scene_corners[3], Scalar( 0, 255, 0), 4 );
		  line( img_scene, scene_corners[3], scene_corners[0], Scalar( 0, 255, 0), 4 );

		  //-- Show detected matches
		  imshow( "src", img_scene );
	}
    return 0;
}


