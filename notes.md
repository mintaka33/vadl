# Notes

## reference
https://trac.ffmpeg.org/wiki/HWAccelIntro

https://trac.ffmpeg.org/wiki/Hardware/VAAPI

## build ffmpeg example
```bash
sudo apt install libx264-dev
sudo apt install libx265-dev

cd build/ffmpeg
../../FFmpeg/configure --enable-debug=3 --disable-optimizations --enable-libx264 --enable-libx265 --enable-gpl
make -j4
make examples
```

## command line examples
ffmpeg hw decode+vpp
```bash
./ffmpeg -y -hwaccel vaapi -hwaccel_output_format vaapi -vaapi_device /dev/dri/renderD128 \
-i ~/test.264 -vframes 1 -vf scale_vaapi=w=640:h=360,hwdownload,format=yuv420p out.yuv
```

ffmpeg hw decode+vpp+encode
```bash
./ffmpeg -y -v verbose -benchmark -hwaccel vaapi -hwaccel_output_format vaapi -vaapi_device /dev/dri/renderD128 \
 -i ~/test.264 -vframes 100 -vf scale_vaapi=w=640:h=360 -c:v h264_vaapi -b:v 1M /tmp/output.mp4
```

## graph2dot tool
build graph2dot
```bash
sudo apt install graphviz
cd build/ffmpeg
make tools/graph2dot
```

run graph2dot
```bash
cd build/ffmpeg/tools
# example 1
echo nullsrc,scale=640:360,nullsink | ./graph2dot -o graph.tmp && dot -Tpng graph.tmp -o graph.png && display graph.png
```
