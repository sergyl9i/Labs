#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main() {
	struct stat STATUS;
	int start,create_file,rewers_read,count,dlen,info,read_pos;
	start = open("hel.txt",O_RDWR);
	create_file = open("nexfile.txt", O_RDWR);
	printf("FD для hel.txt = %d\n", start);
	printf("FD для nexfile.txt = %d\n", create_file);
	info = stat("hel.txt",&STATUS);
	printf("Получение статистики по файлу hel.txt = %d\n",info);
	printf("Получение длинны файла hel.txt = %ld\n",STATUS.st_size);
	char S[STATUS.st_size], G[STATUS.st_size], D[STATUS.st_size];
	S[STATUS.st_size]='\0';
	G[STATUS.st_size]='\0';
	D[STATUS.st_size]='\0';
	count = STATUS.st_size;
	dlen = read(start, S, count);
	printf("Количество считанных из файла hel.txt = %d\n",dlen);
	printf("Полученный буфер из hel.txt : %s\n",S);
	close(start);
	dlen = write(create_file,S,count);
	printf("Количество считанных из буфера символов в nexfile.txt = %d\n",dlen);
	close(create_file);
	rewers_read = open("nexfile.txt", O_RDWR);
	printf("FD для второго запуска nexfile.txt = %d\n", create_file);
	info = stat("hel.txt",&STATUS);
	printf("Получение длинны файла hel.txt = %ld\n",STATUS.st_size);
	count = STATUS.st_size;
	for (count;count>=0;count--){
		read_pos = lseek(rewers_read,count,0);
		read(rewers_read, D, 1);
		printf("%s",D);
	}
	printf("\n");
	close(create_file);
	return 0;
}