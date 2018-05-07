#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import sys
import xlrd
import tablib
from datetime import date, datetime


#  authour:zzzhhh
#  2018-05-07
#  根据txt文本里的IP数据，从excel提取出满足条件的IP，导出整行数据。
#  外出应急响应的时候，找到受害主机，对比资产表找到负责人提供帮助。
#  ip.txt       # 为应急响应提取IP
#  ip.xls       # 资产表
#  out_file.xls # 输出文件


if sys.getdefaultencoding() != 'utf-8':
    reload(sys)
    sys.setdefaultencoding('utf-8')

# 读取文件内容
# 对比内容
txt_ip_list = []                          # txt_ip列表
excel_ip_list= []                         # excel_ip列表
find_ip_list = []                         # 找打的列表
excel_ip_list_count_num = []              # excel索引值保存

#读取文件函数
def read_file(file_path):
    # 判断文件路径是否存在，如果不存在直接退出，否则读取文件内容
    if not os.path.exists(file_path):
        print 'Please confirm correct filepath !'
        sys.exit(0)
    else:
        with open(file_path, 'r') as source:
            for line in source:
                txt_ip_list.append(line.rstrip('\r\n').rstrip('\n'))


#读取EXCEL
def read_excel(file_path):
    # 文件位置
    ExcelFile = xlrd.open_workbook(file_path)
    #根据sheet索引获取sheet内容
    sheet=ExcelFile.sheet_by_index(0)
    # 打印sheet的名称，行数，列数
    print ("表名:").decode('UTF-8'),sheet.name, ("列数:").decode('UTF-8'),sheet.nrows,("行数:").decode('UTF-8'),sheet.ncols

    # 把EXCEL数据存储到列表里
    for j in range(sheet.nrows):
        excel_ip_list.append(sheet.cell(j, 0).value.encode('utf-8'))


# IP数据对比处理函数
def find_rule():
    excel_ip_list_count = 1
    for i in txt_ip_list:
        for j in excel_ip_list:
            if (i == j):
                 print i
                 find_ip_list.append(i)
                 excel_ip_list_count_num.append(excel_ip_list_count)             # 保存当前的索引值


# IP数据对比处理函数
def save_file_xls():
    # 循环遍历原来的excel，确定所在行数
    # 文件位置
    ExcelFile = xlrd.open_workbook(os.getcwd()+"\\ip.xls")
    #根据sheet索引获取sheet内容
    sheet=ExcelFile.sheet_by_index(0)
    # 打印sheet的名称，行数，列数
    print ("表名:").decode('UTF-8'),sheet.name, ("行数:").decode('UTF-8'),sheet.nrows,("列数:").decode('UTF-8'),sheet.ncols

    dataset2 = tablib.Dataset()       # 初始化

    # 把EXCEL数据存储到列表里
    for i in range(sheet.nrows):
        for j in find_ip_list:
            if sheet.cell(i, 0).value == j:
                print  i,sheet.row_values(i)              # 数据
                dataset2.append((sheet.row_values(i)))

    dataset2.title = '字符串全值'
    #写入Excel文件
    with open(os.getcwd()+"\\out_file.xls", 'wb') as f:#exl是二进制数据
        f.write(dataset2.xls)




if __name__ == '__main__':
    #file_str=raw_input('Input file IP.txt filepath eg:D:\\\\test.txt \n')
    print "python find_data.py"
    print "output ip.xls_out.xls"
    print ("同目录的下ip.txt/ip.xls是对比的文件").decode('UTF-8')

    read_file(os.getcwd()+"\\ip.txt")         # 对比的txt
    read_excel(os.getcwd()+"\\ip.xls")        # 对比的excel
    find_rule()                    # 对比规则
    save_file_xls()                # 保存文件

