#/usr/bin/python
#-*- coding:utf-8 -*-
import os


# 遍历C盘目录文件


def main():
    # 存放的路径
    path = "C:\\"
    # 1、遍历目录内文件名
    nCout = 0                                                 # 文件计数
    path_text = open('path.txt', 'w')                        # 将文件名写入文本
    for fpathe, dirs, fs in os.walk(path):                   # 遍历路径
        for f in fs:                                         # 遍历文件名
            nCout = nCout + 1                                 # 计数器增加
            print os.path.join(fpathe, f)                     # 拼接全路径
            path_text.write(os.path.join(fpathe, f) + '\n')   # 将路径写入到文本
    print nCout                                               # 打印计数器
    path_text.close()                                          # 关闭文件

if __name__ == '__main__':
    main()