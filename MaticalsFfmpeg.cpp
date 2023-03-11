// Maticals Ffmpeg - library code examples and test.

// Headers & library

//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <string.h>
//#include <iostream>
//#include <algorithm>
//#include <iterator>

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavdevice/avdevice.h>	
#include <libavutil/avutil.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavformat/avio.h>
#include <libavutil/pixdesc.h>
#include <libavutil/hwcontext.h>
#include <libavutil/opt.h>
#include <libavutil/avassert.h>
#include <libavutil/imgutils.h>
#include <libavutil/motion_vector.h>
#include <libavutil/frame.h>
#include <libswresample/swresample.h>
}

#pragma comment(lib, "avcodec.lib")
#pragma comment(lib, "avformat.lib")
#pragma comment(lib, "swscale.lib")
#pragma comment(lib, "avdevice.lib")
#pragma comment(lib, "avutil.lib")
#pragma comment(lib, "avfilter.lib")
#pragma comment(lib, "postproc.lib")
#pragma comment(lib, "swresample.lib")

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

// Test ID:
// 1 - Singletone [OK]
// 2 - Transcode [FAIL] <<< --- This test not work normally!

#define MTS_TEST_ID 2


// [1] Single Tone Freq
#define MTS_TEST_ST_FREQ	22050 * 8

//#define MTS_TEST_SINGLETONE
//#define MTS_TEST_TRANSCODE

#include "String.h"
#include "Audio.h"

int main(){
	printf("Maticals Ffmpeg - examples & test. \r\n");

#if MTS_TEST_ID == 1
	printf("--- Begin test singletone ---\r\n");

	MaticalsAudioSave as;
	MaticalsAudioTest at;
	if(!as.Open("test_singletone.mp4")){
		printf("File test_singletone.mp4 can't opened!\r\n");
		return 0;
	}

	int frames = 300;

	for(int i = 0; i < frames; i ++){
		as.WriteFrame(at.GetSingleTone(MTS_TEST_ST_FREQ));
	}

	as.Close();
	printf("--- End test singletone ---\r\n\r\n");

#endif

#if MTS_TEST_ID == 2
	printf("--- Begin test transcode ---\r\n");

	MaticalsAudioLoad al;
	MaticalsAudioSave as;

	if(!al.Open("test_original.wav")){
		printf("File test_original.wav can't opened!\r\n");
		return 0;
	}

	if(!as.Open("test_transcode.mp4")){
		printf("File test_transcode.mp4 can't opened!\r\n");
		return 0;
	}

	while(al.Read()){
		as.WriteFrame(al.GetFrame());
	}

	as.Close();
	printf("--- End test transcode ---\r\n\r\n");

#endif


	return 0;
}







