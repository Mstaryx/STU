import requests

url="https://movie.douban.com/j/chart/top_list"
##url过长，get类型用param
dic={
    "user-agent":
"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
}
star=-20
for i in range(1,2):
    star+=20
    param={
    "type": "24",
    "interval_id": "100:90",
    "action": "",
    "start": f"{star}",
    "limit": "20",
    }
##运行发现空白，查找被反爬原因，首先尝试user-agent
    resp=requests.get(url,params=param,headers=dic)
    print(resp.text)
resp.close()
    