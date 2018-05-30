#/usr/bin/python
#-*- coding:utf-8 -*-

## 输入参数说明

# target.txt   为对比的目标文件
# raw_data.txt 为原始文件对比
# diff_rule 输出的文件

import sys,os,re
target = []
raw_data = []


# 数据保存文件函数
def save_file_xls():
    with open(os.getcwd()+"\\diff_rule.txt", 'wb') as f:#exl是二进制数据
        for target_value in target:
            f.write(target_value+"\n")


# 数据对比处理函数
def find_rule():
    # 不同的值，受害目标与对比元数据如果数据相同则删除，不同则不处理
    for target_list in target:
        for raw_data_list in raw_data:
            if target_list == raw_data:
                target.remove(target_list)



if __name__ == '__main__':

    print ("python find_data.py").decode('UTF-8')
    print ("target.txt           -> 对比的数据").decode('UTF-8')
    print ("raw_data.txt         -> 原始的数据").decode('UTF-8')
    print ("output diff_rule.txt -> 不同的数据").decode('UTF-8')

    # 判断文件路径是否存在，如果不存在直接退出，否则读取文件内容
    if (not os.path.exists(os.getcwd()+"\\target.txt")) or (not os.path.exists(os.getcwd()+"\\raw_data_Execute_File_Hash.lst")):
        print 'Please confirm correct filepath !'
        sys.exit(0)
    else:
        # target
        with open(os.getcwd()+"\\target.txt", 'r') as source:
            for line in source:
                target.append(line.rstrip('\r\n').rstrip('\n'))

        # raw_data
        with open(os.getcwd()+"\\raw_data.txt", 'r') as source:
            for line in source:
                raw_data.append(line.rstrip('\r\n').rstrip('\n'))
    find_rule()                    # 对比规则
    save_file_xls()                # 保存文件