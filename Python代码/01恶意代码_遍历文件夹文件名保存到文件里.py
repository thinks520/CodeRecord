#/usr/bin/python
#-*- coding:utf-8 -*-
import os

# 遍历目录
root = "/"

##  windows系统
# root = "C:\\"
##  Linux系统
# root = "/"


# 存储列表
file_name  = []



# 数据保存文件函数
def save_file():
    # with open(os.getcwd()+"\\file.txt", 'wb') as f:#exl是二进制数据
    #     for file_name_value in file_name:
    #         f.write(file_name_value+"\n")

    file_object = open('thefile.txt', 'w')
    for file_name_value in file_name:
        file_object.write(file_name_value + "\n")
    file_object.close()

if __name__ == '__main__':
    for dirpath, dirnames, filenames in os.walk(root):
        for filepath in filenames:
            file_name.append(os.path.join(dirpath, filepath))
            print os.path.join(dirpath, filepath)

    save_file()
