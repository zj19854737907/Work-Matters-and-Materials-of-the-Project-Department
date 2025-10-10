import random


# 创建一个魔法咒语函数，用于查询天气
def magic_weather_hat(location):
    # 模拟查询天气，返回随机天气数据
    weather_data = {
        'sunny': '晴天',
        'rainy': '雨天',
        'cloudy': '多云',
        'windy': '有风',
    }

    # 使用Lambda函数将摄氏度转换为华氏度
    celsius_to_fahrenheit = lambda celsius: (celsius * 9 / 5) + 32

    # 随机生成温度
    temperature_celsius = random.randint(-10, 30)
    temperature_fahrenheit = celsius_to_fahrenheit(temperature_celsius)

    # 输出天气信息
    print(
        f"在{location}的天气是{weather_data[random.choice(list(weather_data.keys()))]}，温度为{temperature_celsius}摄氏度 ({temperature_fahrenheit}华氏度)。")


# 主程序
if __name__ == "__main__":
    print("欢迎使用魔法天气帽！")
    location = input("请输入一个地点，我会告诉你那里的天气：")
    magic_weather_hat(location)