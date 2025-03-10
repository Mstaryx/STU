import requests
url="https://fanyi.baidu.com/sug"
s=input("输入想翻译的单词：")
dat={
    "kw":s
}
resp=requests.post(url,data=dat)
print(resp.json())
resp.close()