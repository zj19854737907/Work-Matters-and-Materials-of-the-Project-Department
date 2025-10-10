import json
import os
#获取路径
current_directory = os.path.dirname(os.path.abspath(__file__))
file_directory = os.path.join(current_directory, 'pet_info')


def save_data(pet_info):
    name = pet_info['name']
    file_path = os.path.join(file_directory, f"{name}.json")

    # 检查是否已存在相同名字的宠物
    existing_pet = None
    for pet in get_all_data():
        if pet['name'] == name:
            existing_pet = pet
            break

    # 如果已存在，更新宠物数据
    if existing_pet:
        existing_pet.update(pet_info)
        with open(file_path, 'w', encoding='utf-8') as f:
            json.dump(existing_pet, f, ensure_ascii=False)
        print(f"Pet {name} updated successfully.")
    else:
        # 使用 'a' 模式以加入 JSON 数组
        with open(file_path, 'a', encoding='utf-8') as f:
            # 在每个 JSON 对象之间加上逗号和换行
            if os.path.getsize(file_path) > 0:
                f.write(",\n")
            json.dump(pet_info, f, ensure_ascii=False)

def get_all_data():
    pet_list = []

    for file_name in os.listdir(file_directory):
        if file_name.endswith(".json"):
            file_path = os.path.join(file_directory, file_name)
            try:
                with open(file_path, 'r', encoding='utf-8') as file:
                    data = json.load(file)
                    pet_list.append(data)
            except FileNotFoundError:
                # 处理文件不存在的情况
                print("文件不存在")

    return pet_list

