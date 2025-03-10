import requests
query=input("输入你想要搜索的内容：")
url=f'https://www.sogou.com/web?query={query}'
dic={
    "user-agent":
"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
}
resp=requests.get(url,headers=dic)
##print(resp)
##print(resp.text)
resp.close()