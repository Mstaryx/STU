import re
import requests
url='https://www.dytt89.com/'
header={
   "user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
}
resp=requests.get(url,headers=header)
resp.encoding='gb2312'
obj1=re.compile(r'.*?2024必看热片.*?<ul>(?P<URL>.*?)</ul>',re.S)
obj2=re.compile(r"<a href=\'(?P<serchlink>.*?)\' title=\"(?P<title>.*?)\">.*?</a>",re.S)
objchid=re.compile(r'<td style="WORD-WRAP: break-word" bgcolor="#fdfddf"><a href="(?P<download>.*?)"',re.S)
chid_herf_list=[]
res1=obj1.finditer(resp.text)
for it in res1:
    ul=it.group("URL")
    res2=obj2.finditer(ul)
    for it1 in res2:
        chid_link=url+it1.group("serchlink").strip("/")
        chid_herf_list.append(chid_link)
for herf in chid_herf_list:
    respchid=requests.get(herf,headers=header)
    respchid.encoding='gb2312'
    reschid=objchid.finditer(respchid.text)
    for it in reschid:
        print(it.group("download"))