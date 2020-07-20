#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>
#include<grp.h>
#include<pwd.h>

void file_mode(struct stat* buf);
void print_guid(int uid, int gid);
void file_operation(int *argv);

int main(int argc, char **argv)
{
	int argNum = argc;
	int params[4] = { 0,0,0,0 };
	int count = 0;
	while (argNum != 0 && count < argc) {
		if (strcmp(argv[count], "-d") == 0)
			params[0] = 1;
		else if (strcmp(argv[count], "-R") == 0)
			params[1] = 1;
		else if (strcmp(argv[count], "-a") == 0)
			params[2] = 1;
		else if (strcmp(argv[count], "-i") == 0)
			params[3] = 1;
		argNum--;
		count++;
	}
	file_operation(params);
	return 0;
}
void file_mode(struct stat *buf) {
	int i;
	char buff[10] = { "----------" };
	switch (buf->st_mode & S_IFMT)//按位&获取文件基本属性
	{
	case S_IFIFO:
		buff[0] = 'f';
		break;
	case S_IFDIR:
		buff[0] = 'd';
		break;
	case S_IFSOCK:
		buff[0] = 's';
		break;
	case S_IFBLK:
		buff[0] = 'b';
		break;
	case S_IFLNK:
		buff[0] = 'l';
		break;
	default:break;
	}

	if (buf->st_mode & S_IRUSR)
	{
		buff[1] = 'r';
	}
	if (buf->st_mode & S_IWUSR)
	{
		buff[2] = 'w';
	}
	if (buf->st_mode & S_IXUSR)
	{
		buff[3] = 'x';
	}
	if (buf->st_mode & S_IRGRP)
	{
		buff[4] = 'r';
	}
	if (buf->st_mode & S_IWGRP)
	{
		buff[5] = 'w';
	}
	if (buf->st_mode & S_IXGRP)
	{
		buff[6] = 'x';
	}
	if (buf->st_mode & S_IROTH)
	{
		buff[7] = 'r';
	}
	if (buf->st_mode & S_IWOTH)
	{
		buff[8] = 'w';
	}
	if (buf->st_mode & S_IXOTH)
	{
		buff[9] = 'x';
	}

	for (i = 0; i < 10; i++)
	{
		printf("%c", buff[i]); //打印类型和权限
	}
}
void recursion(const int *argv, char *dirName) {
	DIR *fd; // 定义文件夹类型
	struct dirent *fp;// 文件夹返回值
	struct stat buf;

	char temp[100]; // 中间变量存放文件路径

	char dirs[100][100]; // 存放子目录用于R指令

	int count = 0; // 子目录计数

	if ((fd = opendir(dirName)) == NULL)//打开文件夹
	{
		perror("open file failed");
		exit(0);
	}

	// -R指令输出文件夹名
	if (argv[1] == 1) {
		printf("%s:\n", dirName);
	}

	while ((fp = readdir(fd)) != NULL) // 循环读取文件夹中的文件信息
	{
		strcpy(temp, dirName);
		strcat(temp, fp->d_name); // 把文件名字添加到路径后面形成完整的路径

		if (stat(temp, &buf) == -1) //获取文件基本属性
		{
			perror("get stat failed");
			exit(0);
		}

		// -R指令：记录子文件夹（不包括.和..）
		char buff = ' ';
		switch ((&buf)->st_mode & S_IFMT) {
		case S_IFDIR:
			buff = 'd';
		}
		if (buff == 'd') {
			if (strcmp(fp->d_name, ".") != 0 && strcmp(fp->d_name, "..") != 0) {
				// -a
				if (argv[2] == 1) {
					// 生成完整的目录名
					char complete_d_name[200];
					strcpy(complete_d_name, dirName);
					strcat(complete_d_name, fp->d_name);
					strcat(complete_d_name, "/");
					strcpy(dirs[count], complete_d_name);
					count++;
				}
				else {
					if (strncmp(fp->d_name, ".", 1) != 0) {
						char complete_d_name[200];
						strcpy(complete_d_name, dirName);
						strcat(complete_d_name, fp->d_name);
						strcat(complete_d_name, "/");
						strcpy(dirs[count], complete_d_name);
						count++;
					}
				}
			}
		}

		// -a则处理隐藏文件
		if (argv[2] == 1) {
			// -i则在前面显示ino
			if (argv[3] == 1) {
				printf("%llu ", (long long int) buf.st_ino);
			}
			file_mode(&buf);//文件属性（目录，链接……，可读，可写，可执行）
			printf("  %d", (int)buf.st_nlink); //打印链接数
			print_guid(buf.st_uid, buf.st_gid); //调用函数打印出文件拥有者和文件所有者组
			printf("\t%ld", buf.st_size); //打印文件大小
			printf("\t%.12s ", 4 + ctime(&buf.st_mtime)); // 打印修改时间
			printf("   %s\n", fp->d_name); //打印文件名
		}
		// 否则略过隐藏文件
		else {
			if (strncmp(fp->d_name, ".", 1) == 0) {
				continue;
			}
			else {
				// -i
				if (argv[3] == 1) {
					printf("%llu ", (long long int) buf.st_ino);
				}
				file_mode(&buf);
				printf("  %d", (int)buf.st_nlink);
				print_guid(buf.st_uid, buf.st_gid);
				printf("\t%ld", buf.st_size);
				printf("\t%.12s ", 4 + ctime(&buf.st_mtime));
				printf("   %s\n", fp->d_name);
			}
		}
	}
	// -R指令会遍历子文件夹
	if (argv[1] == 1) {
		printf("\n");
		for (int i = 0; i < count; i++) {
			recursion(argv, dirs[i]);
		}
	}
}

void file_operation(int *argv) {
	struct stat buf;

	char temp[100];

	// ls -d则只显示当前文件夹
	if (argv[0] == 1) {
		strcpy(temp, "./");
		if (stat(temp, &buf) == -1)
		{
			exit(0);
		}
		// ls -i显示ino
		if (argv[3] == 1) {
			printf("%llu ", (long long int) buf.st_ino);
		}
		file_mode(&buf);
		printf("  %d", (int)buf.st_nlink);
		print_guid(buf.st_uid, buf.st_gid);
		printf("\t%ld", buf.st_size);
		printf("\t%.12s ", 4 + ctime(&buf.st_mtime));
		printf("   %s\n", ".");
	}
	// ls 非-d处理
	else {
		recursion(argv, "./");
	}
}
void print_guid(int uid, int gid)
{
	struct passwd *ptr;
	struct group *str;
	ptr = getpwuid((__uid_t)uid);
	str = getgrgid((__uid_t)gid);
	printf("\t%s\t%s", ptr->pw_name, str->gr_name);
}
