void let_it_go()
{
    int i,k;
    char your_name[100];
    int n=100;//这是总人数
    int a[]={}//这是输入信息库，里面是所有的学生信息
    printf("请输入要删除的学生名字");
    int ni_hao=0;
    gets(your_name);
    for(i=0;i<n;i++){
        if(strcmp(your_name,a[].xm)==0)
            break;
    }
    if(i>=n){
        printf("请你检查学生名字是否输入正确并重新输入");
    }
    else{
        for(k=i;k<n-1;k++){
            a[k]=a[k+1];
            ni_hao=1;
        }
        n--;
    }
    if(ni_hao==1){
        printf("删除成功，欢迎再次光临学生信息管理系统！")；
    }
}

/*————————我是可爱的分割线————————*/

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float score;
} Student;

// 函数声明
void saveStudentsToFile(Student students[], int count, const char *filename);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    char choice;

    // 循环输入学生信息
    do {
        if (studentCount >= MAX_STUDENTS) {
            printf("你输入的太多了（扶眼镜）\n");
            break;
        }

        printf("请输入学生ID: ");
        scanf("%d", &students[studentCount].id);
        printf("请输入学生姓名: ");
        scanf("%s", students[studentCount].name);
        printf("请输入学生分数: ");
        scanf("%f", &students[studentCount].score);
        studentCount++;

        printf("是否继续添加学生信息? (y/n): ");
        getchar(); // 清除缓冲区
        choice = getchar();

        //注意，以上部分要根据前文所输入的内容进行更改，我这里只虚拟列举出了可能的内容


    } while (choice == 'y' || choice == 'Y');

    // 将学生信息保存到文件
    saveStudentsToFile(students, studentCount, "students.txt");

    printf("学生信息已保存到文件中。\n");
    return 0;
}

// 将学生信息保存到文件的函数
void saveStudentsToFile(Student students[], int count, const char *filename) {
    FILE *file = fopen(filename, "w");     //如果有多次循环外的输入可以改为“a”
    if (file == NULL) {
        perror("无法打开文件");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].id, students[i].name, students[i].score);
    }

    fclose(file);
}
