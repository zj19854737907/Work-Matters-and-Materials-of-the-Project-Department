from random import choice


class Book:
    def __init__(self, title, author, isbn):
        self.title = title
        self.author = author
        self.isbn = isbn
        self.is_borrowed = False

class Library:
    def __init__(self):

        self.books = [
            Book("魔女之旅", "白石定规", "1999"),
            Book("无职转生","是不讲理不求人","2014"),
            Book("一拳超人","ONE","001"),
            Book("电锯人","藤本树","2018")
        ]
    def list_books(self):
        print("\n图书列表:")
        print("-"*60)
        for i, book in enumerate(self.books,1):
            status = "已借出" if book.is_borrowed else "可借"
            print(f"{i}. 《{book.title}》- {book.author} - ISBN:{book.isbn} - {status}")
            print("-"*60)
    def borrow_book(self):
        self.list_books()

        try:
            choice = int(input("请输入要借阅的图书编号"))
            if choice < 1 or choice > len(self.books):
                print("无效的图书编号!")
                return
            book = self.books[choice-1]

            if book.is_borrowed:
                print(f"《{book.title}》已被借出")
            else:
                book.is_borrowed = True
                print(f"成功借阅《{book.title}》!")

        except ValueError:
            print("请输入有效数字！")

    def return_book(self):
        borrowed_books = [book for book in self.books if book.is_borrowed]

        if not borrowed_books:
            print("当前没有已借阅图书！")
            return

        print("\n 已借出图书:")
        print("-"*60)
        for i, book in enumerate(borrowed_books,1):
            print(f"{i}. 《{book.title}》-{book.author} - ISBN:{book.isbn} ")
            print("-"*60)
            try:
                choice = int(input("请输入要归还的图书编号:"))

                if choice < 1 or choice > len(borrowed_books):
                    print("无效的图书编号!")
                    return

                book = borrowed_books[choice-1]
                book.is_borrowed = False
                print(f"成功归还《{book.title}》!")

            except ValueError:
                print("请输入有效数字!")

    def get_total_books(self):
        return len(self.books)

    def get_available_books(self):
        count = 0
        for book in self.books:
            if not book.is_borrowed:
                count += 1
        return count

    def get_borrowed_books(self):
        count = 0
        for book in self.books:
            if book.is_borrowed:
                count += 1
        return count

    def generate_report(self):
        print("\n" + "="*50)
        print("图书统计报告")
        print("="*50)
        print(f"图书总数量: {self.get_total_books()}本")
        print(f"可借图书数量:{self.get_available_books()}本")
        print(f"已借出图书数量:{self.get_borrowed_books()}本")
        print("="*50)

        print("\n图书详情:")
        for book in self.books:
            status = "已借出" if book.is_borrowed else"在馆"
            print(f"《{book.title}》- {status}")


def main():
    library = Library()

    print("=" * 50)
    print("图书管理系统(4本具体图书)")
    print("=" * 50)

    while True:
        print("\n" + "-" * 40)
        print("1.查看图书列表")
        print("2.借阅图书")
        print("3.归还图书")
        print("4.查看统计报告")
        print("5.退出系统")
        print("-" * 40)

        choice = input("请选择操作(1-5): ")

        if choice == "1":
            library.list_books()
        elif choice == "2":
            library.borrow_book()
        elif choice == "3":
            library.return_book()
        elif choice == "4":
            library.generate_report()
        elif choice == "5":
            print("感谢使用图书管理系统")
            break
        else:
            print("无效选择,请重新输入!")


if __name__ == "__main__":
    main()

