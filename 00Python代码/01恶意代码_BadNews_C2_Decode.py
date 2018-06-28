#!/usr/bin/env python
# -*- coding: utf-8 -*-
import requests
import base64
import binascii
import re
from Crypto.Cipher import Blowfish
from struct import pack
 
 
rol = lambda val, r_bits, max_bits: (val << r_bits%max_bits) & (2**max_bits-1) | ((val & (2**max_bits-1)) >> (max_bits-(r_bits%max_bits)))
 
ror = lambda val, r_bits, max_bits: ((val & (2**max_bits-1)) >> r_bits%max_bits) | (val << (max_bits-(r_bits%max_bits)) & (2**max_bits-1))
 
 
def unhexData(d):                       # 十六进制解密
  if len(d) % 2:
    d = d.zfill(len(d)+1)
  return ord(binascii.unhexlify(d))     # 十六进制解密，然后将单个字符以ascii码的方式返回
 
 
def decodeDecrypt(data):                # 传参 c945adaa8a656b8fc9c9a5aec56fe58a248ac96c650b848423
  decdata = ''
  for x in range(len(data)):
    x = x*2
    if x < len(data):
      c = unhexData(data[x])            # 十六进制转ASCII码
      add_num = unhexData(data[x+1])
      c = c << 4                        # 左移动4位
      c = (c + add_num) & 0xff
      c ^= 0x23                         # 异或0x23
      c = rol(c, 3, 8)                  # 运算
      decdata += chr(c)                 # 恢复为Base64编码
  data2 = base64.b64decode(decdata)
  key = binascii.unhexlify("F0E1D2C3B4A5968778695A4B3C2D1E0F0011223344556677")
  cipher = Blowfish.new(key, Blowfish.MODE_ECB)     # Blowfish算法解密
  dec = cipher.decrypt(data2)                       # 解密后的C2地址
  return dec
 

# 加密C2的Url列表
urls = [
  "http://feeds.rapidfeeds.com/88604"
]
 
for d in urls:
    r = requests.get(d)
    body = r.text
    r = re.search("\[+\s*([a-zA-Z0-9\=]+)\]+", body)      # 取值得到 [[[Yzk0NWFkYWE4YTY1NmI4ZmM5YzlhNWFlYzU2ZmU1OGEyNDhhYzk2YzY1MGI4NDg0MjM=]]]]
    if r:
        data = base64.b64decode(r.group(0))                  # Base64解密得到c945adaa8a656b8fc9c9a5aec56fe58a248ac96c650b848423
        print("[{}] Decrypted C2: {}".format(d, decodeDecrypt(data).split("\x00")[0]))   # 输出解密后的IP地址