#/usr/bin/python
#-*- coding:utf-8 -*-
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.common.exceptions import NoSuchElementException, TimeoutException
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

import os
import re
import time

# 测试环境
# python依赖库 ：selenium
# 操作系统：widows 10 x64
# chrome： 67.0.3396.87（正式版本） （64 位）
# chromedriver：2.38.506120 http://npm.taobao.org/mirrors/chromedriver/2.38/
# 放置在 "C:/Program Files (x86)/Google/Chrome/Application/chromedriver


class vt_download(object):
    username = ""
    password = ""
    user = "zzzhhh"     # 这里用来判断是否登录成功

    # 初始化
    def __init__(self, md5file, vir_dir=None):
        # 设置代理
        chromeOptions = webdriver.ChromeOptions()
        # chromeOptions.add_argument('--headless')  这行控制是否要有界面
        chromeOptions.add_argument('--proxy-server=http://127.0.0.1:8081')
        self.browser = webdriver.Chrome(chrome_options=chromeOptions)
        self.md5file = md5file
        self.result = []
        self.nextp = True
        self.vir_dir = vir_dir

    def login(self):
        loginUrl = "https://www.virustotal.com/#/home/upload"
        self.browser.get(loginUrl)
        time.sleep(5) # 等五秒钟网页下载完成
        print "Virustotal open finish."
        elem_login =  self.browser.find_element_by_id("signinButton") # 找到网页登录按钮
        elem_login.click()
        # 账户赋值
        name_xpath = "//*[@id=\"email\"]"
        name = self.browser.find_element_by_xpath(name_xpath)
        name.send_keys(self.username)
        time.sleep(2)
        # 密码赋值
        passwd_xpath = "//*[@id=\"password\"]"
        passwd = self.browser.find_element_by_xpath(passwd_xpath)
        passwd.send_keys(self.password)
        time.sleep(2)
        passwd.send_keys(Keys.RETURN)
        print "Login Success."
    def search(self):
        time.sleep(8)
        # 打开小图标
        elem_icon = self.browser.find_element_by_id("appsButton")
        elem_icon.click()
        # 打开intelligence
        elem_intelligence = self.browser.find_element_by_id("intelligence")
        elem_intelligence.click()
        # 打开Search_for_hashes
        elem_Search_for_hashes = self.browser.find_element_by_xpath("//*[@id=\"search-tabs\"]/li[3]/a")
        elem_Search_for_hashes.click()
        # 填写HASH值
        elem_HASH = self.browser.find_element_by_xpath("// *[ @ id = \"textarea\"]")
        urllist = open(self.md5file, 'r')  # 这是要添加的url列表
        formaturl = urllist.readlines()
        print "Load HASH Values."
        hash = []
        for hash_value in formaturl:
            hash.append(hash_value)
        elem_HASH.send_keys(hash)
        # 搜索
        
		
		# more result click
        
		
		# download 处理
		
		
		
        print "hashhash"
		
		
    def download(self):
        pass


    def main(self):
        # 获得cookie信息
        cookie1 = self.browser.get_cookies()
        print cookie1
        self.login()     # 登录操作
        self.search()    # 下载操作


if __name__ == '__main__':
    md5file = "md5.txt"                      #  读取的MD5值
    download_dir = "C:\\vir_dir\\"           #  保存的目录
    vt_download(md5file, download_dir).main()