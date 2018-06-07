#/usr/bin/python
#-*- coding:utf-8 -*-

import os,re,sys


target = []
emails = []
repeat = []

# 读文件
def read_file():
    # 判断文件路径是否存在，如果不存在直接退出，否则读取文件内容
    if (not os.path.exists(os.getcwd()+"\\file_context.txt")):
        print 'Please confirm correct filepath ，file_contenxt.txt!'
        sys.exit(0)
    else:
        # target
        with open(os.getcwd()+"\\file_context.txt", 'r') as source:
            for line in source:
                target.append(line.rstrip('\r\n').rstrip('\n'))

# 去重复函数
def check(one_list):
    '''''
    使用排序的方法
    '''
    result_list = []
    temp_list = sorted(one_list)
    i = 0
    while i < len(temp_list):
        if temp_list[i] not in result_list:
            result_list.append(temp_list[i])
        else:
            i += 1
    return result_list


if __name__ == '__main__':
    read_file()
    # regex = r"([a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+)"
    # 这个正则表达式过滤掉了qq邮箱
    regex = r"([a-zA-Z0-9_.+-]+@[a-pr-zA-PRZ0-9-]+\.[a-zA-Z0-9-.]+)"

    for target_value in target:
        # print(html)
        raw_data = re.findall(regex, target_value)
        for raw_data_value in raw_data:
            repeat.append(raw_data_value)

    # 去重复
    emails = check(repeat)
    #输出邮件
    i = 0
    with open(os.getcwd() + "\\output.txt", 'wb') as f:  # exl是二进制数据
        for email in emails:
            i += 1
            print("{} :{}".format(i, email))
            f.write(email + "\n")
        #print("{}".format(email))