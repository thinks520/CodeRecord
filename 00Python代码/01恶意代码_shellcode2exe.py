#! /usr/bin/env python
# -*- coding: utf-8 -*-


### 说明
#  代码可以将二进制转换成十六进制文本保存起来
#  binary to hex


# 计算messagebox大小
c = open('messagebox.txt','r')
r = c.read()
print len(r)

# 将cmd.exe中的opcode再转换为hex数据
s = open('messagebox.txt','rb')
b = s.read()
bb = b[-len(r):]
cb = bb.decode("hex")
f = open('mess.exe','wb')
f.write(cb)


