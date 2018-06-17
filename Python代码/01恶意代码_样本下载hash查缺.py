# /usr/bin/python
# -*- coding:utf-8 -*-

import os,sys,hashlib,argparse

def CalcSha1(filepath):        # 计算sha1
    with open(filepath,'rb') as f:
        sha1obj=hashlib.sha1()
        sha1obj.update(f.read())
        hash=sha1obj.hexdigest()
        return hash
def CalcMd5(filepath):         # 计算MD5
    with open(filepath,'rb') as f:
        sha1obj=hashlib.md5()
        sha1obj.update(f.read())
        hash=sha1obj.hexdigest()
        return hash
def CalcSha256(filepath):       # 计算sha256
    with open(filepath,'rb') as f:
        sha1obj=hashlib.sha256()
        sha1obj.update(f.read())
        hash=sha1obj.hexdigest()
        return hash
def JudgeBetweenList(alist,locallist):#在alist中删除locallist中的元素
    for i in locallist:
        try:
            alist.remove(i)
        except:
            pass


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='input the samples floder fullpath and the hash text file path')
    parser.add_argument('-s','--samplePath', type=str, help="The Samples floder full path")
    parser.add_argument('-t','--hashPath', type=str, help="The hash text file path")
    args=parser.parse_args()
    hashfilepath=args.hashPath
    with open(hashfilepath) as file_objeact:
        a=file_objeact.readlines()#读取文件

    pure_a=[]#过滤空格,统一转化为小写
    for i in a:
        pure_a.append(i.strip().lower())
    pure_a=list(set(pure_a))#集合去重
    sha1_list=[]
    md5_list=[]
    sha256_list=[]
    nrror_list=[]
    for line in pure_a:   # 存储HASH
        if len(line) is 64:
            sha256_list.append(line)
        elif len(line) is 40:
            sha1_list.append(line)
        elif len(line) is 32:
            md5_list.append(line)
        else:
            nrror_list.append(line)
    print "MD5:%d lines\nSH1-hash:%s lines\nSHA-256:%s"%(len(md5_list),len(sha1_list),len(sha256_list))
    print "And %s lines We are not sure."%(len(nrror_list))
    print "Total:%d lines"%(len(md5_list)+len(sha1_list)+len(sha256_list))

    # 计算文件的HASH值对比
    path=args.samplePath
    file_list=os.listdir(path)
    print "We find %d files"%(len(file_list))#寻找所有文件
    local_sha1_list=[];
    local_md5_list=[];
    local_sha256_list=[];
    for i in file_list:#
        local_sha1_list.append(CalcSha1(path+"\\\\"+i))
        local_md5_list.append(CalcMd5(path+"\\\\"+i))
        local_sha256_list.append(CalcSha256(path+"\\\\"+i))
    JudgeBetweenList(sha1_list,local_sha1_list)
    JudgeBetweenList(md5_list,local_md5_list)
    JudgeBetweenList(sha256_list,local_sha256_list)
    print "We find %d hashs not find."%(len(md5_list)+len(sha1_list)+len(sha256_list))
    f=open("rule.txt","w+")
    f.writelines("sha1:\n")
    for i in sha1_list:
        f.writelines(i+"\n")
    f.writelines("sha256:\n")
    for i in sha256_list:
        f.writelines(i+"\n")
    f.writelines("md5:\n")
    for i in md5_list:
        f.writelines(i+"\n")
    f.close()
    print "And input the result to "+os.getcwd()+"\\rule.txt"