#pragma once

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/pixdesc.h>
#include <libavutil/hwcontext.h>
#include <libavutil/opt.h>
#include <libavutil/avassert.h>
#include <libavutil/imgutils.h>
}

class VAccel
{
public:
    VAccel(const char* inf, const char* outf="out.yuv", const char* type="vaapi");
    ~VAccel();

    int init();
    int getFrame();
private:
    int decode();

private:
    const char* vatype_;
    const char* infile_;
    const char* outfile_;
    AVBufferRef *hwDeviceCtx_ = nullptr;
    AVFormatContext *inputCtx_ = nullptr;
    AVCodecContext *decoderCtx_ = nullptr;
    AVStream *video_ = nullptr;
    AVCodec *decoder_ = nullptr;
    AVPacket packet_ = {};
    int stream_ = -1;
};

