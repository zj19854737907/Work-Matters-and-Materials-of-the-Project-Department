import requests  # 导入requests模块，用于发送网络请求

# 全局变量
API_URL = "https://v0.yiketianqi.com/free/day"  # 新的天气API网址
API_APPID = "89594975"  # 你的用户appid
API_SECRET = "2oWBHTtn"  # 你的用户appsecret


# 如何使用查看这个：http://www.tianqiapi.com/index/doc?version=day
def magic_weather_hat(city):
    """
    这是一个魔法咒语（函数），当你告诉它一个城市的名字时，它会用神秘的网络通道从远方获取那个城市的天气信息。
    参数：city - 你想知道天气的城市名称
    结果：打印出那个城市的详细天气情况
    """
    # 构造请求URL
    request_url = f"{API_URL}?appid={API_APPID}&appsecret={API_SECRET}&city={city}&unescape=1"

    # 通过网络通道获取天气数据
    response = requests.get(request_url)
    weather_data = response.json()  # 解析返回的JSON数据

    # 通过lambda创建建议函数实现摄氏度转华氏度
    celsius_to_fahrenheit = lambda celsius: celsius * 9 / 5 + 32

    # 从天气数据中提取信息
    weather_condition = weather_data['wea']  # 天气情况
    temperature_current = weather_data['tem']  # 实况温度
    temperature_fahrenheit = celsius_to_fahrenheit(temperature_current)

    # 输出天气信息
    print(
        f"在{city}的天气是{weather_condition}，当前温度为{temperature_current}摄氏度，{temperature_fahrenheit}华氏度")


# 这是主程序的入口
if __name__ == "__main__":
    print("欢迎使用魔法天气帽！")
    city = input("请输入一个城市名称，我会告诉你那里的天气：")  # 魔法帽子在询问你想了解的城市
    magic_weather_hat(city)  # 使用魔法咒语查询天气
