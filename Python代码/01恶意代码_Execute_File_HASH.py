#/usr/bin/python
#-*- coding:utf-8 -*-

# 计算文件hash值

import hashlib
import os, sys

def CalcSha1(filepath):
    with open(filepath,'rb') as f:
        sha1obj = hashlib.sha1()
        sha1obj.update(f.read())
        hash = sha1obj.hexdigest()
        print(hash)
        return hash

def CalcMD5(filepath):
    with open(filepath,'rb') as f:
        md5obj = hashlib.md5()
        md5obj.update(f.read())
        hash = md5obj.hexdigest()
        print(hash)
        return hash

if __name__ == "__main__":
        hashfile = os.getcwd()+"\\target_Execute_File_Hash.lst"
        CalcMD5(hashfile)
        CalcSha1(hashfile)
