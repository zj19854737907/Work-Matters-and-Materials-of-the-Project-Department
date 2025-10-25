def analyze_books(books):
    """统计图书信息并生成报告"""
    if not books:
        print("ℹ️ 没有可分析的图书数据")
        return
    
    # 1. 统计总数量
    total = len(books)
    
    # 2. 统计可借（status=0）和已借出（status=1）数量
    available = 0
    borrowed = 0
    for book in books:
        if book["status"] == 0:
            available += 1
        elif book["status"] == 1:
            borrowed += 1
    
    # 3. 计算平均价格
    total_price = sum(book["price"] for book in books)
    avg_price = total_price / total
    
    # 生成报告
    print("\n📊 图书信息统计报告 📊")
    print("-" * 40)
    print(f"• 图书总数量：{total} 本")
    print(f"• 可借图书数量：{available} 本（占比 {available/total*100:.1f}%）")
    print(f"• 已借出图书数量：{borrowed} 本（占比 {borrowed/total*100:.1f}%）")
    print(f"• 图书平均价格：{avg_price:.2f} 元")
    print("-" * 40)

# 测试代码
if __name__ == "__main__":
    # 初始化文件
    init_book_file()
    # 读取图书数据（若文件为空，可手动添加测试数据后再运行）
    books = read_books()
    # 统计分析
    analyze_books(books)