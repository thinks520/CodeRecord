#-*-coding:utf-8-*-
import yara
import os
import os.path 
rootdir = "E:\\Vir"    # ����Ŀ¼
YaraRule_dir = "E:\\yara-rule.txt"  



def mycallback(data):
    if data['strings']:
        print(data['rule']) #��� ƥ�䵽������
        yara.CALLBACK_CONTINUE



for parent,dirnames,filenames in os.walk(rootdir):    #�����������ֱ𷵻�1.��Ŀ¼ 2.�����ļ������֣�����·���� 3.�����ļ�����
    for filename in filenames:                        #����ļ���Ϣ
        print(filename)
        rules = yara.compile(YaraRule_dir)            # yara������� 
        matches = rules.match(os.path.join(parent,filename), callback=mycallback)
#       print("the full name of the file is:" + os.path.join(parent,filename)) #����ļ�·����Ϣ