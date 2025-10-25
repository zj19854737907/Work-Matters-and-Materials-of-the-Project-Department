import os

def init_book_file(filename="books.txt"):
    """初始化图书信息文件，若文件不存在则创建"""
    try:
        if not os.path.exists(filename):
            with open(filename, 'w', encoding='utf-8') as f:
                # 写入表头（可选）
                f.write("编号,书名,作者,出版社,价格,状态(0可借/1已借)\n")
            print(f"文件 {filename} 初始化成功")
        else:
            print(f"文件 {filename} 已存在，无需初始化")
    except Exception as e:
        print(f"初始化文件失败：{e}")

def read_books(filename="books.txt"):
    """读取图书信息文件，返回图书列表"""
    books = []
    try:
        with open(filename, 'r', encoding='utf-8') as f:
            lines = f.readlines()
            # 跳过表头
            for line in lines[1:]:
                line = line.strip()
                if line:
                    parts = line.split(',')
                    # 转换数据类型
                    book = {
                        "id": parts[0],
                        "name": parts[1],
                        "author": parts[2],
                        "publisher": parts[3],
                        "price": float(parts[4]),
                        "status": int(parts[5])
                    }
                    books.append(book)
        print(f"成功读取 {len(books)} 条图书信息")
        return books
    except FileNotFoundError:
        print(f"文件 {filename} 不存在，请先初始化")
        return []
    except Exception as e:
        print(f"读取文件失败：{e}")
        return []