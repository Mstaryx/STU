import os
import requests

endpoint = "https://whut.ai-augmented.com/api/jx-iresource/"

token = input("请输入 token: ") or os.environ.get("DEV_TOKEN")  # 获取token
headers = {
    "Authorization": f"Bearer {token}",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
}

group_id = input("请输入 group_id: ")  # 课程的总ID，在链接的mycourse后面
url = f"{endpoint}resource/queryCourseResources?group_id={group_id}"  # 获取课程资源
course_jobs = requests.get(url=url, headers=headers).json()["data"]

end_time=input("请输入end_time(直接回车不限): ")#可选指定截止日期
red_font = "\033[31m"
green_font = "\033[32m"
orange_font = "\033[33m"
reset_font = "\033[0m"
mypath=''
for job in course_jobs:  # 遍历课程任务
    node_id = job["id"]  # 任务ID，在链接的最尾部
    job_type = job["type"]  # 任务类型
    job_path=job["path"]

    if "task_id" not in job:
        print(f"{orange_font}{node_id}{reset_font}: Not a task, skipped.")
        continue
    job_end_time = job["end_time"]
    if mypath=='' or mypath not in job_path:
        print(job["name"],':',job_path)
        mypath = input("输入课程path第二段（可选,输入#退出）：")
    if mypath=='#':
        exit(0)
    if end_time!='':
        if end_time not in job_end_time:
            continue
    if mypath!='':
        if mypath not in job_path:
            continue
    if job_type == 9:  # 9=视频
        url = f"{endpoint}resource/task/studenFinishInfo?group_id={group_id}&node_id={node_id}"
        assign_id = requests.get(url=url, headers=headers).json()[
            "data"]["assign_id"]

        url = f"{endpoint}resource/queryResource?node_id={node_id}"
        result = requests.get(url=url, headers=headers).json()["data"]
        quote_id = result["quote_id"]
        media_id = result["resource"]["id"]
        duration = result["resource"]["duration"]
        task_id = result["task_id"]

        data = {
            "video_id": "0000000000000000000",  # 似乎不重要
            "played": duration,
            "media_type": 1,
            "duration": duration,
            "watched_duration": duration
        }
        url = f"{endpoint}vod/duration/{quote_id}"  # 提交视频观看时长
        result = requests.post(url=url, headers=headers, json=data)

        url = f"{endpoint}vod/checkTaskStatus"  # 完成视频任务
        data = {
            "group_id": group_id,
            "media_id": media_id,
            "task_id": task_id,
            "assign_id": assign_id
        }

        result = requests.post(url=url, headers=headers, json=data).json()
        print(f"{green_font}{node_id}{reset_font}: {result}")

    elif job_type == 6:  # 6=文档
        task_id = job["task_id"]

        url = f"{endpoint}resource/finishActivity"
        data = {
            "group_id": group_id,
            "task_id": task_id,
            "node_id": node_id
        }
        result = requests.post(url=url, headers=headers, json=data).json()
        print(f"{green_font}{node_id}{reset_font}: {result}")

    else:
        print(
            f"{red_font}{node_id}{reset_font}: job_type={job_type} Not Implemented, skipped.")