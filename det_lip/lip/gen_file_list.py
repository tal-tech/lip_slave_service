# import os
# '''
# 作用：遍历音频文件夹和视频文件夹，生成一一对应列表
# '''


# if __name__ == "__main__":
#     # 音频文件夹
#     audio_dir = "/home/tal/data/workspace/lip_generation/lip_generation_performance/data/images/wav_cut_length_test/test1"
#     # 视频文件夹
#     video_dir = "/home/tal/data/workspace/lip_generation/lip_generation_performance/data/images/video/"
#     # 输出的filelist文件
#     output_filelist_path = "filelist.txt"
#     video_list = os.listdir(video_dir)
#     audio_list = os.listdir(audio_dir)

#     with open(output_filelist_path, 'w') as f:
#         for video_path in video_list:
#             if video_path.find(".mp4") == -1:
#                 continue
#             for audio_path in audio_list:
#                 if audio_path.find(".wav") == -1:
#                     continue
#                 f.write(os.path.join(video_dir, video_path) + "   " + os.path.join(audio_dir, audio_path) + "\n")

import wave
import numpy as np
f = wave.open("/home/tal/data/workspace/lip_generation/lip_generation_performance/data/images/output/Abby_final.wav",'rb')
params = f.getparams()
nchannels, sample_width, framerate, nframes = params[:4]
str_data = f.readframes(nframes)
f.close()
print(params[:4])
# print(str_data)
wave_data = np.fromstring(str_data, dtype = np.short)
print('max:', np.max(wave_data))
print('min:', np.min(wave_data))