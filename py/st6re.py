import re
import requests
import csv
##csv数据均以逗号分隔
url="https://movie.douban.com/chart"
dic={
   "user-agent":
"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
}
resp=requests.get(url,headers=dic)
page_content=resp.text
obj=re.compile(
    r'<a class=".*?" href=".*?"  title="(?P<name>.*?)">.*? <p class="pl">'
    r'(?P<year>.*?)/.*?<span class="rating_nums">(?P<rate>.*?)</span>.*?'
    ##括号具有特殊含义，因此在匹配括号时应用转义符
    r'<span class="pl">\((?P<judge>.*?)\)</span>'
    ,re.S)
res=obj.finditer(page_content)
f=open("moviedata.csv",mode="w",encoding="utf-8")
csvwriter=csv.writer(f)
for i in res:
    dic=i.groupdict()
    csvwriter.writerow(dic.values())
print("over!")
    # print(i.group("name"))
    # print(i.group("year"))
    # print(i.group("rate"))
    # print(i.group("judge"))

