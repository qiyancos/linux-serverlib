#! /usr/bin/env python3
#coding=utf-8

from flask import Flask
import urllib.parse as parse
import urllib.request as request
import json
from bs4 import BeautifulSoup

Request_URL="http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule"
form_data={}
form_data['i']='The name is Jerry!'
form_data['from'] = 'en'
form_data['to'] = 'zh-CN'
form_data['smartresult'] = 'dict'
form_data['doctype']='json'
form_data['version']='2.1'
form_data['keyfrom']='fanyi.web'
form_data['action']='FY_BY_CLICKBUTTION'
form_data['typoResult']='false'

data=parse.urlencode(form_data).encode('utf-8')
response=request.urlopen(Request_URL,data)
html=response.read().decode('utf-8')
translate_results = json.loads(html)
# 找到翻译结果
translate_result = translate_results["translateResult"][0][0]['tgt']
# 打印翻译结果
print("翻译的结果是：%s" % translate_result)
