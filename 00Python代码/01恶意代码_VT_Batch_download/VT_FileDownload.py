#-*-coding:utf-8-*-
import urllib
import urllib2
import os
import json
import sys
import hashlib
import tablib
import requests



api = '5dcc54ee972ccce340e'

headers = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) '
                         'AppleWebKit/537.36 (KHTML, like Gecko) '
                         'Chrome/56.0.2924.87 Safari/537.36'}
proxies = {'http': 'socks5://127.0.0.1:8081', 'https': 'socks5://127.0.0.1:8081'}



if __name__ == '__main__':

    params = {'apikey': api, 'hash': '44cda81782dc2a346abd7b2285530c5f'}
    response = requests.get('https://www.google.com',proxies=proxies)
    downloaded_file = response.content
    ip_error_log = open("D:\\test", "w+")
    ip_error_log.write(downloaded_file)
    ip_error_log.close()