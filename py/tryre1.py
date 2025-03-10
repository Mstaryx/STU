import requests
import csv

url = "https://movie.douban.com/j/chart/top_list"
header = {
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36 Edg/131.0.0.0"
}

# 打开文件以写入
f = open("horromovie.txt", mode="w", encoding="utf-8", newline="")
# 写入表头
f.write(f"{'Rank':<5} {'Title':<25} {'Rating':<20} {'Types':<20} {'Regions':<15} {'Release Date':<15}\n")
f.write("=" * 120 + "\n")

bg = -20
for i in range(1, 2):
    bg += 20
    para = {
        "type": "20",
        "interval_id": "100:90",
        "action": "",
        "start": f"{bg}",
        "limit": "20"
    }
    resp = requests.get(url, params=para, headers=header)
    data = resp.json()  # 获取 JSON 数据

    for movie in data:
        # 提取所需字段
        rating = ','.join(movie.get("rating", []))  # 提取评分值
        rank = movie.get("rank", "N/A")
        types = ', '.join(movie.get("types", []))  # 将列表转换为逗号分隔的字符串
        regions = ', '.join(movie.get("regions", []))  # 同上
        title = movie.get("title", "N/A")
        release_date = movie.get("release_date", "N/A")

        # 截取字段，确保不超过规定的宽度
        title = title[:25]  # 截取title字段，避免超过25个字符
        types = types[:20]  # 截取types字段，避免超过20个字符
        regions = regions[:15]  # 截取regions字段，避免超过15个字符
        rating = rating[:20]  # 截取rating字段，避免超过20个字符
        release_date = release_date[:15]  # 截取release_date字段，避免超过15个字符

        # 格式化输出并写入文件
        f.write(f"{rank:<5} {title:<25} {rating:<20} {types:<20} {regions:<15} {release_date:<15}\n")

print("over!")
resp.close()
f.close()
